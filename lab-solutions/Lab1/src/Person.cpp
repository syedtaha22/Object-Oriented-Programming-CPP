#include <iostream> 

#include "../headers/Person.hpp"

// Constructor to initialize name and age
Person::Person(std::string _name, int _age) : name(_name), age(_age) {}

// Function to print the details of a Person object
void Person::print() {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
}
