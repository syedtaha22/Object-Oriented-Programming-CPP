#include <iostream>

template <typename T>
class Printer {
public:
    void print(T value) {
        std::cout << "Generic Printer: " << value << std::endl;
    }
};

// Partial specialization for pointer types
template <typename T>
class Printer<T*> {
public:
    void print(T* ptr) {
        if (ptr) std::cout << "Pointer Printer: " << *ptr << std::endl;
        else std::cout << "Pointer Printer: nullptr" << std::endl;
    }
};

int main() {
    Printer<int> p1;
    Printer<int*> p2;

    int x = 42;
    int* ptr = &x;

    p1.print(x);  // Generic Printer
    p2.print(ptr);  // Pointer Printer

    return 0;
}
