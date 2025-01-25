/********************************************************************************
    Task 3:
        Create a class Circle with:
            • A private member radius (float).
            • Public methods:
                1. setRadius(float r) to set the value of radius.
                2. getRadius() to return the value of radius.
                3. circumference() to calculate and return the circumference

        In main, create a Circle object, set the radius using setRadius(), and
        display its circumference.
********************************************************************************/

// Include the necessary header files
#include <iostream>

#include "../headers/Circle.hpp" // Include the Circle class

int main() {
    // Declare Circle object
    Circle circle;

    // Set the radius
    circle.setRadius(5.0);

    // Display the radius
    std::cout << "Radius of the circle: " << circle.getRadius() << std::endl;

    // Display the circumference
    std::cout << "Circumference of the circle: " << circle.circumference() << std::endl;

    return 0; // Exit
}