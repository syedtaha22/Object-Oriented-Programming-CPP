/*********************************************************************************************************************
 * Task 1:
 *      You are provided with a list of elements containing information about their name, symbol, and atomic number.
 *      Utilize functors and STL algorithms to achieve the following:
 *          • Sort: Create a custom functor to sort the elements based on two criteria:
 *              o Primary: Atomic number (ascending order)
 *              o Secondary: Element name (alphabetical order)
 *          • Count: After sorting, determine the number of elements with names longer than 5 characters using a
 *            custom filter functor.
 *          • Transform: Create a new list containing the element symbols transformed to uppercase using a lambda
 *            function.
 *
 *      Task Instructions:
 *          1. Complete the main function by initializing the elements vector with your desired element data (name,
 *             symbol, atomic number).
 *          2. Implement the logic to process the sorted elements, long name count, and uppercase symbols as needed.
 *          3. Modify the code to allow users to specify a custom minimum atomic number for filtering elements
 *             during sorting
 **********************************************************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct Element {
    std::string name;
    std::string symbol;
    size_t atomicNumber;


    // Overload << operator for easy printing
    friend std::ostream& operator<<(std::ostream& os, const Element& element) {
        os << element.name << " (" << element.symbol << ", " << element.atomicNumber << ")";
        return os;
    }

};

struct SortByAtomicNumberAndName {
    bool operator()(const Element& a, const Element& b) const {
        if (a.atomicNumber != b.atomicNumber) {
            return a.atomicNumber < b.atomicNumber; // Primary sort by atomic number
        }
        return a.name < b.name; // Secondary sort by name
    }
};

struct LongNameFilter {
    size_t minLength;
    LongNameFilter(size_t length) : minLength(length) {}

    bool operator()(const Element& element) const {
        return element.name.length() > minLength; // Filter by name length
    }
};


// Helper function to print vector of elements
template<typename T>
void print(const std::string& title, const std::vector<T>& items) {
    std::cout << title << "\n";
    std::for_each(items.begin(), items.end(), [](const T& item) {std::cout << item << "\n";});
    std::cout << "\n";
}


int main() {
    std::vector<Element> elements = {
        {"Lithium", "Li", 3},
        {"Nitrogen", "N", 7},
        {"Neon", "Ne", 10},
        {"Beryllium", "Be", 4},
        {"Fluorine", "F", 9},
        {"Helium", "He", 2},
        {"Oxygen", "O", 8},
        {"Boron", "B", 5},
        {"Hydrogen", "H", 1},
        {"Carbon", "C", 6},
    };

    print("Original Elements:", elements);

    // Sort elements using custom functor
    std::sort(elements.begin(), elements.end(), SortByAtomicNumberAndName());
    print("Sorted Elements:", elements);


    // Get minimum atomic number from user
    size_t minAtomicNumber = 5; // Custom minimum atomic number for filtering

    // Filter elements based on atomic number
    std::vector<Element> filteredElements;
    std::copy_if(elements.begin(), elements.end(), std::back_inserter(filteredElements),
        [minAtomicNumber](const Element& e) {
            return e.atomicNumber >= minAtomicNumber;
        });

    // Print filtered elements
    print("Filtered Elements(Atomic Number >= " + std::to_string(minAtomicNumber) + "):", filteredElements);


    // Count elements with names longer than a specified length
    size_t minLength = 5; // Custom minimum length for filtering
    LongNameFilter filter(minLength);
    size_t longNameCount = std::count_if(elements.begin(), elements.end(), filter);
    std::cout << "\nNumber of elements with names longer than " << minLength << ": " << longNameCount << "\n\n";

    // Transform symbols to uppercase using a lambda function
    std::vector<std::string> uppercaseSymbols;
    std::transform(elements.begin(), elements.end(), std::back_inserter(uppercaseSymbols),
        [](const Element& element) {
            std::string upperSymbol = element.symbol;
            std::transform(upperSymbol.begin(), upperSymbol.end(), upperSymbol.begin(), ::toupper);
            return upperSymbol;
        });
    print("Uppercase Symbols:", uppercaseSymbols);


    return 0;
}