/**********************************************************************************
    Task 2:
        Define a class called Rectangle with the following:
            • Two public members length and width (both int).
            • A public method area() that calculates and returns the area.
        In main, create a Rectangle object, set its dimensions, and display its area.
**********************************************************************************/

// Include the necessary header files
#include <iostream>

#include "../headers/Rectangle.hpp" // Include the Rectangle class

int main() {
    // Declare Rectangle object
    Rectangle rectangle;

    // Set the dimensions
    rectangle.length = 10;
    rectangle.width = 5;

    // Display the dimensions
    std::cout << "Length of the rectangle: " << rectangle.length << std::endl;
    std::cout << "Width of the rectangle: " << rectangle.width << std::endl;

    // Display the area
    std::cout << "Area of the rectangle: " << rectangle.area() << std::endl;

    return 0; // Exit
}