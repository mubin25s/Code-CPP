#include <iostream>
#include <string>

class Student {
public:
    std::string name;
    int roll;

    // Default Constructor
    Student() {
        name = "Unknown";
        roll = 0;
        std::cout << "Default Constructor called" << std::endl;
    }

    // Parameterized Constructor
    Student(std::string n, int r) {
        name = n;
        roll = r;
        std::cout << "Parameterized Constructor called for " << name << std::endl;
    }

    // Copy Constructor
    Student(const Student &s) {
        name = s.name;
        roll = s.roll;
        std::cout << "Copy Constructor called for " << name << std::endl;
    }

    // Destructor
    ~Student() {
        std::cout << "Destructor called for " << name << std::endl;
    }
};

int main() {
    Student s1;
    Student s2("Alice", 101);
    Student s3 = s2; // Copy initialization

    return 0;
}
