#include <iostream>


// Base class
class Animal {
public:
    void eat() {
        std::cout << "This animal is eating.\n";
    }
};

// Derived class
class Dog : public Animal {
public:
    void bark() {
        std::cout << "The dog is barking.\n";
    }
};

int main() {
    Dog myDog;
    myDog.eat();  // Inherited function
    myDog.bark(); // Derived class function
    return 0;
}