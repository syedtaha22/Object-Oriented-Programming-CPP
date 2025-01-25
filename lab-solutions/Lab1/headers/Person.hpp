#ifndef PERSON_HPP
#define PERSON_HPP

#include <string> // For std::string

// Define the Person class
class Person {
    std::string name; // Private member
    int age; // Private member

public:
    // Constructor to initialize name and age
    Person(std::string _name, int _age);

    // Function to print the details of a Person object
    void print();

};

#endif // PERSON_HPP