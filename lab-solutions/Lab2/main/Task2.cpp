/*********************************************************************************************************
    Task 2:
        Create a class Complex to represent complex numbers. Implement a friend function to
        add two complex numbers and return the result.

            • The class should have two private attributes: real and imag (for real and imaginary parts).
            • Implement a friend function addComplex(Complex, Complex) that takes two Complex objects
              and returns their sum as a new Complex object.
            • Display the result using a display() method.
*********************************************************************************************************/

// Include the necessary header files
#include <iostream>

// Include the Complex class
#include "../headers/Complex.hpp"


int main() {
    Complex c1(3.0, 4.0); // Create a Complex object
    Complex c2(1.0, 2.0); // Create another Complex object

    // Display the complex numbers
    std::cout << "Complex number 1: "; c1.display();
    std::cout << "Complex number 2: "; c2.display();

    Complex sum = addComplex(c1, c2); // Add the two complex numbers

    std::cout << "Sum of the complex numbers: "; sum.display(); // Display the sum

    return 0;
}