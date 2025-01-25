#ifndef CIRCLE_HPP
#define CIRCLE_HPP

// Define the Circle class
class Circle {
    float radius; // Private member

public:
    // Method to set the radius
    void setRadius(float r);

    // Method to get the radius
    float getRadius();

    // Method to calculate and return the circumference
    float circumference();
};

#endif // CIRCLE_HPP