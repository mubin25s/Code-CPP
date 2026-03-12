#include <iostream>
#include <string>

// Base class
class Animal {
public:
    void eat() {
        std::cout << "This animal is eating." << std::endl;
    }
};

// Derived class
class Dog : public Animal {
public:
    void bark() {
        std::cout << "The dog is barking. Woof!" << std::endl;
    }
};

int main() {
    Dog myDog;

    // Access methods from the base class
    myDog.eat();

    // Access methods from the derived class
    myDog.bark();

    return 0;
}
