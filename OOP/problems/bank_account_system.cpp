/*
Problem: Bank Account System
Create a BankAccount class with encapsulation:
- Private members: accountNumber, accountHolderName, balance
- Public methods: deposit(amount), withdraw(amount), getBalance()
*/

#include <iostream>
#include <string>

class BankAccount {
private:
    std::string accountNumber;
    std::string accountHolderName;
    double balance;

public:
    BankAccount(std::string accNum, std::string name, double initialBalance = 0.0) {
        accountNumber = accNum;
        accountHolderName = name;
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposited $" << amount << ". New balance: $" << balance << std::endl;
        } else {
            std::cout << "Invalid deposit amount." << std::endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            std::cout << "Withdrew $" << amount << ". New balance: $" << balance << std::endl;
        } else {
            std::cout << "Invalid withdrawal amount or insufficient funds." << std::endl;
        }
    }

    double getBalance() const {
        return balance;
    }

    void display() const {
        std::cout << "Account: " << accountNumber << " | Holder: " << accountHolderName 
                  << " | Balance: $" << balance << std::endl;
    }
};

int main() {
    BankAccount myAcc("AC1001", "John Doe", 500);
    myAcc.display();
    myAcc.deposit(200);
    myAcc.withdraw(100);
    myAcc.withdraw(1000); // Should fail

    return 0;
}
