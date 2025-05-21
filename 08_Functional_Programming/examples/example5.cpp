#include <iostream>

void greet() {
    std::cout << "Hello, World!" << std::endl;
}

int main() {
    void (*funcPtr)() = greet;
    funcPtr();  // Output: Hello, World!
    return 0;
}
