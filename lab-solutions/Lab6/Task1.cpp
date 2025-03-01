/*******************************************************************************************
    Task 1:
        Create an interface IVehicle with pure virtual methods accelerate(int speed) and
        decelerate(int speed). Create an abstract class Car that implements IVehicle and
        has a pure virtual method startEngine().

        Create two classes Sedan and SUV that extend Car and implement the accelerate()
        and decelerate() methods. Create an interface IConvertible with a pure virtual
        method openRoof() and implement this interface in the Sedan class.
*******************************************************************************************/
#include <iostream>

class IVehicle {
public:
    virtual void accelerate(int speed) = 0;
    virtual void decelerate(int speed) = 0;
    virtual ~IVehicle() {}
};

class Car : public IVehicle {
public:
    virtual void startEngine() = 0;
    virtual ~Car() {}
};

class IConvertible {
public:
    virtual void openRoof() = 0;
    virtual ~IConvertible() {}
};

class Sedan : public Car, public IConvertible {
public:
    void accelerate(int speed) override { std::cout << "Sedan is accelerating at " << speed << " km/h" << std::endl; }
    void decelerate(int speed) override { std::cout << "Sedan is decelerating at " << speed << " km/h" << std::endl; }
    void startEngine() override { std::cout << "Sedan engine started" << std::endl; }
    void openRoof() override { std::cout << "Sedan roof opened" << std::endl; }
};

class SUV : public Car {
public:
    void accelerate(int speed) override { std::cout << "SUV is accelerating at " << speed << " km/h" << std::endl; }
    void decelerate(int speed) override { std::cout << "SUV is decelerating at " << speed << " km/h" << std::endl; }
    void startEngine() override { std::cout << "SUV engine started" << std::endl; }
};

int main() {

    Sedan sedan;
    sedan.startEngine();
    sedan.accelerate(100);
    sedan.decelerate(50);
    sedan.openRoof();

    std::cout << std::endl;

    SUV suv;
    suv.startEngine();
    suv.accelerate(120);
    suv.decelerate(60);

    return 0;
}