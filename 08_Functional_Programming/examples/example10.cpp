#include <iostream>

class Adder {
    int value;
public:
    Adder(int v) : value(v) {}

    int operator()(int x) const {
        return x + value;
    }
};

int main() {
    Adder add5(5);
    std::cout << add5(10) << std::endl;  // Output: 15
    return 0;
}
