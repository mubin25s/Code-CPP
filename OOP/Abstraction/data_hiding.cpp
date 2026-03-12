#include <iostream>

class Bank {
private:
    double vaultBalance; // Hidden data

public:
    Bank(double initial) : vaultBalance(initial) {}

    // Public interface to interact with hidden data securely
    void deposit(double amount) {
        if (amount > 0) vaultBalance += amount;
    }

    bool withdraw(double amount) {
        if (amount > 0 && amount <= vaultBalance) {
            vaultBalance -= amount;
            return true;
        }
        return false;
    }

    double checkBalance() const {
        return vaultBalance; // Controlled access
    }
};

int main() {
    Bank atm(5000.0);
    // vaultBalance cannot be accessed directly: atm.vaultBalance = 0; (Error)
    
    atm.deposit(1000.0);
    if(atm.withdraw(2000.0)) {
        std::cout << "Withdrawal successful." << std::endl;
    }
    
    std::cout << "Current Balance: $" << atm.checkBalance() << std::endl;

    return 0;
}
