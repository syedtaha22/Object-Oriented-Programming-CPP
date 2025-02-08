/****************************************************************************************************
    Task 2:
        Strings in C++ are commonly handled using std::string, but understanding how strings work
        internally helps reinforce memory management and operator overloading concepts.

        Implement a custom MyString class that supports fundamental string operations using dynamic
        memory allocation and operator overloading.

        You may not use string functions from the standard library (e.g., strcpy, strlen, strcmp, etc.).

        Required Methods:
            • MyString(const char* str): Constructor to initialize a string from a character array.
            • MyString operator+(const MyString& other): Overload + to concatenate two strings.
            • bool operator==(const MyString& other): Overload == to compare two strings for equality.
            • void operator=(const MyString& other): Overload = to assign one string to another,
              ensuring proper memory management.
            • char operator[](int index): Overload [] to access a character at a given index.
            • void display(): Prints the string.

        Write a main function that demonstrates the functionality of the MyString class, ensuring
        all overloaded operators are tested effectively.
****************************************************************************************************/

#include <iostream>

class MyString {
    char* str;
    size_t length;

public:

    MyString(const char* str) {
        length = 0;
        while (str[length] != '\0') length++;
        this->str = new char[length + 1];
        for (size_t i = 0; i < length; i++) this->str[i] = str[i];
        this->str[length] = '\0';
    }

    MyString operator+(const MyString& other) {
        char* newStr = new char[length + other.length + 1];
        for (size_t i = 0; i < length; i++) newStr[i] = str[i];
        for (size_t i = 0; i < other.length; i++) newStr[length + i] = other.str[i];
        newStr[length + other.length] = '\0';
        return MyString(newStr);
    }

    bool operator==(const MyString& other) const {
        if (length != other.length) return false;
        for (size_t i = 0; i < length; i++) {
            if (str[i] != other.str[i]) return false;
        }
        return true;
    }

    void operator=(const MyString& other) {
        delete[] str;
        length = other.length;
        str = new char[length + 1];
        for (size_t i = 0; i < length; i++) str[i] = other.str[i];
        str[length] = '\0';
    }

    char operator[](size_t index) {
        return str[index];
    }

    void display() {
        std::cout << str << std::endl;
    }

    size_t size() {
        return length;
    }

    ~MyString() {
        delete[] str;
    }
};

int main() {
    MyString str1 = "Hello";
    MyString str2 = "World";
    MyString str3 = str1 + " " + str2;

    std::cout << "str1: "; str1.display();
    std::cout << "str2: "; str2.display();
    std::cout << "str3: "; str3.display();

    std::cout << "Are str1 and str2 equal? " << (str1 == str2) << std::endl;
    std::cout << "Are str1 and str1 equal? " << (str1 == str1) << std::endl;

    std::cout << "Copying str2 to str1..." << std::endl;
    str1 = str2;
    std::cout << "str1: "; str1.display();

    for (size_t i = 0; i < str1.size(); i++) {
        std::cout << "str1[" << i << "] = " << str1[i] << std::endl;
    }

    return 0;
}