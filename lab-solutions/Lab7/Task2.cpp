/******************************************************************************************
    Task 2:
        Create a diamond inheritance structure where Base has an identity function that
        returns a unique class identifier. Derive Left and Right from Base, and then
        derive Final from both.
            1. Store a Final object in a Base* pointer and call the identity function.
            2. Observe whether Base's function is called multiple times due to duplicate
               subobjects.
            3. Modify the structure to remove duplicate Base instances and ensure correct
               function calls.
            4. Document why the diamond problem caused issues and how virtual inheritance
               resolved them.
*****************************************************************************************/

#include <iostream>

class Base {
public:
    virtual void identity() { std::cout << "Base" << std::endl; }
};

class Left : virtual public Base {
public:
    void identity() override { std::cout << "Left" << std::endl; }
};

class Right : virtual public Base {
public:
    void identity() override { std::cout << "Right" << std::endl; }
};

class Final : public Left, public Right {
public:
    void identity() override { std::cout << "Final" << std::endl; }
};

int main() {
    Base* base = new Final();
    base->identity();
    delete base;
    return 0;
}