#include <iostream>
#include <string>

// Define a simple class named 'Car'
class Car {
public:
    // Attributes (Data Members)
    std::string brand;
    std::string model;
    int year;

    // Methods (Member Functions)
    void displayInfo() {
        std::cout << "Brand: " << brand << "\n"
                  << "Model: " << model << "\n"
                  << "Year: " << year << std::endl;
    }
};

int main() {
    // Create an object of Car
    Car myCar;
    myCar.brand = "Toyota";
    myCar.model = "Corolla";
    myCar.year = 2022;

    // Call the method
    std::cout << "Car Details:" << std::endl;
    myCar.displayInfo();

    return 0;
}
