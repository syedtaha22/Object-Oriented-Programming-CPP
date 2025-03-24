// generic queue class

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <stdexcept>

#include "Node.hpp"

namespace DataStructures {

    template <typename T>
    class Queue {
        Node<T>* front;
        Node<T>* rear;
    public:

        Queue() : front(nullptr), rear(nullptr) {}

        // Copy constructor
        Queue(const Queue& other) : front(nullptr), rear(nullptr) {
            Node<T>* current = other.front;
            while (current != nullptr) {
                enqueue(current->data);
                current = current->next;
            }
        }

        // Copy assignment
        Queue& operator=(const Queue& other) {
            if (this == &other) {
                return *this;
            }

            while (front != nullptr) {
                Node<T>* temp = front;
                front = front->next;
                delete temp;
            }

            front = rear = nullptr;

            Node<T>* current = other.front;
            while (current != nullptr) {
                enqueue(current->data);
                current = current->next;
            }

            return *this;
        }

        ~Queue() {
            while (front != nullptr) {
                Node<T>* temp = front;
                front = front->next;
                delete temp;
            }
        }

        void enqueue(const T& data) {
            Node<T>* newNode = new Node<T>(data);
            if (front == nullptr) {
                front = rear = newNode;
            }
            else {
                rear->next = newNode;
                rear = newNode;
            }
        }

        T dequeue() {
            if (front == nullptr) {
                throw std::runtime_error("Queue is empty");
            }
            Node<T>* temp = front;
            T data = front->data;
            front = front->next;
            delete temp;
            return data;
        }

        T peek() {
            if (front == nullptr) {
                throw std::runtime_error("Queue is empty");
            }
            return front->data;
        }

        bool isEmpty() const {
            return front == nullptr;
        }
    };

} // namespace DataStructures

#endif // QUEUE_HPP