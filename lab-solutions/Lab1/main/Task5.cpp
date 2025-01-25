/*********************************************************************************************
    Task 5:
        Create a class InstanceCounter with:
            1.	A private static member variable count that tracks the number of instances
                of the class.
            2.	A constructor that increments count whenever a new object is created.
            3.	A public static method getCount() that returns the current value of count.

        In the main function, create multiple objects of the class, and use getCount()
        method to print how many objects have been created.
**********************************************************************************************/

// Include the necessary header files
#include <iostream>

#include "../headers/InstanceCounter.hpp" // Include the InstanceCounter class


int main() {
    // Create multiple objects of the class
    InstanceCounter obj1;
    InstanceCounter obj2;
    InstanceCounter obj3;

    // Print how many objects have been created
    std::cout << "Number of instances created: " << InstanceCounter::getCount() << std::endl;

    return 0; // Exit
}