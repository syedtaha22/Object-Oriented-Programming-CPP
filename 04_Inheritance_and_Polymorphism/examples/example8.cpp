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
    Base* b = new Derived(); // Base pointer to Derived object
    Derived* d = dynamic_cast<Derived*>(b);

    if (d) d->show(); // Output: Derived class
    else std::cout << "Failed to cast" << std::endl;

    delete b;
    return 0;
}