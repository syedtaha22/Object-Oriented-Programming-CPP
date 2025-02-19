#include <iostream>

// Include LinkedListStack.hpp here
#include "LinkedListStack.hpp"

int main() {

    LinkedListStack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);

    std::cout << "Is empty: " << s.isEmpty() << std::endl; // 0
    std::cout << "Size: " << s.size() << std::endl; // 3
    std::cout << "Top: " << s.top() << std::endl; // 3

    while (!s.isEmpty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl;

    std::cout << "Is empty: " << s.isEmpty() << std::endl; // 1
    std::cout << "Size: " << s.size() << std::endl; // 0

    return 0;
}