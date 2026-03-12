#include <iostream>

// Abstract class (contains at least one pure virtual function)
class RemoteControl {
public:
    // Pure virtual function
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;

    void commonDescription() {
        std::cout << "This is a remote control." << std::endl;
    }
};

class TVRemote : public RemoteControl {
public:
    void turnOn() override {
        std::cout << "TV is now ON." << std::endl;
    }
    void turnOff() override {
        std::cout << "TV is now OFF." << std::endl;
    }
};

int main() {
    // RemoteControl remote; // Error: Cannot instantiate abstract class
    
    TVRemote myRemote;
    myRemote.commonDescription();
    myRemote.turnOn();
    myRemote.turnOff();

    return 0;
}
