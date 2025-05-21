#include <iostream>

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }

int main() {
    int (*operations[])(int, int) = { add, subtract, multiply };
    int x = 6, y = 3;

    for (auto func : operations) {
        std::cout << func(x, y) << " ";
    }
    // Output: 9 3 18
    return 0;
}
