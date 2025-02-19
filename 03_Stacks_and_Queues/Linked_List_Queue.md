# Linked List-Based Queue

In this section, we implement a **queue** using a **singly linked list**. Unlike an array-based queue, this implementation does not require resizing and allows efficient memory usage by dynamically allocating space as needed.

## Implementation Overview

A **linked list queue** consists of nodes, where each node contains a data element and a pointer to the next node. The queue follows the **First In, First Out (FIFO)** principle, meaning elements are added at the back (enqueue) and removed from the front (dequeue). This ensures that the oldest element is always processed first.

### Core Operations

A linked list queue supports the following fundamental operations:

- **Enqueue** – Adds an element to the back of the queue.
- **Dequeue** – Removes and returns the front element of the queue.
- **Front** – Retrieves the front element without removing it.
- **Size** – Returns the number of elements in the queue.
- **isEmpty** – Checks whether the queue is empty.

## Integer Queue Implementation

We now implement a queue specifically for **integers**, using a singly linked list.

### Class Prototype

```cpp
class Queue {
private:
    struct Node {
        int data;
        Node* next;
    };
    Node* frontNode;  // Pointer to the front of the queue
    Node* rearNode;   // Pointer to the rear of the queue
    int count;        // Number of elements in the queue

public:
    Queue();
    ~Queue();
    void enqueue(int item);
    void dequeue();
    int front() const;
    int size() const;
    bool isEmpty() const;
};
```

### Implementation

#### **Constructor & Destructor**

The constructor initializes an empty queue by setting `frontNode` and `rearNode` to `nullptr` and `count` to `0`. The destructor ensures proper memory cleanup by iteratively deleting all nodes.

```cpp
Queue::Queue() : frontNode(nullptr), rearNode(nullptr), count(0) {}

Queue::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}
```

#### **Enqueue Operation**

The `enqueue` function inserts a new element at the back of the queue. A new node is created and linked to the current rear node. If the queue was empty, both `frontNode` and `rearNode` are updated to point to the new node.

```cpp
void Queue::enqueue(int item) {
    Node* newNode = new Node{item, nullptr};
    if (isEmpty()) {
        frontNode = rearNode = newNode;
    } else {
        rearNode->next = newNode;
        rearNode = newNode;
    }
    count++;
}
```

#### **Dequeue Operation**

The `dequeue` function removes the front element from the queue. If the queue is empty, an exception is thrown. Otherwise, the front node is deleted, and `frontNode` is updated to the next node. If the queue becomes empty, `rearNode` is also set to `nullptr`.

```cpp
void Queue::dequeue() {
    if (isEmpty()) throw std::out_of_range("Queue is empty");
    Node* temp = frontNode;
    frontNode = frontNode->next;
    if (frontNode == nullptr) {
        rearNode = nullptr;
    }
    delete temp;
    count--;
}
```

#### **Front Operation**

The `front` function retrieves the front element without removing it. If the queue is empty, an exception is thrown. Otherwise, it returns the value stored in `frontNode`.

```cpp
int Queue::front() const {
    if (isEmpty()) throw std::out_of_range("Queue is empty");
    return frontNode->data;
}
```

#### **Size and isEmpty**

The `size` function returns the number of elements in the queue, while `isEmpty` checks whether the queue is empty by verifying if `count` is zero.

```cpp
int Queue::size() const {
    return count;
}

bool Queue::isEmpty() const {
    return count == 0;
}
```

## Complete Implementation

The complete implementation can be found here:  
[examples/LinkedListQueue.hpp](examples/LinkedListQueue.hpp)


## Array-Based Queue Implementation

For a **resizing array implementation** of queues, refer to: [Resizing_Array_Queue.md](Resizing_Array_Queue.md)

After understanding Queue implementations, look at a comparison between Linked List Implementation and Array Implementation: [Comparison of Linked List and Array Implementations](Linked_List_vs_Array_Stack_Queue.md)