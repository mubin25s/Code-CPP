#include <iostream>

class Base {
public:
    Base() { std::cout << "Base Constructor" << std::endl; }
    
    // Virtual destructor guarantees derived destructors are called
    virtual ~Base() { std::cout << "Base Destructor" << std::endl; }
};

class Derived : public Base {
public:
    Derived() { std::cout << "Derived Constructor" << std::endl; }
    ~Derived() { std::cout << "Derived Destructor" << std::endl; }
};

int main() {
    std::cout << "Creating pointer to Base class allocated with Derived..." << std::endl;
    Base* ptr = new Derived();

    std::cout << "Deleting pointer..." << std::endl;
    // Without a virtual destructor in Base, the Derived destructor would not be called here!
    delete ptr;

    return 0;
}
