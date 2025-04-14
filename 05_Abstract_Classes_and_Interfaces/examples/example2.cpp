#include <iostream>

class Flyable {
public:
    virtual void fly() = 0;
};

class Swimmable {
public:
    virtual void swim() = 0;
};

class Duck : public Flyable, public Swimmable {
public:
    void fly() override { std::cout << "Duck flying." << std::endl; }
    void swim() override { std::cout << "Duck swimming." << std::endl; }
};

int main() {
    Duck d;
    d.fly();
    d.swim();
    return 0;
}
