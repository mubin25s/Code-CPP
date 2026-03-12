#include <iostream>
#include <string>

class Employee {
private:
    // Sensitive data
    int salary;
    std::string password;

public:
    std::string name;

    // Setter for salary with validation
    void setSalary(int s) {
        if (s > 0) {
            salary = s;
        } else {
            std::cout << "Invalid salary amount!" << std::endl;
        }
    }

    // Getter for salary
    int getSalary() {
        return salary;
    }

    // Setter for password
    void setPassword(std::string pwd) {
        if (pwd.length() >= 6) {
            password = pwd;
        } else {
            std::cout << "Password too short." << std::endl;
        }
    }
};

int main() {
    Employee emp;
    emp.name = "John Doe";
    
    emp.setSalary(-500); // Invalid
    emp.setSalary(5000); // Valid

    emp.setPassword("123");  // Invalid
    emp.setPassword("SecurePass1!"); // Valid

    std::cout << emp.name << " earns $" << emp.getSalary() << std::endl;

    return 0;
}
