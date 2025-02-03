#include <iostream>

class Person {
public:
    std::string name;

    // Constructor
    Person(std::string n) : name(n) {}

    // Overloading the assignment operator
    Person& operator=(const Person& other) {
        if (this != &other) {
            name = other.name;  // Custom copy logic
        }
        return *this;
    }

    void display() {
        std::cout << "Name: " << name << std::endl;
    }
};

int main() {
    Person person1("Alice");
    Person person2("Bob");

    person2 = person1; // Assignment operator is called

    person1.display(); // Output: Name: Alice
    person2.display(); // Output: Name: Alice
}
