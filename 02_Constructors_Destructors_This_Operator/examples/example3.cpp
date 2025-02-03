#include <iostream>

class Adder {
public:
    int value;

    // Constructor to initialize value
    Adder(int v) : value(v) {}

    // Method to add a number to value and return the current object
    Adder* add(int v) {
        value += v;
        return this; // Return the current object
    }

    void display() {
        std::cout << "Value: " << value << std::endl;
    }
};

int main() {
    Adder adder(10);
    adder.add(5)->add(3)->add(2); // Method chaining using 'this'

    adder.display(); // Output: Value: 20
}
