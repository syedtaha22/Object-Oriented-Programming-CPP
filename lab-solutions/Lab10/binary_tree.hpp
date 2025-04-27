/**************************************************************************************************
    Task 5:
        Implement a class BinaryTree that models a simple binary tree. The class should include
        the following functionalities:
        - insert: A method to insert a node with a given value into the tree, ensuring that the
          binary tree properties are maintained. The new node should be inserted in the correct
          position based on the binary search tree (BST) rule, where all nodes in the left
          subtree have values less than the root, and all nodes in the right subtree have values
          greater than the root.

        - in_order_traversal: A method that performs an in-order traversal of the tree and returns
          an array of node values. In an in-order traversal, the tree is recursively traversed as
          follows: first, the left subtree is visited, then the current node, and finally, the
          right subtree. This ensures that nodes are visited in ascending order in a binary search
          tree. The method should return an array containing these values.

        - clear: A method to clear the tree, deleting all nodes and freeing up memory. This method
          should ensure that all dynamically allocated memory is properly released to avoid memory
          leaks.

        - operator(std::vector<T>&): A method that takes in a vector of values and inserts each value into the
          binary tree using the insert method. Then does an in-order traversal adding the values to the
          vector. This gives a sorted array of the values in the vector.

        Deliverables: binary_tree.hpp
**************************************************************************************************/

#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <iostream>
#include <vector>

template <typename T>
class BinaryTree {
    struct Node {
        T data;
        Node* left;
        Node* right;

        Node(T value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root;
private:

    void insert(Node*& node, T value) {
        if (node == nullptr) node = new Node(value);
        else if (value < node->data) insert(node->left, value);
        else insert(node->right, value);
    }

    void in_order_traversal(Node* node, std::vector<T>& result) {
        if (node != nullptr) {
            in_order_traversal(node->left, result);
            result.push_back(node->data);
            in_order_traversal(node->right, result);
        }
    }

    void clear(Node* node) {
        if (node != nullptr) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    void insert(T value) {
        insert(root, value);
    }

    std::vector<T> in_order_traversal() {
        std::vector<T> result;
        in_order_traversal(root, result);
        return result;
    }

    void operator()(std::vector<T>& arr) {
        for (const auto& value : arr) insert(value);
        arr.clear();
        in_order_traversal(root, arr);
    }

    void clear() {
        clear(root);
        root = nullptr; // Reset the root to nullptr
    }

    ~BinaryTree() { clear(root); }

};


#endif // BINARY_TREE_HPP