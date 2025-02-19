#ifndef LINKED_LIST_QUEUE_HPP
#define LINKED_LIST_QUEUE_HPP

#include <iostream>

template <typename T>
class LinkedListQueue {
private:
    struct Node {
        T data;
        Node* next;

        Node(T x) : data(x), next(nullptr) {}
        Node() : data(0), next(nullptr) {}
    };

    Node* frontNode;
    Node* backNode;
    int count;

public:

    LinkedListQueue() : frontNode(nullptr), backNode(nullptr), count(0) {}

    ~LinkedListQueue() {
        while (frontNode != nullptr) {
            Node* temp = frontNode;
            frontNode = frontNode->next;
            delete temp;
        }
    }


    // Returns true if the queue is empty
    bool isEmpty() const { return count == 0; }

    // Returns the number of elements in the queue
    int size() const { return count; }

    // Adds an element to the back of the queue
    void enqueue(T x) {
        Node* newNode = new Node(x);
        if (isEmpty()) frontNode = backNode = newNode;
        else {
            backNode->next = newNode;
            backNode = newNode;
        }
        count++;
    }

    // Removes the element at the front of the queue
    void dequeue() {
        if (isEmpty()) throw std::runtime_error("Queue is empty!");

        Node* temp = frontNode;
        frontNode = frontNode->next;
        delete temp;
        count--;
    }

    // Returns the element at the front of the queue
    T front() const {
        if (isEmpty()) throw std::runtime_error("Queue is empty!");
        return frontNode->data;
    }

    // Returns the element at the back of the queue
    T back() const {
        if (isEmpty()) throw std::runtime_error("Queue is empty!");
        return backNode->data;
    }
};


#endif // LINKED_LIST_QUEUE_HPP