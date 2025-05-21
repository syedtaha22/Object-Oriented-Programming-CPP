#include <iostream>

int main() {
    int a = 5, b = 10;
    auto lambda = [=]() {
        std::cout << "a = " << a << ", b = " << b << std::endl;
        };
    lambda();  // Output: a = 5, b = 10
    return 0;
}
