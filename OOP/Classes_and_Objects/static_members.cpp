#include <iostream>

class Counter {
private:
    // Static member variable
    static int count;

public:
    // Constructor increments count
    Counter() {
        count++;
    }

    // Static member function
    static int getCount() {
        return count;
    }
};

// Initialization of static member outside the class
int Counter::count = 0;

int main() {
    std::cout << "Initial Count: " << Counter::getCount() << std::endl;

    Counter c1;
    Counter c2;
    Counter c3;

    std::cout << "Count after creating 3 objects: " << Counter::getCount() << std::endl;

    return 0;
}
