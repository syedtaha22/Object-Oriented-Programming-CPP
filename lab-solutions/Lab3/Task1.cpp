/****************************************************************************************************
    Task 1:
        A doubly linked list (DLL) is a type of linked list where each node contains:
            1. Data – Stores the value.
            2. Next pointer – Points to the next node in the list.
            3. Previous pointer – Points to the previous node in the list.

        Unlike a singly linked list, a DLL allows both forward and backward traversal, making
        certain operations like deletion more efficient.

        One of the key advantages of a doubly linked list is that it supports both forward
        andvbackward traversal. This makes it useful in scenarios where elements need to be
        accessed from either end efficiently, such as in implementing undo/redo functionality or
        navigating through browser history.

        To manage the list efficiently, a DLL typically maintains both a head and a tail pointer:
            • The head points to the first node, allowing traversal from the beginning.
            • The tail points to the last node, making it possible to traverse backward or efficiently
              insert elements at the end.

        Each node in a DLL requires careful pointer management to ensure proper linking and memory
        handling. Since nodes are dynamically allocated, memory must be freed properly to prevent
        memory leaks.

        Your task is to implement a class DoublyLinkedList that represents a DLL of integers and
        supports the following operations:
            • add – Adds a new node with the given value at the end of the list.
            • remove – Removes the first occurrence of a given value from the list.
            • get – Returns the value at the i-th node.
            • traverseForward – Prints the list from head to tail.
            • traverseBack – Prints the list from tail to head
****************************************************************************************************/

#include <iostream>

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int data) : data(data), next(nullptr), prev(nullptr) {}
};

class DoublyLinkedList {
    Node* head;
    Node* tail;


public:

    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void add(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void remove(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                if (current == head) {
                    head = current->next;
                    if (head != nullptr) head->prev = nullptr;
                }
                else if (current == tail) {
                    tail = current->prev;
                    if (tail != nullptr) tail->next = nullptr;
                }
                else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
        }
    }

    int get(int index) {
        Node* current = head;
        for (int i = 0; i < index && current != nullptr; i++) {
            current = current->next;
        }
        return current != nullptr ? current->data : -1;
    }

    void traverseForward() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void traverseBack() {
        Node* current = tail;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->prev;
        }
        std::cout << std::endl;
    }

    ~DoublyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    DoublyLinkedList list;
    list.add(10);
    list.add(20);
    list.add(30);
    list.add(40);
    list.add(50);

    list.traverseForward();
    list.traverseBack();

    list.remove(30);
    list.remove(10);

    list.traverseForward();
    list.traverseBack();

    std::cout << "Element at index 1: " << list.get(1) << std::endl;

    return 0;
}