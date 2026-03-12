#include <iostream>

class Box {
private:
    double length;
    double breadth;
    double height;

public:
    // Constructor using 'this' pointer to differentiate between members and parameters
    Box(double length, double breadth, double height) {
        this->length = length;
        this->breadth = breadth;
        this->height = height;
    }

    double getVolume() {
        return length * breadth * height;
    }

    // Method returning the object reference
    Box& compareVolume(Box &other) {
        if (this->getVolume() > other.getVolume()) {
            std::cout << "Current box is larger." << std::endl;
            return *this;
        } else {
            std::cout << "Other box is larger or equal." << std::endl;
            return other;
        }
    }
};

int main() {
    Box box1(3.0, 4.0, 5.0);
    Box box2(4.0, 5.0, 6.0);

    // Call compareVolume which uses 'this' internally
    box1.compareVolume(box2);

    return 0;
}
