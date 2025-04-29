#include <iostream>

class Resource {
    int* data;
public:
    Resource() {
        data = new int[100];
        std::cout << "Resource acquired\n";
    }

    ~Resource() {
        delete[] data;
        std::cout << "Resource released\n";
    }
};

int main() {
    try {
        Resource r;
        throw 42;
    }
    catch (int e) {
        std::cout << "Caught exception: " << e << std::endl;
    }
}