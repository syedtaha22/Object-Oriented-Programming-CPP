/**************************************************************************************************
    Task 1:
        Create a class Base with a dynamically allocated resource and a virtual destructor.
        Derive Intermediate from Base, and further derive Final from Intermediate. The Final
        class should throw an exception in its destructor.

        Inside the main function
            • Dynamically allocate a Final object using a Base*.
            • Delete the object inside a try-catch block.
            • Observe and analyze what happens when the destructor of Final throws an exception.
            • Identify and fix any issues related to exception safety in destructors.
        In comments, document:
            • What happens when the exception is thrown inside the destructor.
            • Why this is dangerous.
            • The correct way to handle exceptions in destructors.
*************************************************************************************************/

#include <iostream>
#include <exception>

class Base {
    int* resource;
public:
    Base() {
        std::cout << "Base constructor" << std::endl;
        resource = new int[10];
    }

    virtual ~Base() {
        std::cout << "Base Destructor" << std::endl;
        delete[] resource;
    }
};

class Intermediate : public Base {
public:
    Intermediate() { std::cout << "Intermediate constructor" << std::endl; }
    ~Intermediate() { std::cout << "Intermediate destructor" << std::endl; }
};

class Final : public Intermediate {
public:
    Final() { std::cout << "Final contructor" << std::endl; }

    // ~Final() {
    //     std::cout << "Final destructor" << std::endl;
    //     throw std::runtime_error("Exception thrown from Final destructor");
    // }

    // Resolve the issue by catching the exception in the destructor
    ~Final() {
        try {
            std::cout << "Final destructor" << std::endl;
            throw std::runtime_error("Exception thrown from Final destructor");
        }
        catch (const std::exception& e) { std::cerr << e.what() << std::endl; }
    }
};

int main() {
    try {
        Base* base = new Final();
        delete base;
    }
    catch (const std::exception& e) { std::cerr << e.what() << std::endl; }

    return 0;
}

