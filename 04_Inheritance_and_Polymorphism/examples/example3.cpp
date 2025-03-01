/*
    Without using virtual keyword
*/

#include <iostream>

class Base {
public:
    void show() { std::cout << "Base class\n"; }
};

class Derived : public Base {
public:
    void show() { std::cout << "Derived class\n"; }
};

int main() {
    Base* obj = new Derived();
    obj->show();  // Calls Base::show(), NOT Derived::show()
    delete obj;
    return 0;
}