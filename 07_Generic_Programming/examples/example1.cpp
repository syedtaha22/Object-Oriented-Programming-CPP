#include <iostream>

template<typename A, typename B>
class Pair {
    A first;
    B second;
public:
    Pair(const A& a, const B& b) : first(a), second(b) {}

    friend std::ostream& operator<<(std::ostream& os, const Pair<A, B>& pair) {
        os << "(" << pair.first << ", " << pair.second << ")";
        return os;
    }
};

int main() {
    Pair<int, double> p1(1, 2.5);
    Pair<std::string, int> p2("Hello", 42);

    std::cout << "Pair 1: " << p1 << std::endl;
    std::cout << "Pair 2: " << p2 << std::endl;

    return 0;
}