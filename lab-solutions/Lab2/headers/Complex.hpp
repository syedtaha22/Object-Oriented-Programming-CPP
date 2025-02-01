#ifndef COMPLEX_HPP
#define COMPLEX_HPP

class Complex {
    double real;
    double imag;
public:
    Complex(double r, double i);

    friend Complex addComplex(Complex c1, Complex c2);

    void display();
};

#endif // COMPLEX_HPP