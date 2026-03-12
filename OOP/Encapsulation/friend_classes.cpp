#include <iostream>

class ClassA {
private:
    int secretDataA;

public:
    ClassA() : secretDataA(100) {}

    // Declare ClassB as a friend class
    friend class ClassB;
};

class ClassB {
public:
    void showSecret(ClassA& a) {
        // ClassB can access private members of ClassA
        std::cout << "Secret data from ClassA: " << a.secretDataA << std::endl;
    }
};

int main() {
    ClassA objA;
    ClassB objB;

    objB.showSecret(objA);

    return 0;
}
