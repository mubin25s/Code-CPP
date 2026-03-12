/*
Problem: Online Store (Deep vs Shallow Copying)
Understand why Copy Constructors are needed when using pointers as class members.
*/

#include <iostream>
#include <string>
#include <cstring>

class Product {
private:
    char* name; // Using character pointer instead of string for demonstration
    double price;

public:
    // Parameterized Constructor
    Product(const char* n, double p) {
        name = new char[strlen(n) + 1]; // allocate dynamic memory
        strcpy(name, n);
        price = p;
        std::cout << "Constructor called for " << name << std::endl;
    }

    // Deep Copy Constructor
    // Try commenting this out to see issues with double free / shallow copying
    Product(const Product& other) {
        name = new char[strlen(other.name) + 1]; // Allocate NEW memory
        strcpy(name, other.name); // Copy the value
        price = other.price;
        std::cout << "Deep Copy Constructor called for " << name << std::endl;
    }

    ~Product() {
        std::cout << "Destructor called for " << name << std::endl;
        delete[] name; // Free dynamically allocated memory
    }

    void display() const {
        std::cout << "Product: " << name << " | Price: $" << price << std::endl;
    }

    // Mutator
    void setName(const char* newName) {
        delete[] name;
        name = new char[strlen(newName) + 1];
        strcpy(name, newName);
    }
};

int main() {
    Product p1("Wireless Mouse", 20.0);
    
    // Creating a copy of p1. With a standard shallow copy, they would point to the same char array!
    Product p2 = p1; // This invokes the copy constructor

    std::cout << "\n--- Before Modifying Copy ---" << std::endl;
    p1.display();
    p2.display();

    std::cout << "\n--- Modifying the Copy ---" << std::endl;
    p2.setName("Gaming Mouse (Mod)");
    
    // p1's name remains unchanged due to Deep Copy
    p1.display();
    p2.display();

    std::cout << "\n--- Exiting Scope ---" << std::endl;
    return 0;
}
