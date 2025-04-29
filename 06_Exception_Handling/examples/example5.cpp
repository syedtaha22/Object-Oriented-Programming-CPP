#include <iostream>

void throwUnknown() {
    throw 42; // throwing an int, not a standard exception
}

int main() {
    try {
        throwUnknown();
    }
    catch (const std::exception& e) {
        std::cout << "Caught std::exception: " << e.what() << std::endl;
    }
    catch (...) {
        std::cout << "Caught an unknown exception!" << std::endl;
    }
}