#ifndef LIST_HPP
#define LIST_HPP

#include <cstddef>
#include <stdexcept>

#include "Node.hpp"

namespace DataStructures {

    template <typename T>
    class List {
        Node<T>* head;
        Node<T>* tail;
    public:
        List() : head(nullptr), tail(nullptr) {}

        ~List() {
            while (head != nullptr) {
                Node<T>* temp = head;
                head = head->next;
                delete temp;
            }
        }

        void insert(const T& data) {
            Node<T>* newNode = new Node<T>(data);
            if (head == nullptr) {
                head = tail = newNode;
            }
            else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
        }

        void remove(size_t index) {
            if (index == 0) {
                Node<T>* temp = head;
                head = head->next;
                if (head != nullptr) {
                    head->prev = nullptr;
                }
                delete temp;
                return;
            }

            Node<T>* current = head;
            for (size_t i = 0; i < index; ++i) {
                if (current == nullptr) {
                    throw std::out_of_range("Index out of bounds");
                }
                current = current->next;
            }

            if (current == nullptr) {
                throw std::out_of_range("Index out of bounds");
            }

            if (current == tail) {
                tail = tail->prev;
                tail->next = nullptr;
                delete current;
                return;
            }

            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
        }

        Node<T>* get(size_t index) {
            Node<T>* current = head;
            for (size_t i = 0; i < index; ++i) {
                if (current == nullptr) {
                    throw std::out_of_range("Index out of bounds");
                }
                current = current->next;
            }
            return current;
        }

        Node<T>* getHead() {
            return head;
        }
    };

} // namespace DataStructures


#endif // LIST_HPP    