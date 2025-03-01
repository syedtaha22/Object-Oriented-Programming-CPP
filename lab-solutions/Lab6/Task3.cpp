/******************************************************************************************************
    Task 3:
        Create a Dynamic Graphic Calculator that computes the perimeter of different
        geometric shapes using Object-Oriented Programming (OOP) principles. This task
        emphasizes function overloading, static_cast, dynamic_cast, static binding,
        and dynamic binding.

        Task Description
            Develop a Geometry Toolkit that calculates the perimeter of various geometric
            shapes. The system should:
                • Support multiple shapes, where each shape inherits from a common base
                  class
                • Use function overloading to implement multiple versions of a perimeter
                  calculation function
                • Allow polymorphic behavior, where all shapes are handled using base class
                  pointers
                • Implement type casting:
                    - Use static_cast when converting between known related types
                    - Use dynamic_cast to check and ensure safe conversion at runtime

        Geometric Shapes to Implement:
            • Circular Shape (e.g., Circle) - Requires a radius
                - Perimeter Formula: P = 2πr
            • Rectangular Shape (e.g., Rectangle) - Requires length and width
                - Perimeter Formula: P = 2(l + w)
            • Triangular Shape (e.g., Triangle) - Requires three sides
                - Perimeter Formula: P = a + b + c
            • Polygonal Shape (e.g., General Polygon) - Requires a variable number of sides
                - Perimeter Formula: Sum of all side lengths

        Requirements:
        • Define an Abstract Base Class (Shape)
            - Declare a pure virtual function for computing the perimeter
            - Ensure that every derived class must override this function
            - Include a virtual destructor for proper cleanup
        • Create Derived Classes (Circular, Rectangular, Triangular, Polygonal)
            - Each class inherits from Shape and implements computePerimeter()
            - Each class stores its own attributes (e.g., radius, length, width, etc.)
        • Use Polymorphism
            - Store different shapes in a base class pointer array/vector
            - Call computePerimeter() dynamically at runtime
        • Demonstrate Type Casting
            - Use static_cast for known, safe conversions between related types
            - Use dynamic_cast to check and safely downcast at runtime

        Bonus Challenge (Optional)
        Add a new shape (e.g., Trapezoid, Parallelogram) with its own perimeter function. Implement
        operator overloading to allow summing up perimeters of two shapes (e.g., shape1 + shape2).

        Use an STL container (vector) to store multiple shapes and compute total perimeter

******************************************************************************************************/

#include <iostream>
#include <vector>

class Shape {
public:
    virtual double computePerimeter() = 0;
    virtual ~Shape() {}

    // Overload + operator to sum perimeters of two shapes
    double operator+(Shape& s) { return computePerimeter() + s.computePerimeter(); }
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {
        std::cout << "Making a circle with radius " << r << std::endl;
    }

    double computePerimeter() override { return 2 * 3.14159 * radius; }
};

class Rectangle : public Shape {
    double length, width;
public:
    Rectangle(double l, double w) : length(l), width(w) {
        std::cout << "Making a rectangle with length " << l << " and width " << w << std::endl;
    }

    double computePerimeter() override { return 2 * (length + width); }
};

class Triangle : public Shape {
    double a, b, c;
public:
    Triangle(double sideA, double sideB, double sideC) : a(sideA), b(sideB), c(sideC) {
        std::cout << "Making a triangle with sides " << sideA << ", " << sideB << ", " << sideC << std::endl;
    }

    double computePerimeter() override { return a + b + c; }
};

class Polygon : public Shape {
    std::vector<double> sides;
public:
    Polygon(std::vector<double> s) : sides(s) {
        std::cout << "Making a polygon with sides: ";
        for (int i = 0; i < s.size() - 1; i++) {
            std::cout << s[i] << ", ";
        }
        std::cout << s[s.size() - 1];
        std::cout << std::endl;
    }

    double computePerimeter() override {
        double perimeter = 0;
        for (double side : sides) {
            perimeter += side;
        }
        return perimeter;
    }
};

class GeometryToolkit {
    std::vector<Shape*> shapes;
public:
    void addShape(Shape* shape) { shapes.push_back(shape); }

    void displayPerimeters() {
        for (int i = 0; i < shapes.size(); i++) {
            std::cout << "Shape " << i + 1 << " Perimeter: " << shapes[i]->computePerimeter() << std::endl;
        }
    }

    double totalPerimeter() {
        double total = 0;
        for (Shape* shape : shapes) {
            total += shape->computePerimeter();
        }
        return total;
    }

    Shape* get(int index) { return shapes[index]; }

};

int main() {
    GeometryToolkit toolkit;

    Circle circle(5);
    Rectangle rectangle(4, 6);
    Triangle triangle(3, 4, 5);
    Polygon polygon({ 2, 3, 4, 5 });

    toolkit.addShape(&circle);
    toolkit.addShape(&rectangle);
    toolkit.addShape(&triangle);
    toolkit.addShape(&polygon);

    // Show dynamic_cast example, by using get
    std::cout << std::endl;
    Circle* c = dynamic_cast<Circle*>(toolkit.get(0));
    if (c) {
        std::cout << "Successfully casted to Circle (Dynamic Cast)" << std::endl;
        std::cout << "Circle Perimeter: " << c->computePerimeter() << std::endl;
    }
    else std::cout << "Not a circle" << std::endl;
    std::cout << std::endl;

    // Show static_cast example, by using get
    Circle* c2 = static_cast<Circle*>(toolkit.get(1));
    std::cout << "Static Cast Rectangle to Circle" << std::endl;
    std::cout << "Circle Perimeter: " << c2->computePerimeter() << std::endl;
    std::cout << std::endl;

    toolkit.displayPerimeters();

    std::cout << "Total Perimeter: " << toolkit.totalPerimeter() << std::endl;

    return 0;
}