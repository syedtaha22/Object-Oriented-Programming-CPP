#include <iostream>
#include <functional>

int add(int a, int b) {
    return a + b;
}

int main() {
    std::function<int(int, int)> op = add;
    std::cout << op(3, 4) << std::endl;  // Output: 7
    return 0;
}
