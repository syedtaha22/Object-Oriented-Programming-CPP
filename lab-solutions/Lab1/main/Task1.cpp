/******************************************************************
    Task 1:
        Write a structure called Student with the following members:
            • name (string)
            • ERP (int)
            • grade (char)
        Write a main function to:
            1. Create a Student object.
            2. Input values for the members.
            3. Print the values.
******************************************************************/

// Include the necessary header files
#include <iostream>

#include "../headers/Student.hpp" // Include the Student structure

int main() {
    // Declare Student object
    Student student;

    // Input values for the members
    std::cout << "Enter student's name: ";
    std::getline(std::cin, student.name);
    std::cout << "Enter student's ERP: ";
    std::cin >> student.erp;
    std::cout << "Enter student's grade: ";
    std::cin >> student.grade;

    // Print the values
    std::cout << "\nStudent's name: " << student.name << std::endl;
    std::cout << "Student's age: " << student.erp << std::endl;
    std::cout << "Student's grade: " << student.grade << std::endl;

    return 0; // Exit
}