/**
 * @file Task4.cpp
 * @brief Task 4: Implement a Generic Data Transformation Pipeline
 *
 * @details
 * Design a generic class that represents a data transformation pipeline. The pipeline should allow the user to
 * sequentially apply a series of transformation functions to an input value. Each function in the pipeline should
 * take a value of type T and return a value of the same type T.
 *
 * The pipeline class must allow:
 *  - Adding transformation functions one by one.
 *  - Executing all added functions in order on an input value.
 *  - Returning the final result after all transformations have been applied.
 *
 * You should demonstrate the pipeline with multiple transformation functions applied to at least 2 different datatypes,
 * and show how the result evolves step by step.
 */

#include <iostream>
#include <vector>

template<typename T>
class Pipeline {
    std::vector<T(*)(const T&)> functions; // Vector to store transformation functions
public:

    /**
     * @brief Adds a transformation function to the pipeline
     * @param func Pointer to the transformation function
     */
    void add(T(*func)(const T&)) {
        functions.push_back(func); // Add function to the pipeline
    }

    /**
     * @brief Executes all transformation functions in the pipeline on the input value
     * @param input The input value to be transformed
     * @param verbose If true, prints intermediate results
     * @return The final transformed value after applying all functions
     */
    T run(const T& input, bool verbose = false) {
        T result = input; // Initialize result with input value
        if (verbose) std::cout << "[Pipeline] Initial value: " << result << std::endl;
        for (auto& func : functions) {
            result = func(result); // Apply each function in the pipeline
            if (verbose) std::cout << "[Pipeline] After applying function: " << result << std::endl;
        }
        return result; // Return final result after all transformations
    }

};

// Example transformation functions
int addOne(const int& x) { return x + 1; }
int multiplyByTwo(const int& x) { return x * 2; }
int square(const int& x) { return x * x; }


std::string toUpperCase(const std::string& str) {
    std::string strCopy = str; // Create a copy of the input string
    for (auto& c : strCopy) c = toupper(c); // Convert string to uppercase
    return strCopy; // Return the modified string
}

std::string appendExclamation(const std::string& str) {
    return str + "!"; // Append exclamation mark to string
}

int main() {
    // Create a pipeline for integers
    Pipeline<int> intPipeline;
    intPipeline.add(addOne); // Add transformation functions to the pipeline
    intPipeline.add(multiplyByTwo);
    intPipeline.add(square);
    int resultInt = intPipeline.run(5, true); // Run the pipeline with input value 5 and verbose output
    std::cout << "Final result (int): " << resultInt << "\n\n"; // Output: 12

    // Create a pipeline for strings
    Pipeline<std::string> stringPipeline;
    stringPipeline.add(toUpperCase); // Add transformation functions to the pipeline
    stringPipeline.add(appendExclamation);
    std::string resultString = stringPipeline.run("hello", true); // Run the pipeline with input value "hello" and verbose output
    std::cout << "Final result (string): " << resultString << std::endl; // Output: HELLO!

    return 0;
}


