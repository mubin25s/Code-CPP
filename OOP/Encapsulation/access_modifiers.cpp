#include <iostream>
#include <string>

class BankAccount {
private:
    // Private attributes cannot be accessed from outside the class
    double balance;

public:
    // Constructor to initialize balance
    BankAccount(double initialBalance) {
        if (initialBalance >= 0) {
            balance = initialBalance;
        } else {
            balance = 0;
            std::cout << "Invalid initial balance. Setting to 0." << std::endl;
        }
    }

    // Public method to deposit money (Encapsulation)
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposited: $" << amount << std::endl;
        }
    }

    // Public method to check balance
    double getBalance() const {
        return balance;
    }
};

int main() {
    BankAccount myAccount(1000.0);
    
    // myAccount.balance = 5000; // This would cause a compilation error
    
    myAccount.deposit(500.0);
    std::cout << "Current Balance: $" << myAccount.getBalance() << std::endl;

    return 0;
}
