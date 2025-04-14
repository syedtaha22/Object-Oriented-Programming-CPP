/**
 * @file Task3.cpp
 * @brief Task 3: Implement a Variadic Logger Utility
 *
 * @details
 * Implement a class Logger that acts as a simple debugging utility. This class should accept
 * and print a varying number of arguments of any type, separated by spaces. The implementation
 * should make use of variadic templates and recursion.
 *s
 * The purpose of this task is to provide a utility that simplifies debugging by allowing the
 * user to log multiple values in a clean and extensible manner without needing to manually
 * insert multiple std::cout statements.
 *
 * Requirements:
 *  - Define a class Logger with the following members:
 *   - A base case function to terminate recursion and print a newline.
 *   - A recursive variadic template function that takes any number of arguments and prints them
 *     to the console.
 *   - An operator() overload to use the logger in function-call style: logger(1, "text", 4.2).
 *  - Demonstrate the logger with at least 5 different types.
 *  - Draw the recursion tree based on the function call logger(1, 2, "Hi", 's', 5.0f). The tree
 *    should show each function call, the outputs, and the remaining arguments at each stage.
 *    (Write this in comments)
 *
 * Recursion Tree Example Format:
 *
 * (1) logger(1, 2, "Hi", 's', 5.0f) -------------------------- 1
 *     └── (2) logger(2, "Hi", 's', 5.0f) --------------------- 1 2
 *             └── (3) logger("Hi", 's', 5.0f)  --------------- 1 2 Hi
 *                     └── (4) logger('s', 5.0f) -------------- 1 2 Hi s
 *                             └── (5) logger(5.0f) ----------- 1 2 Hi s 5.0
 *                                     └── (6) logger() ------- 1 2 Hi s 5.0\n
 *
 */

#include<iostream>


 /**
  * @class Logger
  * @brief A simple logger utility that prints multiple arguments to the console.
  *
  * This class uses variadic templates and recursion to handle a varying number of arguments
  * of any type. It provides a clean and extensible way to log messages for debugging purposes.
  */
class Logger {
private:
    /**
     * @brief Base case for the recursive logging function.
     */
    void log() { std::cout << std::endl; }

    /**
     * @brief Recursive variadic function to log multiple arguments.
     * @param first The first argument to log.
     * @param args The remaining arguments to log.
     */
    template<typename T, typename... Args>
    void log(T first, const Args&... args) {
        std::cout << first << " ";
        log(args...);
    }

public:
    /**
     * @brief Overloaded function call operator to use the logger in a function-call style.
     * @param args The arguments to log.
     */
    void operator()(const auto&... args) {
        log(args...); // Call the variadic log function
    }

};

int main() {
    Logger log;
    log(1, 2, "Hi", 's', 5.0f); // Example usage of the logger
    return 0;
}
