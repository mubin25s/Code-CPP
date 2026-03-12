#include <iostream>
#include <vector>

// Base class
class Shape {
public:
    // Virtual function enables runtime polymorphism
    virtual void draw() {
        std::cout << "Drawing a generic shape." << std::endl;
    }
    
    // Virtual destructor is important for classes with virtual functions
    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a Circle." << std::endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a Rectangle." << std::endl;
    }
};

int main() {
    // Polymorphism in action using pointers to base class
    Shape* shape1 = new Circle();
    Shape* shape2 = new Rectangle();

    shape1->draw(); // Calls Circle::draw()
    shape2->draw(); // Calls Rectangle::draw()

    delete shape1;
    delete shape2;

    return 0;
}
