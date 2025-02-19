#include <iostream>


// Include LinkedListQueue.hpp here
#include "LinkedListQueue.hpp"

int main() {

    LinkedListQueue<int> q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    std::cout << "Is empty: " << q.isEmpty() << std::endl; // 0
    std::cout << "Size: " << q.size() << std::endl; // 3    
    std::cout << "Front: " << q.front() << std::endl; // 1
    std::cout << "Back: " << q.back() << std::endl; // 3

    while (!q.isEmpty()) {
        std::cout << q.front() << " ";
        q.dequeue();
    }
    std::cout << std::endl;

    std::cout << "Is empty: " << q.isEmpty() << std::endl; // 1
    std::cout << "Size: " << q.size() << std::endl; // 0

    return 0;
}