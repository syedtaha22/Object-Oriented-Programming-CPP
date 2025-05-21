#include <iostream>

int add(int a, int b) { return a + b; }
int multiply(int a, int b) { return a * b; }

int main() {
    int (*operation)(int, int) = add;
    std::cout << "Add: " << operation(5, 2) << std::endl;  // Output: Add: 7

    operation = multiply;
    std::cout << "Multiply: " << operation(5, 2) << std::endl;  // Output: Multiply: 10

    return 0;
}
