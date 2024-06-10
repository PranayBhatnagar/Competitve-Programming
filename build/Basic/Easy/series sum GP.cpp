//
// Created by bhatn on 10-06-2024.
//
#include <iostream>
#include <cmath>
#include <iomanip> // Include iomanip for fixed and setprecision

using namespace std;

void geometric_sum(int n) {
    long double sum = 0;
    for (int i = 0; i <= n; i++) {
        sum = sum + 1 / (pow(2, i));
    }
    cout << fixed << setprecision(5); // Set precision to 5 decimal places
    cout << "Geometric sum is: " << sum;
}

int main() {
    int k;
    cout << "Enter the value: ";
    cin >> k;
    geometric_sum(k);
    return 0;
}
