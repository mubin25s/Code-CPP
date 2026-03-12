#include <iostream>

// Abstract Class: Cannot be instantiated
class Animal {
public:
    // Pure virtual function
    virtual void sound() = 0;
};

// Derived classes MUST implement pure virtual functions
class Dog : public Animal {
public:
    void sound() override {
        std::cout << "Woof!" << std::endl;
    }
};

class Cat : public Animal {
public:
    void sound() override {
        std::cout << "Meow!" << std::endl;
    }
};

int main() {
    Animal* myDog = new Dog();
    Animal* myCat = new Cat();

    myDog->sound();
    myCat->sound();

    delete myDog;
    delete myCat;

    return 0;
}
