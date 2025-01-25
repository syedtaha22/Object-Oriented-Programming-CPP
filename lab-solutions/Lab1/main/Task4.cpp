/*********************************************************************************
    Task 4:
        Create a class Person with:
            • Private members name (string) and age (int)
            • A constructor that takes two arguments to initialize name and age.
            • A public method print() that displays the details of the Person object.

        In the main function, create a Person object, and use the print() method
        to display the details.
*********************************************************************************/

// Include the necessary header files
#include <iostream>
#include <string> 

#include "../headers/Person.hpp" // Include the Person class

int main() {
    // Declare Person object using the constructor
    Person person("Alice", 25);

    // Display the details using the overloaded << operator
    person.print();

    return 0; // Exit
}