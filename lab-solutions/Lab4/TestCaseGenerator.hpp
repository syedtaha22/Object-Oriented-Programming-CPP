#ifndef TEST_CASEGENERATOR_HPP
#define TEST_CASEGENERATOR_HPP

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

#include "Stack.hpp"

class TestCaseGenerator {
private:
    const std::string brackets = "{}[]()";

    // Generates a random balanced bracket sequence
    std::string generateBalanced(int length) {
        std::string result;
        Stack stk;

        for (int i = 0; i < length / 2; ++i) {
            char open = brackets[(rand() % 3) * 2]; // Pick a random opening bracket
            result += open;
            stk.push(open);
        }

        while (!stk.isEmpty()) {
            char open = stk.pop();
            char close = (open == '(') ? ')' : (open == '[') ? ']' : '}';
            result += close;
        }
        return result;
    }

    // Generates a random unbalanced bracket sequence
    std::string generateUnbalanced(int length) {
        std::string result;
        for (int i = 0; i < length; ++i) result += brackets[rand() % 6]; // Pick a random bracket
        return result;
    }

public:
    // Generates n test cases with a given percentage of balanced cases
    std::vector<std::string> operator()(int n, double balancedPercentage = 0.5) {
        std::vector<std::string> testCases;
        int balancedCount = static_cast<int>(n * balancedPercentage);
        int unbalancedCount = n - balancedCount;

        for (int i = 0; i < n; i++) {
            // Get a random boolean to check if this should be balanced or not
            bool balanced = (rand() % 100) < (balancedPercentage * 100);

            // Ensure even length for balanced sequences
            int length = (balanced) ? (rand() % 10) * 2 : (rand() % 20);
            std::string testCase = (balanced) ? generateBalanced(length) : generateUnbalanced(length);
            testCases.push_back(testCase);
        }
        return testCases;
    }

};

#endif  // TEST_CASEGENERATOR_HPP