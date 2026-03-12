#include <iostream>

// Base Class
class Grandparent {
public:
    void displayGrandparent() {
        std::cout << "I am the Grandparent." << std::endl;
    }
};

// Derived Class 1 (acts as Base for Child)
class Parent : public Grandparent {
public:
    void displayParent() {
        std::cout << "I am the Parent." << std::endl;
    }
};

// Derived Class 2 (Inherits from Parent)
class Child : public Parent {
public:
    void displayChild() {
        std::cout << "I am the Child." << std::endl;
    }
};

int main() {
    Child c;
    // Child can access methods from all ancestor levels
    c.displayGrandparent();
    c.displayParent();
    c.displayChild();

    return 0;
}
