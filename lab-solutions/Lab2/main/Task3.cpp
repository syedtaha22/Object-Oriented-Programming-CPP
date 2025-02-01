/*****************************************************************************************************
    Task 3:
        C++ provides shared pointers as part of the std::shared_ptr class, which helps manage
        dynamically allocated objects. The key feature of a shared pointer is that multiple
        shared pointers can point to the same object. The object is only deleted when the last
        shared pointer goes out of scope, preventing memory leaks and ensuring proper cleanup.

        Task:
        You need to implement a simplified version of a shared pointer in a class called
        SharedIntPointer. Your class should:

            •	Manage a dynamically allocated int.
            •	Keep track of how many SharedIntPointer objects are pointing to the same integer.
            •	Automatically delete the integer when the last pointer goes out of scope.
            •	Provide the following methods:
                o	int get(): Returns the stored integer value.
                o	void set(int value): Updates the stored integer value.
                o	int getRefCount(): Returns the number of shared pointers pointing to the object.

        Restriction: You may NOT use the static keyword

        Hint: Think about whether you need a deep copy or a shallow copy when handling assignments
        and copies.
*****************************************************************************************************/


// Include the necessary header files
#include <iostream>

// Include the SharedIntPointer class
#include "../headers/SharedIntPointer.hpp"

int main() {
    std::cout << "Making Shared Pointer 1 with value 5" << std::endl;
    SharedIntPointer num1(5); // Create a SharedIntPointer object

    std::cout << "Making Shared Pointer 2 by copying Shared Pointer 1" << std::endl;
    SharedIntPointer num2 = num1; // Copy the object using the assignment operator

    {
        std::cout << "Making Shared Pointer 3 by copying Shared Pointer 1" << std::endl;
        SharedIntPointer num3 = num1; // Copy the object using the assignment operator


        std::cout << "Value of Pointer 1: " << num1.get() << std::endl; // Print the original value
        std::cout << "Modifying the value using Pointer 1" << std::endl;
        num1.set(10); // Modify the original object

        std::cout << "Value of Pointer 1 after modification: " << num1.get() << std::endl; // Print the original value
        std::cout << "Value of Pointer 2 after modification: " << num2.get() << std::endl; // Print the copied value

        std::cout << "Reference Count through Pointer 1: " << num1.getRefCount() << std::endl; // Print the reference count
    }

    std::cout << "Reference Count through Pointer 2 after Pointer 3 goes out of scope: " << num2.getRefCount() << std::endl; // Print the reference count
    std::cout << "Value of Pointer 1 after Pointer 3 goes out of scope: " << num1.get() << std::endl; // Print the original value

    return 0;
}