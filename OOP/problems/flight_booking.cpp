/*
Problem: Flight Booking System
Demonstrate static members to keep track of total booked flights.
*/

#include <iostream>
#include <string>

class FlightTicket {
private:
    std::string passengerName;
    std::string flightNumber;
    int ticketID;
    static int totalTicketsSold; // Static attribute

public:
    FlightTicket(std::string name, std::string flight) 
        : passengerName(name), flightNumber(flight) {
        
        totalTicketsSold++; // Increment static counter on every object creation
        ticketID = totalTicketsSold; 
    }

    void displayTicket() const {
        std::cout << "Ticket ID: " << ticketID 
                  << " | Passenger: " << passengerName 
                  << " | Flight: " << flightNumber << std::endl;
    }

    // Static function to access static attribute
    static int getTotalTicketsSold() {
        return totalTicketsSold;
    }
};

// Initialize static member variable
int FlightTicket::totalTicketsSold = 0;

int main() {
    std::cout << "Total tickets before booking: " << FlightTicket::getTotalTicketsSold() << std::endl;

    FlightTicket t1("Alice", "FL100");
    FlightTicket t2("Bob", "FL100");
    FlightTicket t3("Charlie", "FL205");

    t1.displayTicket();
    t2.displayTicket();
    t3.displayTicket();

    std::cout << "Total tickets after booking: " << FlightTicket::getTotalTicketsSold() << std::endl;

    return 0;
}
