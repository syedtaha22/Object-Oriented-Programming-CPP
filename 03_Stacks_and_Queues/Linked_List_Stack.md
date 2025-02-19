# Linked List-Based Stack

In this section, we implement a **stack** using a **singly linked list**. Unlike an array-based stack, this implementation does not require resizing and allows efficient memory usage by allocating space dynamically as needed.

## Implementation Overview

A **linked list stack** consists of nodes, where each node contains a data element and a pointer to the next node. The stack grows or shrinks dynamically without requiring a predefined size, making it efficient for cases where the number of elements is unknown or frequently changing.

### Core Operations

A linked list stack supports the following fundamental operations:

- **Push** – Adds an element to the top of the stack by creating a new node and updating the top pointer.
- **Pop** – Removes and returns the top element by deleting the first node and updating the top pointer.
- **Top** – Retrieves the top element without removing it.
- **Size** – Returns the number of elements in the stack.
- **isEmpty** – Checks whether the stack is empty.

## Integer Stack Implementation

We now implement a stack specifically for **integers**, using a singly linked list.

### Class Prototype

```cpp
class Stack {
private:
    struct Node {
        int data;
        Node* next;
    };
    Node* topNode;  
    int count;  

public:
    Stack();
    ~Stack();
    void push(int item);
    void pop();
    int top() const;
    int size() const;
    bool isEmpty() const;
};
```

### Implementation

#### **Constructor & Destructor**

The constructor initializes an empty stack by setting `topNode` to `nullptr` and `count` to `0`, indicating that there are no elements. The destructor ensures proper memory cleanup by iteratively deleting all nodes.

```cpp
Stack::Stack() : topNode(nullptr), count(0) {}

Stack::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}
```

#### **Push Operation**

The `push` function inserts a new element at the top of the stack. A new node is created, and its `next` pointer is set to the current top node. Then, `topNode` is updated to point to this new node, and `count` is incremented.

```cpp
void Stack::push(int item) {
    Node* newNode = new Node{item, topNode};
    topNode = newNode;
    count++;
}
```

#### **Pop Operation**

The `pop` function removes the top element from the stack. It first checks if the stack is empty, throwing an exception if there are no elements to remove. Otherwise, it stores the reference to the current top node, updates `topNode` to the next node, deletes the old top node, and decrements `count`.

```cpp
void Stack::pop() {
    if (isEmpty()) throw std::out_of_range("Stack is empty");
    Node* temp = topNode;
    topNode = topNode->next;
    delete temp;
    count--;
}
```

#### **Top Operation**

The `top` function retrieves the top element without removing it. If the stack is empty, an exception is thrown. Otherwise, it returns the value stored in `topNode`.

```cpp
int Stack::top() const {
    if (isEmpty()) throw std::out_of_range("Stack is empty");
    return topNode->data;
}
```

#### **Size and isEmpty**

The `size` function returns the number of elements in the stack, while `isEmpty` checks whether the stack is empty by verifying if `count` is zero.

```cpp
int Stack::size() const {
    return count;
}

bool Stack::isEmpty() const {
    return count == 0;
}
```

## Complete Implementation

The complete implementation can be found here:\
[examples/LinkedListStack.hpp](examples/LinkedListStack.hpp)


## Array-Based Stack Implementation

For a **resizing array implementation** of stacks, refer to: [Resizing\_Array\_Stack.md](Resizing_Array_Stack.md)

After understanding Stack implementations, look at a comparison between Linked List Implementation and Array Implementation: [Comparison of Linked List and Array Implementations](Linked_List_vs_Array_Stack_Queue.md)
