#include <iostream>

int main() {
    int x = 10;
    auto lambda = [&x]() {
        x += 5;
        std::cout << "Captured by reference: " << x << std::endl;
        };
    lambda();  // Output: 15
    return 0;
}
