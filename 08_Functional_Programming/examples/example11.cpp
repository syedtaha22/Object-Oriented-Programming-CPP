#include <iostream>

class Counter {
    int count;
public:
    Counter() : count(0) {}

    void operator()() {
        ++count;
        std::cout << "Count: " << count << std::endl;
    }
};

int main() {
    Counter counter;
    counter();  // Count: 1
    counter();  // Count: 2
    return 0;
}
