/******************************************************************************************************
    Task 1:
        Implement an efficient stack data structure that supports the following operations in O(1)
        time:
            • push(x) → Inserts x onto the stack.
            • pop() → Removes the top element from the stack, and returns it.
            • top() → Returns the top element of the stack without removing it.

        Additionally, Implement size() to return the number of elements in the stack and isEmpty()
        to check whether the stack is empty.

        You are free to choose the implementation method (dynamic array or linked list), but you
        must justify your choice in comments.
******************************************************************************************************/

#ifndef STACK_HPP
#define STACK_HPP


#include <iostream>

class Stack {
private:
    struct Node {
        char data;
        Node* next;

        Node(char x) : data(x), next(nullptr) {}
        Node() : data(0), next(nullptr) {}
    };

    Node* topNode;
    int size;
public:
    Stack() {
        topNode = nullptr;
        size = 0;
    }

    ~Stack() {
        while (topNode != nullptr) {
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
    }

    bool isEmpty() { return size == 0; }
    int getSize() { return size; }

    void push(char x) {
        Node* newNode = new Node(x);
        newNode->next = topNode;
        topNode = newNode;
        size++;
    }

    char pop() {
        if (isEmpty()) {
            std::cout << "Stack is empty!" << std::endl;
            return 0;
        }

        Node* temp = topNode;
        char data = temp->data;
        topNode = topNode->next;
        delete temp;
        size--;
        return data;
    }

    char top() {
        if (isEmpty()) {
            std::cout << "Stack is empty!" << std::endl;
            return 0;
        }
        return topNode->data;
    }

};

#endif // STACK_HPP