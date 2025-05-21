#include <iostream>

class Multiplier {
    int factor;
public:
    Multiplier(int f) : factor(f) {}

    int operator()(int a, int b) const {
        return factor * (a + b);
    }
};

int main() {
    Multiplier mul3(3);
    std::cout << mul3(2, 4) << std::endl;  // Output: 18 (3 * (2 + 4))
    return 0;
}
