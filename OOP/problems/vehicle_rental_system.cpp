/*
Problem: Vehicle Rental System
Show Multilevel Inheritance:
Vehicle -> MotorVehicle -> Car / Truck
Compute rental cost based on specific subclass logic.
*/

#include <iostream>
#include <string>

// Level 1
class Vehicle {
protected:
    std::string licensePlate;
    int rentalDays;

public:
    Vehicle(std::string lp, int days) : licensePlate(lp), rentalDays(days) {}
    virtual double calculateRentalCost() const = 0; // pure virtual
    virtual void displayInfo() const {
        std::cout << "License: " << licensePlate << " | Days: " << rentalDays;
    }
};

// Level 2
class MotorVehicle : public Vehicle {
protected:
    double engineCapacity; // cc

public:
    MotorVehicle(std::string lp, int days, double eng) 
        : Vehicle(lp, days), engineCapacity(eng) {}
    
    void displayInfo() const override {
        Vehicle::displayInfo();
        std::cout << " | Engine CC: " << engineCapacity;
    }
};

// Level 3a
class Car : public MotorVehicle {
private:
    int seats;
    double dailyRate = 40.0;

public:
    Car(std::string lp, int days, double eng, int s) 
        : MotorVehicle(lp, days, eng), seats(s) {}

    double calculateRentalCost() const override {
        return dailyRate * rentalDays;
    }

    void displayInfo() const override {
        MotorVehicle::displayInfo();
        std::cout << " | Seats: " << seats << " | Total Cost: $" << calculateRentalCost() << std::endl;
    }
};

// Level 3b
class Truck : public MotorVehicle {
private:
    double loadCapacityTons;
    double dailyRate = 80.0;

public:
    Truck(std::string lp, int days, double eng, double load)
        : MotorVehicle(lp, days, eng), loadCapacityTons(load) {}

    double calculateRentalCost() const override {
        return dailyRate * rentalDays + (loadCapacityTons * 10.0); // Extra charge for load capacity
    }

    void displayInfo() const override {
        MotorVehicle::displayInfo();
        std::cout << " | Load Tons: " << loadCapacityTons << " | Total Cost: $" << calculateRentalCost() << std::endl;
    }
};

int main() {
    Car c1("ABC-123", 5, 1500, 5);
    Truck t1("TRK-999", 3, 4000, 2.5);

    c1.displayInfo();
    t1.displayInfo();

    return 0;
}
