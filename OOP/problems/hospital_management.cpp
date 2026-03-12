/*
Problem: Hospital Management System
Demonstrate Association and Aggregation relationships without inheritance.
Doctors are associated with Patients (weak association).
*/

#include <iostream>
#include <string>
#include <vector>

class Patient {
public:
    std::string name;
    int age;

    Patient(std::string n, int a) : name(n), age(a) {}
    
    std::string getDetails() const {
        return name + " (" + std::to_string(age) + " yrs)";
    }
};

class Doctor {
private:
    std::string name;
    std::string specialization;
    std::vector<Patient*> assignedPatients; // Aggregation of Patient pointers

public:
    Doctor(std::string n, std::string s) : name(n), specialization(s) {}

    void assignPatient(Patient* p) {
        assignedPatients.push_back(p);
        std::cout << "Patient " << p->name << " assigned to Dr. " << name << std::endl;
    }

    void viewPatients() const {
        std::cout << "Patients under Dr. " << name << " (" << specialization << "):" << std::endl;
        for (Patient* p : assignedPatients) {
            std::cout << "- " << p->getDetails() << std::endl;
        }
    }
};

int main() {
    // Independent Lifecycles (Aggregation)
    Patient p1("Alice Smith", 45);
    Patient p2("Bob Johnson", 30);
    Patient p3("Charlie Davis", 60);

    Doctor d1("Gregory House", "Diagnostic Medicine");
    Doctor d2("Stephen Strange", "Neurosurgery");

    d1.assignPatient(&p1);
    d1.assignPatient(&p3);
    d2.assignPatient(&p2);

    std::cout << "\n";
    d1.viewPatients();
    std::cout << "\n";
    d2.viewPatients();

    return 0; // Both patient and doctor objects are destroyed safely
}
