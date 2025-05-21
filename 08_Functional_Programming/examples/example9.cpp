#include <iostream>

int main() {
    int a = 5, b = 10;
    auto lambda = [&]() {
        a += 5;
        b += 10;
        std::cout << "a = " << a << ", b = " << b << std::endl;
        };
    lambda();  // Output: a = 10, b = 20
    return 0;
}
