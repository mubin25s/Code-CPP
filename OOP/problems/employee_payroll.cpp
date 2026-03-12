/*
Problem: Employee Payroll System
Create:
- Base class Employee (id, name, baseSalary) with pure virtual function calculateSalary()
- Derived classes FullTimeEmployee, PartTimeEmployee, Intern implementing calculateSalary() uniquely.
*/

#include <iostream>
#include <string>

class Employee {
protected:
    int id;
    std::string name;
    double baseSalary;

public:
    Employee(int id, std::string name, double baseSal) : id(id), name(name), baseSalary(baseSal) {}
    
    // Pure virtual function
    virtual double calculateSalary() = 0;
    
    virtual void displayDetails() {
        std::cout << "ID: " << id << " | Name: " << name << " | Base: $" << baseSalary;
    }
};

class FullTimeEmployee : public Employee {
private:
    double bonus;

public:
    FullTimeEmployee(int id, std::string name, double baseSal, double bonus) 
        : Employee(id, name, baseSal), bonus(bonus) {}

    double calculateSalary() override {
        return baseSalary + bonus;
    }

    void displayDetails() override {
        Employee::displayDetails();
        std::cout << " | Total Salary (Full-time): $" << calculateSalary() << std::endl;
    }
};

class PartTimeEmployee : public Employee {
private:
    int hoursWorked;
    double hourlyRate;

public:
    PartTimeEmployee(int id, std::string name, int hours, double rate)
        : Employee(id, name, 0), hoursWorked(hours), hourlyRate(rate) {}

    double calculateSalary() override {
        return hoursWorked * hourlyRate;
    }

    void displayDetails() override {
        Employee::displayDetails();
        std::cout << " | Total Salary (Part-time): $" << calculateSalary() << std::endl;
    }
};

int main() {
    Employee* emp1 = new FullTimeEmployee(101, "Alice", 5000, 1500);
    Employee* emp2 = new PartTimeEmployee(102, "Bob", 40, 20);

    emp1->displayDetails();
    emp2->displayDetails();

    delete emp1;
    delete emp2;

    return 0;
}
