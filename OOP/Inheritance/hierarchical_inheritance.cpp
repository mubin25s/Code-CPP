#include <iostream>

// Base Class
class Engine {
public:
    void startEngine() {
        std::cout << "Engine started." << std::endl;
    }
};

// Derived Class 1
class Car : public Engine {
public:
    void drive() {
        std::cout << "Driving the car." << std::endl;
    }
};

// Derived Class 2
class Motorcycle : public Engine {
public:
    void ride() {
        std::cout << "Riding the motorcycle." << std::endl;
    }
};

int main() {
    Car myCar;
    Motorcycle myBike;

    myCar.startEngine(); // Accessing base class method
    myCar.drive();

    myBike.startEngine(); // Accessing base class method
    myBike.ride();

    return 0;
}
