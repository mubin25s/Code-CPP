#include <iostream>

class Box {
private:
    double width;

public:
    Box() : width(0) {}
    void setWidth(double w) { width = w; }

    // Declare a friend function
    friend void printWidth(Box box);
};

// Definition of friend function. It is not a member function of Box, 
// yet it has access to the private members of Box.
void printWidth(Box box) {
    std::cout << "Width of box: " << box.width << std::endl;
}

int main() {
    Box myBox;
    myBox.setWidth(10.5);

    // Call the friend function without using an object
    printWidth(myBox);

    return 0;
}
