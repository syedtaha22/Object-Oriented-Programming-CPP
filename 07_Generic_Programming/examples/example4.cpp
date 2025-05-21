#include <iostream>

// Base case: no arguments
void print() {
    std::cout << std::endl;
}

// Recursive variadic template function
template <typename T, typename... Args>
void print(T first, Args... args) {
    std::cout << first << " ";
    print(args...);
}

int main() {
    print(1, 2.5, "hello", 'A');

    return 0;
}
