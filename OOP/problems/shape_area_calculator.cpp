/*
Problem: Shape Area Calculator 
Abstract class Shape with pure virtual function calculateArea().
Derived classes: Circle, Rectangle, Triangle.
Show runtime polymorphism by calculating area in an array of Shapes.
*/

#include <iostream>
#include <vector>

const double PI = 3.14159;

class Shape {
public:
    virtual double calculateArea() const = 0; // Pure virtual
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double calculateArea() const override {
        return PI * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double length, width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double calculateArea() const override {
        return length * width;
    }
};

class Triangle : public Shape {
private:
    double base, height;
public:
    Triangle(double b, double h) : base(b), height(h) {}
    double calculateArea() const override {
        return 0.5 * base * height;
    }
};

int main() {
    std::vector<Shape*> shapes;
    shapes.push_back(new Circle(5.0));
    shapes.push_back(new Rectangle(4.0, 6.0));
    shapes.push_back(new Triangle(3.0, 8.0));

    for (Shape* shape : shapes) {
        std::cout << "Area: " << shape->calculateArea() << std::endl;
    }

    for (Shape* shape : shapes) {
        delete shape;
    }

    return 0;
}
