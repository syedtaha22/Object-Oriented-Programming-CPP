/**********************************************************************************************
    Task 1:
        Define a class DynamicInt that contains the following:
            • A dynamically allocated integer
            • A constructor that initializes the integer
            • A method set(int) that sets the value of the integer
            • A method get() that returns the value of the integer
            • A default copy constructor (compiler-generated)
        Create an object, copy it using the default copy constructor, and modify the original
        object. Observe the behavior and explain the issue.

        Modify the DynamicInt class to manually implement a copy constructor that
        performs a deep copy. Demonstrate that modifying the original object does not affect
        the copied one. Why?

        Modify DynamicInt class further to include an overloaded assignment operator (operator=)
            • Prevent self-assignment
            • Implement a deep copy in the assignment operator
        Demonstrate the assignment operation by assigning one object to another.
**********************************************************************************************/

// Include the necessary header files
#include <iostream>

// Include the DynamicInt class
#include "../headers/DynamicInt.hpp"

int main() {
    DynamicInt num1(5); // Create a DynamicInt object
    DynamicInt num2 = num1; // Copy the object using the assignment operator

    std::cout << "Original value: " << num1.get() << std::endl; // Print the original value
    std::cout << "Copied value(Using assignment operator): " << num2.get() << std::endl << std::endl; // Print the copied value

    std::cout << "Modifying the original value..." << std::endl << std::endl;
    num1.set(10); // Modify the original object

    std::cout << "Original value after modification: " << num1.get() << std::endl; // Print the original value
    std::cout << "Copied value after modification: " << num2.get() << std::endl; // Print the copied value

    return 0;
}

