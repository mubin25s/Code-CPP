#include <iostream>

using namespace std;

int main() {
    int numbers[5] = {7, 5, 6, 12, 35};
    int sum = 0;
    int count = 5;

    cout << "The numbers are: ";
    for (int i = 0; i < count; ++i) {
        cout << numbers[i] << "  ";
        sum += numbers[i];
    }

    cout << "\nSum = " << sum << endl;

    return 0;
}
