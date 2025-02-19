/***********************************************************************************************
    Task 3:
        Using your stack or queue implementation from Task 1 or Task 2, create a class that
        checks whether a given sequence of characters containing {, }, [, ], (, ) is balanced.

        A sequence is balanced if:
            1. Every opening bracket has a corresponding closing bracket.
            2. The brackets are closed in the correct order.

        Your class should have a function:
            • bool isBalanced(const std::string& s) → Returns true if the sequence is balanced,
              otherwise false.

        Write another class to generate test cases for the bracket checker. This class should
        have a function:
            • std::vector<std::string> generateTestCases(int n) → Returns a vector of n randomly
            generated bracket sequences.

        Use the test case generator to verify your balanced bracket checker. The generated test
        cases should include a mix of balanced and unbalanced sequences.
***********************************************************************************************/

#include <iostream>
#include <iomanip>

#include "Stack.hpp"
#include "TestCaseGenerator.hpp"

class BalancedBraces {
public:
    bool operator()(const std::string& expression) const {
        Stack braceStack;

        for (char c : expression) {
            if (c == '{' || c == '[' || c == '(') braceStack.push(c);
            else if (c == '}' || c == ']' || c == ')') {
                if (braceStack.isEmpty()) return false; // Unmatched closing brace

                char top = braceStack.pop();

                if ((c == '}' && top != '{') ||
                    (c == ']' && top != '[') ||
                    (c == ')' && top != '(')) return false; // Mismatched opening and closing braces
            }
        }
        return braceStack.isEmpty(); // Balanced if stack is empty
    }
};

int main() {

    std::vector<std::string> testCases = TestCaseGenerator()(20);

    std::cout << std::endl << std::setw(20) << std::left << "     Test Cases" << "|     Result" << std::endl;
    std::cout << "--------------------+-----------------" << std::endl;

    for (const std::string& testCase : testCases)
        std::cout << std::setw(20) << testCase << std::setw(5) << "|" <<
        (BalancedBraces()(testCase) ? "Balanced" : "Unbalanced") << std::endl;

    return 0;
}