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
    Derived d;
    Base* b = static_cast<Base*>(&d); // Upcasting
    b->show(); // Output: Derived class (due to virtual function)

    return 0;
}

