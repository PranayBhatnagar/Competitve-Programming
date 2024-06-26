#include <iostream>
#include <thread>
#include <atomic>

using namespace std;

atomic<bool> resource1(false);
atomic<bool> resource2(false);
atomic<bool> resource3(false);
void thread1() {
    while (true) {
        if (!resource1.exchange(true)) { // Try to lock resource 1
            cout << "Thread 1: Locked resource 1\n";
            this_thread::yield(); // Yield to simulate some work

            if (!resource2.exchange(true)) { // Try to lock resource 2
                cout << "Thread 1: Locked resource 2\n";
                // Simulate work with both resources
                resource2 = false; // Unlock resource 2
                resource1 = false; // Unlock resource 1
                cout << "Thread 1: Released both resources\n";
                break;
            } else {
                cout << "Thread 1: Failed to lock resource 2, releasing resource 1\n";
                resource1 = false; // Unlock resource 1
                this_thread::yield(); // Yield to give the other thread a chance
            }
        }
    }
}

void thread2() {
    while (true) {
        if (!resource2.exchange(true)) { // Try to lock resource 2
            cout << "Thread 2: Locked resource 2\n";
            this_thread::yield(); // Yield to simulate some work

            if (!resource3.exchange(true)) { // Try to lock resource 1
                cout << "Thread 2: Locked resource 3\n";
                // Simulate work with both resources
                resource3 = false; // Unlock resource 1
                resource2 = false; // Unlock resource 2
                cout << "Thread 2: Released both resources\n";
                break;
            } else {
                cout << "Thread 2: Failed to lock resource 3, releasing resource 2\n";
                resource2 = false; // Unlock resource 2
                this_thread::yield(); // Yield to give the other thread a chance
            }
        }
    }
}

int main() {
    thread t1(thread1);
    thread t2(thread2);

    t1.join();
    t2.join();

    return 0;
}
