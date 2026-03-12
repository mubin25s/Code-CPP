/*
Problem: Ticket Reservation System
Polymorphism and function overriding.
Calculate booking price using virtual methods based on ticket class structure.
*/

#include <iostream>
#include <string>

class Ticket {
protected:
    double basePrice;

public:
    Ticket(double b) : basePrice(b) {}
    
    // Virtual function enables runtime polymorphism
    virtual double calculateFare() const {
        return basePrice;
    }

    virtual void generateTicket() const {
        std::cout << "Standard Fare: $" << calculateFare();
    }
    
    virtual ~Ticket() {}
};

class EconomyTicket : public Ticket {
public:
    EconomyTicket(double b) : Ticket(b) {}
    
    double calculateFare() const override {
        return basePrice; // No extra charges
    }

    void generateTicket() const override {
        std::cout << "[Economy Class] Total Fare: $" << calculateFare() << std::endl;
    }
};

class BusinessTicket : public Ticket {
public:
    BusinessTicket(double b) : Ticket(b) {}
    
    double calculateFare() const override {
        return basePrice + (basePrice * 0.50); // 50% premium
    }
    
    void generateTicket() const override {
        std::cout << "[Business Class] Total Fare: $" << calculateFare() << std::endl;
    }
};

class FirstClassTicket : public Ticket {
public:
    FirstClassTicket(double b) : Ticket(b) {}
    
    double calculateFare() const override {
        return basePrice + (basePrice * 1.50) + 200; // 150% premium + luxury tax
    }
    
    void generateTicket() const override {
        std::cout << "[First Class] Total Fare: $" << calculateFare() << std::endl;
    }
};

int main() {
    double standardBasePrice = 300.0;

    // Array of base class pointers storing derived objects
    Ticket* bookings[3];
    bookings[0] = new EconomyTicket(standardBasePrice);
    bookings[1] = new BusinessTicket(standardBasePrice);
    bookings[2] = new FirstClassTicket(standardBasePrice);

    for (int i = 0; i < 3; ++i) {
        bookings[i]->generateTicket();
    }

    // Cleanup
    for (int i = 0; i < 3; ++i) {
        delete bookings[i];
    }

    return 0;
}
