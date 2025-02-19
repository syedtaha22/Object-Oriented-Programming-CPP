#ifndef LINKED_LIST_STACK_HPP
#define LINKED_LIST_STACK_HPP

template <typename T>
class LinkedListStack {
private:
    struct Node {
        T data;
        Node* next;

        Node(T x) : data(x), next(nullptr) {}
        Node() : data(0), next(nullptr) {}
    };

    Node* topNode;
    int count;

public:

    LinkedListStack() : topNode(nullptr), count(0) {}

    ~LinkedListStack() {
        while (topNode != nullptr) {
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
    }

    // Returns true if the stack is empty
    bool isEmpty() const { return count == 0; }

    // Returns the number of elements in the stack
    int size() const { return count; }

    // Adds an element to the top of the stack
    void push(T x) {
        Node* newNode = new Node(x);
        newNode->next = topNode;
        topNode = newNode;
        count++;
    }

    // Removes the element at the top of the stack
    void pop() {
        if (isEmpty()) throw std::runtime_error("Stack is empty!");

        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
        count--;
    }

    // Returns the element at the top of the stack
    T top() const {
        if (isEmpty()) throw std::runtime_error("Stack is empty!");

        return topNode->data;
    }

};

#endif // LINKED_LIST_STACK_HPP 