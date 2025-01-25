
#include "../headers/Circle.hpp"

// Method to calculate and return the circumference
float Circle::circumference() {
    return 2 * 3.14159 * radius;
}

// Method to set the radius
void Circle::setRadius(float r) {
    radius = r;
}

// Method to get the radius
float Circle::getRadius() {
    return radius;
}

