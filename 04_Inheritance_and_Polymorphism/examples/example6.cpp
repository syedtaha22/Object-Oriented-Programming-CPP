/*
    Example 5 fix: Use virtual destructors
*/

#include <iostream>


class Base {
public:
    virtual ~Base() { std::cout << "Base Destructor\n"; }
};

class Derived : public Base {
public:
    ~Derived() { std::cout << "Derived Destructor\n"; }
};

int main() {
    Base* obj = new Derived();
    delete obj;  // Calls Derived destructor first, then Base destructor
    return 0;
}