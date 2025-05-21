#include <iostream>

int main() {
    int x = 10;
    auto lambda = [x]() {
        std::cout << "Captured by value: " << x << std::endl;
        };
    lambda();  // Output: 10
    return 0;
}
