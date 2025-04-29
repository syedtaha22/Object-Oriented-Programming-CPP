#include <iostream>

class Tracker {
    std::string name;
public:
    Tracker(std::string n) : name(n) {
        std::cout << "Constructed: " << name << std::endl;
    }
    ~Tracker() {
        std::cout << "Destructed: " << name << std::endl;
    }
};

void C() {
    Tracker t3("t3");
    throw std::runtime_error("Error in C");
}

void B() {
    Tracker t2("t2");
    C();
}

void A() {
    Tracker t1("t1");
    try {
        B();
    }
    catch (const std::exception& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }
}

int main() {
    A();
}