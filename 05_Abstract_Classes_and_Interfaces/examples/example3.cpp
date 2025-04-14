#include <iostream>

class Vehicle {
public:
    virtual void start() = 0;
};

class Car : public Vehicle {
public:
    void start() override { std::cout << "Car starting..." << std::endl; }
};

int main() {

    // Vehicle v; // Error: cannot instantiate abstract class
    Car c;
    c.start();
    return 0;
}
