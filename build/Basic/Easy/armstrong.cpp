#include <iostream>
#include <cmath>
using namespace std;

void armstrong(int num) {
    int digit = 0;
    int result = 0;
    int temp = num;  // Use a temporary variable for calculations

    // Calculate the number of digits
    while (temp > 0) {
        temp = temp / 10;
        digit++;
    }

    temp = num;  // Reset temp to the original number

    // Calculate the Armstrong number
    while (temp > 0) {
        int lastdigit = temp % 10;
        result = result + static_cast<int>(pow(lastdigit, digit));
        temp = temp / 10;
    }

    // Output the result
    if (result == num)
        cout << "It is an Armstrong number";
    else
        cout << "It is not an Armstrong number";
}

int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;
    armstrong(n);
    return 0;
}
