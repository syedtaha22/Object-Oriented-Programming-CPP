#include <iostream>
#include <functional>

void compute(int a, int b, std::function<int(int, int)> func) {
    std::cout << "Result: " << func(a, b) << std::endl;
}

int main() {
    compute(5, 3, [](int x, int y) { return x - y; });  // Output: Result: 2
    return 0;
}
