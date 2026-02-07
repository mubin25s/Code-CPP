#include <iostream>
using namespace std;

int main() {
    int a, b, temp;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }

    cout << "GCD: " << a << endl;

    return 0;
}
