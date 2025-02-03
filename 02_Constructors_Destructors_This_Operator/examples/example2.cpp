#include <iostream>

class Book {
public:
    std::string title;
    int pages;

    // Constructor
    Book(std::string t, int p) : title(t), pages(p) {}

    // Copy Constructor
    Book(const Book& other) {
        title = other.title;
        pages = other.pages;
        std::cout << "Copy constructor called\n";
    }

    void display() {
        std::cout << "Title: " << title << ", Pages: " << pages << std::endl;
    }
};

int main() {
    Book book1("C++ Programming", 500);
    Book book2 = book1; // Copy constructor is called

    book1.display(); // Output: Title: C++ Programming, Pages: 500
    book2.display(); // Output: Title: C++ Programming, Pages: 500
}
