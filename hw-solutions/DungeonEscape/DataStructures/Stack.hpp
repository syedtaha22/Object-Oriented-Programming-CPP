#ifndef STACK_HPP
#define STACK_HPP

#include <stdexcept>

#include "Node.hpp"

namespace DataStructures {

    template <typename T>
    class Stack {
        Node<T>* top;
    public:
        Stack() : top(nullptr) {}

        ~Stack() {
            while (top != nullptr) {
                Node<T>* temp = top;
                top = top->next;
                delete temp;
            }
        }

        void push(const T& data) {
            Node<T>* newNode = new Node<T>(data, top);
            top = newNode;
        }

        T pop() {
            if (top == nullptr) {
                throw std::runtime_error("Stack is empty");
            }
            Node<T>* temp = top;
            T data = top->data;
            top = top->next;
            delete temp;
            return data;
        }

        T peek() {
            if (top == nullptr) {
                throw std::runtime_error("Stack is empty");
            }
            return top->data;
        }

        bool isEmpty() const {
            return top == nullptr;
        }

    };

} // namespace DataStructures

#endif // STACK_HPP