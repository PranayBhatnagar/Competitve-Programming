#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

mutex mtx1;
mutex mtx2;

void thread1() {
    cout << "Thread 1: Trying to lock mutex 1...\n";
    lock_guard<mutex> lock1(mtx1);
    this_thread::sleep_for(chrono::milliseconds(100)); // Simulate some work

    cout << "Thread 1: Trying to lock mutex 2...\n";
    lock_guard<mutex> lock2(mtx2);

    cout << "Thread 1: Locked both mutexes.\n";
}

void thread2() {
    cout << "Thread 2: Trying to lock mutex 2...\n";
    lock_guard<mutex> lock1(mtx2);
    this_thread::sleep_for(chrono::milliseconds(100)); // Simulate some work

    cout << "Thread 2: Trying to lock mutex 1...\n";
    lock_guard<mutex> lock2(mtx1);

    cout << "Thread 2: Locked both mutexes.\n";
}

int main() {
    thread t1(thread1);
    thread t2(thread2);

    t1.join();
    t2.join();

    return 0;
}

















