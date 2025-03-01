/*
    Problematic Destruction. See example6 for fix.
*/

#include <iostream>


class Base {
public:
    ~Base() { std::cout << "Base Destructor\n"; }
};

class Derived : public Base {
public:
    ~Derived() { std::cout << "Derived Destructor\n"; }
};

int main() {
    Base* obj = new Derived();
    delete obj;  // Calls Base destructor only!
    return 0;
}