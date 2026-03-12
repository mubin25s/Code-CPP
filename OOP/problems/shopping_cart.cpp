/*
Problem: Shopping Cart (Operator Overloading)
Overload + to combine items or shopping carts,
Overload << to print the cart details.
*/

#include <iostream>
#include <string>
#include <vector>

class ShoppingCart {
private:
    std::vector<std::string> items;
    double totalCost;

public:
    ShoppingCart() : totalCost(0) {}

    void addItem(std::string item, double price) {
        items.push_back(item);
        totalCost += price;
    }

    // Overload + to merge two carts
    ShoppingCart operator+(const ShoppingCart& other) {
        ShoppingCart newCart;
        
        for (const auto& item : this->items) {
            newCart.items.push_back(item);
        }
        for (const auto& item : other.items) {
            newCart.items.push_back(item);
        }
        
        newCart.totalCost = this->totalCost + other.totalCost;
        return newCart;
    }

    // Friend function to overload <<
    friend std::ostream& operator<<(std::ostream& os, const ShoppingCart& cart);
};

// Print cart content using stream insertion overload
std::ostream& operator<<(std::ostream& os, const ShoppingCart& cart) {
    os << "Cart Items: ";
    for (const auto& item : cart.items) {
        os << item << ", ";
    }
    os << " | Total Cost: $" << cart.totalCost;
    return os;
}

int main() {
    ShoppingCart cart1;
    cart1.addItem("Apple", 1.20);
    cart1.addItem("Banana", 0.50);

    ShoppingCart cart2;
    cart2.addItem("Milk", 2.00);
    cart2.addItem("Bread", 1.50);

    ShoppingCart combinedCart = cart1 + cart2;

    std::cout << "Cart 1 -> " << cart1 << std::endl;
    std::cout << "Cart 2 -> " << cart2 << std::endl;
    std::cout << "Combined -> " << combinedCart << std::endl;

    return 0;
}
