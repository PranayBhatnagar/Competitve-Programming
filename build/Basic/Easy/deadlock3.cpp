//
// Created by bhatn on 26-06-2024.
//
#include <iostream>

using namespace std;

bool resource1 = false;
bool resource2 = false;

void lockResource1() {
    if (!resource1) {
        resource1 = true; // Lock resource 1
        cout << "Locked resource 1\n";
    } else {
        cout << "Failed to lock resource 1\n";
    }
}

void lockResource2() {
    if (!resource2) {
        resource2 = true; // Lock resource 2
        cout << "Locked resource 2\n";
    } else {
        cout << "Failed to lock resource 2\n";
    }
}

void unlockResource1() {
    resource1 = false; // Unlock resource 1
    cout << "Unlocked resource 1\n";
}

void unlockResource2() {
    resource2 = false; // Unlock resource 2
    cout << "Unlocked resource 2\n";
}

void process1() {
    cout << "Process 1 trying to lock resources...\n";
    lockResource1();
    if (resource1) { // Check if resource 1 is locked
        cout << "Process 1: Locked resource 1, trying to lock resource 2...\n";
        lockResource2();
        if (resource2) {
            cout << "Process 1: Locked both resources.\n";
            unlockResource2();
            unlockResource1();
        } else {
            unlockResource1();
        }
    }
}

void process2() {
    cout << "Process 2 trying to lock resources...\n";
    lockResource2();
    if (resource2) { // Check if resource 2 is locked
        cout << "Process 2: Locked resource 2, trying to lock resource 1...\n";
        lockResource1();
        if (resource1) {
            cout << "Process 2: Locked both resources.\n";
            unlockResource1();
            unlockResource2();
        } else {
            unlockResource2();
        }
    }
}

int main() {
    process1();
    process2();
    return 0;
}
