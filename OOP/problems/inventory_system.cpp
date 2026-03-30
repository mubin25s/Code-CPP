/*
Problem: Inventory System
Use dynamic memory allocation to manage a list of items using pointers.
Implement Destructor to manage memory leaks.
*/

#include <iostream>
#include <string>

class Item {
public:
    std::string name;
    int quantity;
    double price;

    Item(std::string n, int q, double p) : name(n), quantity(q), price(p) {}
    
    void display() const {
        std::cout << name << " | Qty: " << quantity << " | Price: $" << price << std::endl;
    }
};

class Inventory {
private:
    Item** items; // Array of pointers to items
    int capacity;
    int count;


public:
    Inventory(int cap) : capacity(cap), count(0) {
        // Dynamically allocating array of Item pointers
        items = new Item*[capacity];
    }

    // Destructor to free dynamically allocated memory
    ~Inventory() {
        for (int i = 0; i < count; ++i) {
            delete items[i]; // Delete individual item objects
        }
        delete[] items; // Delete array of pointers
        std::cout << "Inventory Memory Freed" << std::endl;
    }

    void addItem(std::string n, int q, double p) {
        if (count < capacity) {
            items[count++] = new Item(n, q, p);
            std::cout << n << " added." << std::endl;
        } else {
            std::cout << "Inventory full!" << std::endl;
        }
    }

    void displayAll() const {
        std::cout << "--- Inventory ---" << std::endl;
        for (int i = 0; i < count; ++i) {
            items[i]->display();
        }
    }
};

int main() {
    Inventory* store = new Inventory(5);
    store->addItem("Laptop", 10, 899.99);
    store->addItem("Mouse", 50, 25.50);
    store->addItem("Keyboard", 30, 45.00);

    store->displayAll();

    // Invoking destructor explicitly via delete
    delete store;

    return 0;
}
