#include <iostream>

#include "../headers/Complex.hpp"

Complex::Complex(double r, double i) : real(r), imag(i) {}

void Complex::display() {
    std::cout << real << " + " << imag << "i" << std::endl;
}

Complex addComplex(Complex c1, Complex c2) {
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}