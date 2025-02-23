/**************************************************************************************
    Task 2:
        Create a base class Vehicle with a constructor that prints "Vehicle created"
        and a destructor that prints "Vehicle destroyed".

        Derive a class Car that prints "Car created" and "Car destroyed" in its
        constructor and destructor.
        • Create a main() function that instantiates a Car object.
        • Observe the order of constructor and destructor calls.
        • Explain why the constructor and destructor order follows this pattern.
***************************************************************************************/

#include <iostream>

class Vehicle {
public:
    Vehicle() { std::cout << "Vehicle created" << std::endl; }
    ~Vehicle() { std::cout << "Vehicle destroyed" << std::endl; }
};

class Car : public Vehicle {
public:
    Car() { std::cout << "Car created" << std::endl; }
    ~Car() { std::cout << "Car destroyed" << std::endl; }
};

/****************************************************************************************
    The constructor and destructor order follows the inheritance hierarchy. When an
    object of the derived class is created, the base class constructor is called first,
    followed by the derived class constructor
    When the object goes out of scope, the derived class destructor is called first,
    followed by the base class destructor.
    This pattern ensures that the base class is fully constructed before the derived
    class and fully destructed after the derived class.
****************************************************************************************/
int main() {
    Car car; // Creating Car object
    return 0;
}