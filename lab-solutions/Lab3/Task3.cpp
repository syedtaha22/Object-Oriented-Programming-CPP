/**************************************************************************************************
    Task 3:
        A logging system is used to keep track of events, errors, or general information within
        a program. A Logger class can be designed to provide multiple ways to log messages using
        function overloading. The class should support logging messages in different ways:
            • Simply printing a message.
            • Printing a message with a severity level.
            • Writing a message to a file.

        Implement a Logger class with three overloaded log functions:
            • log(std::string message): Prints a simple message.
            • log(std::string message, int level): Prints a message along with a severity level.
            • log(std::string message, std::string filename): Writes a message to a specified file.

        When logging to a file, the program should:
            • Open the file in append mode (std::ofstream).
            • Write the message to the file.
            • Close the file after writing.

        For example, if "log.txt" is given as the filename, the log should be stored in that file
        without overwriting existing content.
**************************************************************************************************/

#include <iostream>
#include <fstream>
#include <string>

class Logger {
public:
    void log(std::string message) {
        std::cout << message << std::endl;
    }

    void log(std::string message, int level) {
        std::cout << "Level " << level << ": " << message << std::endl;
    }

    void log(std::string message, std::string filename) {
        std::ofstream file(filename, std::ios::app);
        file << message << std::endl;
        file.close();
    }
};

int main() {
    Logger logger;
    logger.log("Information message");
    logger.log("Critical error", 5);
    logger.log("Something went wrong while processing data", "logs.txt");

    return 0;
}