#include <iostream>
#include <stdexcept>

void mayThrow(int num) {
    if (num == 0)
        throw std::invalid_argument("Argument cannot be zero");
    if (num < 0)
        throw std::out_of_range("Argument must be positive");
    std::cout << "Valid input: " << num << std::endl;
}

int main() {
    try {
        mayThrow(0);
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
}