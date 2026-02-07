#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int num, original, remainder, result = 0, digits = 0;

    cout << "Enter a number: ";
    cin >> num;

    original = num;

    // Count number of digits
    while (original != 0) {
        digits++;
        original /= 10;
    }

    original = num;

    // Calculate sum of powers
    while (original != 0) {
        remainder = original % 10;
        result += pow(remainder, digits);
        original /= 10;
    }

    if (result == num) {
        cout << num << " is an Armstrong number" << endl;
    } else {
        cout << num << " is not an Armstrong number" << endl;
    }

    return 0;
}
