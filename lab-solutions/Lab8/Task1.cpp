/**
 * @file Task1.cpp
 * @brief Task 1: Implement a Simple Stack Class
 *
 * @details
 * Create a class template Stack that simulates a stack data structure. Implement the
 * following methods:
 *  - `push(T value)` – Adds an element to the top of the stack.
 *  - `pop()` – Removes the top element of the stack.
 *  - `top()` – Returns the top element without removing it.
 *  - `isEmpty()` – Checks if the stack is empty.
 *  - `size()` – Returns the number of elements in the stack.
 *
 * @note Test your stack with int, double, and std::string types.
 */

#include <iostream>


template <typename T>
struct Node {
    T data;         ///< Data stored in the node
    Node* next;     ///< Pointer to the next node in the stack

    /**
     * @brief Constructor for the Node
     * @param value Value to be stored in the node
     */
    Node(T value) : data(value), next(nullptr) {}
};


template <typename T>
class Stack {
private:
    Node<T>* topNode;   ///< Pointer to the top node of the stack
    int stackSize;      ///< Size of the stack
public:

    /**
     * @brief Constructor for the Stack
     */
    Stack() : topNode(nullptr), stackSize(0) {}

    /**
     * @brief Destructor for the Stack
     * @details Cleans up all nodes in the stack to prevent memory leaks.
     */
    ~Stack() { while (!isEmpty()) pop(); }


    /**
     * @brief Pushes a value onto the stack
     * @param value Value to be pushed onto the stack
     */
    void push(T value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = topNode;
        topNode = newNode;
        stackSize++;
    }

    /**
     * @brief Pops the top value from the stack
     * @details Removes the top element from the stack. If the stack is empty, it prints an error message.
     */
    void pop() {
        if (isEmpty()) {
            std::cerr << "Stack is empty. Cannot pop." << std::endl;
            return;
        }
        Node<T>* temp = topNode;
        topNode = topNode->next;
        delete temp;
        stackSize--;
    }

    /**
     * @brief Returns the top value of the stack
     * @return The top value of the stack
     * @throws std::runtime_error if the stack is empty
     */
    T top() {
        if (isEmpty()) {
            std::cerr << "Stack is empty. No top element." << std::endl;
            throw std::runtime_error("Stack is empty.");
        }
        return topNode->data;
    }

    /**
     * @brief Checks if the stack is empty
     * @return True if the stack is empty, false otherwise
     */
    bool isEmpty() { return stackSize == 0; }

    /**
     * @brief Returns the size of the stack
     * @return The number of elements in the stack
     */
    int size() { return stackSize; }

    /**
     * @brief Prints the elements of the stack
     * @details Prints the elements from top to bottom.
     */
    void printStack() {
        Node<T>* current = topNode;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    Stack<int> intStack;
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);
    std::cout << "Int Stack: ";
    intStack.printStack(); // Output: 3 2 1

    Stack<double> doubleStack;
    doubleStack.push(1.1);
    doubleStack.push(2.2);
    doubleStack.push(3.3);
    std::cout << "Double Stack: ";
    doubleStack.printStack(); // Output: 3.3 2.2 1.1

    Stack<std::string> stringStack;
    stringStack.push("Hello");
    stringStack.push("World");
    std::cout << "String Stack: ";
    stringStack.printStack(); // Output: World Hello

    return 0;
}