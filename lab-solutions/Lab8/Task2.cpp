/**
 * @file Task2.cpp
 * @brief Task 2: Recursive Transformation of Vector Elements
 *
 * @details
 * Create a recursive function that transforms each element of a given vector by applying a transformation function.
 * The function should:
 *  - Take two parameters:
 *      - A constant reference to a vector of integers.
 *      - A pointer to a transformation function (int -> int).
 *  - Return a new vector where each element is the result of applying the transformation function to the corresponding element of the input vector.
 *  - Use recursion for the transformation, without using loops.
 *  - Avoid modifying the input vector. Return a new vector to maintain immutability.
 *  - Ensure the function is pure, with no side effects (e.g., no modification of external variables, printing to console etc).
 *  - Do not use any STL algorithms or built-in functions (e.g., std::transform).
 *
 * @note Test the function with different transformation functions and vectors of varying sizes.
 */

#include <iostream>
#include <vector>

std::vector<int> transformVector(const std::vector<int>& vec,
    int (*transformFunc)(int), size_t index = 0) {

    // Base case: if the index is equal to the size of the vector, return an empty vector
    if (index == vec.size()) return std::vector<int>();

    // Recursive case: transform the current element and combine it with the transformed rest of the vector
    std::vector<int> transformedRest = transformVector(vec, transformFunc, index + 1);
    transformedRest.insert(transformedRest.begin(), transformFunc(vec[index]));

    return transformedRest;
}

void print(const std::vector<int>& vec) {
    for (int val : vec) std::cout << val << " ";
    std::cout << std::endl;
}

int doubleValue(int x) { return x * 2; }
int squareValue(int x) { return x * x; }

int main() {
    std::vector<int> vec = { 1, 2, 3, 4, 5 };
    std::cout << "Original Vector: ";
    print(vec);

    std::vector doubledVec = transformVector(vec, doubleValue);
    std::cout << "Doubled Vector: ";
    print(doubledVec);

    std::vector<int> squaredVec = transformVector(vec, squareValue);
    std::cout << "Squared Vector: ";
    print(squaredVec);

    return 0;
}

/***************** Better Implementation *****************

class transformVector {
private:
    std::vector<int> _transform(const std::vector<int>& vec, int (*transformFunc)(int), size_t index) {
        if (index == vec.size()) return std::vector<int>();
        std::vector<int> transformedRest = _transform(vec, transformFunc, index + 1);
        transformedRest.insert(transformedRest.begin(), transformFunc(vec[index]));
        return transformedRest;
    }

public:
    std::vector<int> operator()(const std::vector<int>& vec, int (*transformFunc)(int)) {
        return _transform(vec, transformFunc, 0);
    }
};

*********************************************************/