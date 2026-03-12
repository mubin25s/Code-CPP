/*
Problem: Student Management System
Create a Class 'Student' with the following:
1. Private attributes: name, rollNumber, marks.
2. Constructor to initialize these values.
3. Method to display student details.
4. Method to calculate and return the grade based on marks.
   - Marks >= 90: A+
   - Marks >= 80: A
   - Marks >= 70: B
   - Marks < 70: F
*/

#include <iostream>
#include <string>
#include <vector>

class Student {
private:
    std::string name;
    int rollNumber;
    float marks;

public:
    Student(std::string n, int r, float m) : name(n), rollNumber(r), marks(m) {}

    std::string calculateGrade() {
        if (marks >= 90) return "A+";
        if (marks >= 80) return "A";
        if (marks >= 70) return "B";
        return "F";
    }

    void display() {
        std::cout << "Name: " << name 
                  << " | Roll: " << rollNumber 
                  << " | Marks: " << marks 
                  << " | Grade: " << calculateGrade() << std::endl;
    }
};

int main() {
    std::vector<Student> students;
    students.push_back(Student("Alice", 101, 92.5));
    students.push_back(Student("Bob", 102, 78.0));
    students.push_back(Student("Charlie", 103, 65.5));

    std::cout << "--- Student Records ---" << std::endl;
    for (auto& s : students) {
        s.display();
    }

    return 0;
}
