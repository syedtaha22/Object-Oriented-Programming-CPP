#include <iostream>
#include <functional>

int main() {
    int x = 5;
    auto lambda = [x](int a) {
        return a + x;
        };

    std::function<int(int)> f = lambda;
    std::cout << f(10) << std::endl;  // Output: 15
    return 0;
}
