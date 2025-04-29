#include <iostream>
#include <exception>

class MyCustomException : public std::exception {
public:
    const char* what() const noexcept override {
        return "My custom exception occurred!";
    }
};

void testCustomException() {
    throw MyCustomException();
}

int main() {
    try {
        testCustomException();
    }
    catch (const MyCustomException& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }
}