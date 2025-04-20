/*********************************************************************************************************************
 * Task 2
 *      This lab task focuses on checking if an expression contains balanced opening and closing braces ({ and }).
 *      Utilize a custom functor and STL algorithms to achieve this. Create a custom functor named BalancedBraces
 *      that takes a string expression as input and returns true if the expression contains balanced opening and
 *      closing braces ({ and }), and false otherwise.
 *
 *      Task Instructions:
 *          1. Implement the operator() function within the BalancedBraces functor.
 *          2. Inside the operator function, iterate through the characters of the expression string.
 *          3. Maintain a counter for opening and closing braces.
 *          4. Increment the opening brace counter for each encountered '{' and decrement the closing brace counter
 *             for each encountered '}'.
 *          5. If a closing brace is encountered but the opening brace counter is zero, the expression is unbalanced.
 *          6. Return true if the expression ends with balanced counters (both zero) and false otherwise.
 *
 *********************************************************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>

class BalancedBraces {
public:
    bool operator()(const std::string& expression) const {
        int openBraces = 0;
        int closeBraces = 0;

        for (char ch : expression) {
            if (ch == '{') openBraces++;
            else if (ch == '}') {
                closeBraces++;
                if (closeBraces > openBraces) return false; // More closing braces than opening braces
            }
        }

        return openBraces == closeBraces; // Check if both counters are equal
    }
};

int main() {
    std::vector<std::string> expressions = {
        "{a + b} * {c - d}",
        "{a + b * {c - d}}",
        "{a + b * {c - d}}}",
        "{{a + b} * {c - d}}",
        "{a + b * {c - d}}{e + f}",
        "a + b * c - d",
        "{a + b * c - d}",
        "}{a + b * c - d}{"
    };

    BalancedBraces checkBalancedBraces;

    std::for_each(expressions.begin(), expressions.end(),
        [&](const std::string& expression) {
            bool isBalanced = checkBalancedBraces(expression);
            std::cout << "Expression: \"" << expression << "\" is " << (isBalanced ? "balanced" : "not balanced") << "\n";
        });

    return 0;
}