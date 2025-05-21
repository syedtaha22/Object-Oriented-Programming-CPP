#include <iostream>

int add(int a, int b) {
    return a + b;
}

int main() {
    int (*funcPtr)(int, int) = add;
    std::cout << "Sum: " << funcPtr(3, 4) << std::endl;  // Output: Sum: 7
    return 0;
}
