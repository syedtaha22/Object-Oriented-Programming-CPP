/***************************************************************************************************
    Task 2:
    Implement a queue data structure that supports the following operations in O(1) time:
        • enqueue(x) → Inserts x at the back of the queue.
        • dequeue() → Removes the front element from the queue and returns it.
        • front() → Returns the front element of the queue without removing it.

    Additionally, Implement size() to return the number of elements in the queue and isEmpty()
    to check whether the queue is empty.

    You are free to choose the implementation method (dynamic array or linked list), but you must
    justify your choice in comments.
***************************************************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>

class Queue {
private:
    struct Node {
        char data;
        Node* next;

        Node(char x) : data(x), next(nullptr) {}
        Node() : data(0), next(nullptr) {}
    };

    Node* frontNode;
    Node* backNode;
    int size;
public:

    Queue() {
        frontNode = nullptr;
        backNode = nullptr;
        size = 0;
    }

    ~Queue() {
        while (frontNode != nullptr) {
            Node* temp = frontNode;
            frontNode = frontNode->next;
            delete temp;
        }
    }

    bool isEmpty() { return size == 0; }
    int getSize() { return size; }

    void enqueue(char x) {
        Node* newNode = new Node(x);
        if (isEmpty()) {
            frontNode = newNode;
            backNode = newNode;
        }
        else {
            backNode->next = newNode;
            backNode = newNode;
        }
        size++;
    }

    char dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty!" << std::endl;
            return 0;
        }

        Node* temp = frontNode;
        char data = temp->data;
        frontNode = frontNode->next;
        delete temp;
        size--;
        return data;
    }

    char front() {
        if (isEmpty()) {
            std::cout << "Queue is empty!" << std::endl;
            return 0;
        }

        return frontNode->data;
    }

};

#endif // QUEUE_HPP