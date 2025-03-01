/*
    Example 3 fix by using virtual functions
*/

#include <iostream>

class Base {
public:
    virtual void show() { std::cout << "Base class\n"; }
};

class Derived : public Base {
public:
    void show() override { std::cout << "Derived class\n"; }
};

int main() {
    Base* obj = new Derived();
    obj->show();  // Calls Derived::show() because of virtual 
    delete obj;
    return 0;
}