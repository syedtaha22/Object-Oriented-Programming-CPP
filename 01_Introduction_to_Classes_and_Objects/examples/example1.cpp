/*
    Simple Structure to store the coordinates of a point
*/

#include <iostream>

struct Point {
    int x;
    int y;
};

int main() {
    Point p1 = { 10, 20 }; // Initialize the structure
    std::cout << "Point coordinates: (" << p1.x << ", " << p1.y << ")" << std::endl;

    return 0;
}
