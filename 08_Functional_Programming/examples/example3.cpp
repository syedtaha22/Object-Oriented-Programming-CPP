#include <iostream>

void compute(int x, int y, int (*func)(int, int)) {
    std::cout << "Result: " << func(x, y) << std::endl;
}

int subtract(int a, int b) { return a - b; }

int main() {
    compute(10, 4, subtract);  // Output: Result: 6
    return 0;
}
