#include <iostream>

class MathOperations {
public:
    // Function Overloading allows multiple functions with the same name
    // but different parameters (compile-time polymorphism).

    int add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }

    int add(int a, int b, int c) {
        return a + b + c;
    }
};

int main() {
    MathOperations math;

    std::cout << "Addition of 2 ints: " << math.add(5, 10) << std::endl;
    std::cout << "Addition of 2 doubles: " << math.add(5.5, 10.5) << std::endl;
    std::cout << "Addition of 3 ints: " << math.add(1, 2, 3) << std::endl;

    return 0;
}
