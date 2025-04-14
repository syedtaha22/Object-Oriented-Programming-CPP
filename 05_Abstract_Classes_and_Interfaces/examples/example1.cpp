#include <iostream>

class Shape {
public:
    virtual void draw() = 0; // Pure virtual

    void info() { std::cout << "This is a shape." << std::endl; }
};

class Circle : public Shape {
public:
    void draw() override { std::cout << "Drawing a circle." << std::endl; }
};

int main() {
    Circle c;
    c.draw();
    c.info();
    return 0;
}