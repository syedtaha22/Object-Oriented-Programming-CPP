/*****************************************************************************************
    Task 1:
        Create a class Person with two protected attributes: name and age.
        Implement a constructor that initializes these attributes.

        Then, create a class Student that publicly inherits from Person and adds an int
        attribute studentID. Implement a constructor in Student that initializes all
        attributes. Add a display() function in Student that prints the name, age, and
        studentID. In the main() function, create a Student object and call display().

        After implementing the program, answer the following questions:
            1) Why must name and age be protected instead of private?
            2) If name and age were private, how would it affect Student?
            3) What happens if Student inherits Person privately instead of publicly?
*****************************************************************************************/

#include <iostream>

class Person {
protected:
    /**********************************************************************************
        Make nane and age protected so that they can be accessed by the derived class.
        If they were private, they would not be accessible by the derived class.
    **********************************************************************************/
    std::string name;
    int age;

public:
    Person(const std::string& name, int age) : name(name), age(age) {}
};

/****************************************************************************************
    If the Student class inherits Person privately, the public and protected members of
    the base class become private members of the derived class. This means that the
    derived class can access the members of the base class, but the outside world cannot
    access the members of the derived class.
****************************************************************************************/
class Student : public Person {
private:
    int studentID;

public:
    Student(const std::string& name, int age, int studentID) :
        Person(name, age), studentID(studentID) {
    }

    void display() const {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "Student ID: " << studentID << std::endl;
    }
};

int main() {
    Student student("Syed Taha", 20, 12345); // Creating Student object
    student.display();

    return 0;
}
