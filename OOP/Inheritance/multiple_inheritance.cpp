#include <iostream>

// Base Class 1
class Printer {
public:
    void print() {
        std::cout << "Printing document..." << std::endl;
    }
};

// Base Class 2
class Scanner {
public:
    void scan() {
        std::cout << "Scanning document..." << std::endl;
    }
};

// Derived Class inheriting from both Printer and Scanner
class MultiFunctionDevice : public Printer, public Scanner {
public:
    void copy() {
        std::cout << "Copying document..." << std::endl;
        scan();
        print();
    }
};

int main() {
    MultiFunctionDevice mfd;
    mfd.print();
    mfd.scan();
    mfd.copy();

    return 0;
}
