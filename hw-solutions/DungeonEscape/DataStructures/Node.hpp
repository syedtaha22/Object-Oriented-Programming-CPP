// generic node class

#ifndef NODE_HPP
#define NODE_HPP

namespace DataStructures {

    template <typename T>
    class Node {
    public:
        T data;
        Node* next;
        Node* prev; // doubly linked list

        Node() : data(), next(nullptr), prev(nullptr) {}
        Node(const T& data) : data(data), next(nullptr), prev(nullptr) {}
        Node(const T& data, Node* next) : data(data), next(next), prev(nullptr) {}
    };

} // namespace DataStructures

#endif // NODE_HPP