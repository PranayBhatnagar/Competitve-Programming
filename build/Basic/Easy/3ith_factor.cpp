//
// Created by bhatn on 10-06-2024.
//
#include <iostream>
#include <vector>
using namespace std;

vector<int> ith_factor(int n) {
    vector<int> factors;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0)
            factors.push_back(i);
    }
    return factors;
}

int main() {
    int n;
    int index;
    cout << "Enter the number: ";
    cin >> n;
    cout << "Enter the index of the factor: ";
    cin >> index;

    vector<int> factors = ith_factor(n);

    if (index > 0 && index <= factors.size()) {
        cout << "The element at " << index << "th factor is: " << factors[index - 1] << endl;
    } else {
        cout << "Invalid index" << endl;
    }

    return 0;
}
