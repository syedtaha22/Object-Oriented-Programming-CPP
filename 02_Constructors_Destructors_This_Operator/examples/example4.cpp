#include <iostream>
#include <fstream>
#include <string>

class FileHandler {
public:
    std::fstream file;

    // Constructor to open a file
    FileHandler(const std::string& filename) {
        file.open(filename, std::ios::out);
        if (file.is_open()) {
            std::cout << "File opened successfully.\n";
        }
    }

    // Destructor to close the file
    ~FileHandler() {
        if (file.is_open()) {
            file.close();
            std::cout << "File closed successfully.\n";
        }
    }

    void write(const std::string& text) {
        if (file.is_open()) {
            file << text;
        }
    }
};

int main() {
    FileHandler file("hello.txt");
    file.write("Hello, World!"); // Writes to the file
    // Destructor will automatically close the file when the object goes out of scope
}
