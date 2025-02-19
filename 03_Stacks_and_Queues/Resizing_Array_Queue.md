# Resizing Array-Based Queue

In this section, we implement a **queue** using a **dynamically resizing array**. Unlike a fixed-size array, this implementation adjusts its size as elements are enqueued and dequeued, ensuring efficient memory usage. The queue automatically expands when it reaches capacity and shrinks when it becomes underutilized, optimizing memory allocation dynamically.

## Implementation Overview

A **resizing array queue** dynamically increases or decreases the allocated storage based on the number of elements. This prevents wasted memory from over-allocation and avoids queue overflows due to insufficient space. The queue follows the **First In, First Out (FIFO)** principle, meaning that elements are added at the rear and removed from the front.

## Core Operations

The queue supports the following fundamental operations:

1. **Enqueue** – Adds an element to the rear of the queue. If the current capacity is reached, the array size doubles before inserting the element.
2. **Dequeue** – Removes and returns the front element. If the number of elements falls below one-fourth of the capacity, the array size is halved to free unused memory.
3. **Front** – Retrieves the front element without removing it.
4. **Size** – Returns the number of elements in the queue.
5. **isEmpty** – Checks whether the queue is empty.

## Integer Queue Implementation

We now implement a queue specifically for **integers**, using a dynamically resizing array. This allows efficient memory usage while ensuring fast operations. The queue starts with an initial capacity and grows or shrinks as needed.

### Class Prototype

```cpp
class Queue {
private:
    int* arr;      // Pointer to dynamically allocated array
    int capacity;  // Total allocated size of the array
    int frontIndex; // Index of the front element
    int count;     // Number of elements in the queue

    void resize(int newCapacity); // Helper function to resize the array

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

#### **Resize Function**

The `resize` function handles dynamic memory allocation when the queue needs to grow or shrink. It realigns elements correctly in a new array to maintain proper ordering.

```cpp
void Queue::resize(int newCapacity) {
    int* newArr = new int[newCapacity]; // Allocate new array
    for (int i = 0; i < count; i++) {
        newArr[i] = arr[frontIndex + i]; // Copy elements sequentially
    }
    delete[] arr; // Free old memory
    arr = newArr; // Point to new array
    frontIndex = 0;
    capacity = newCapacity;
}
```

#### **Constructor & Destructor**

The constructor initializes the queue with an initial capacity and an empty array. The destructor ensures that dynamically allocated memory is freed when the queue is destroyed.

```cpp
Queue::Queue() : capacity(2), frontIndex(0), count(0) {
    arr = new int[capacity]; // Initialize array with capacity 2
}

Queue::~Queue() {
    delete[] arr; // Free allocated memory
}
```

#### **Enqueue Operation**

The `enqueue` function inserts an element at the rear of the queue. If the queue is full, it first doubles its capacity to accommodate new elements.

```cpp
void Queue::enqueue(int item) {
    if (count == capacity) {
        resize(2 * capacity);  // Double the capacity if full
    }
    arr[frontIndex + count] = item;
    count++;
}
```

#### **Dequeue Operation**

The `dequeue` function removes the front element. If the queue becomes underutilized (size falls below one-fourth of capacity), the array size is halved to prevent wasted memory.

```cpp
void Queue::dequeue() {
    if (count == 0) throw std::out_of_range("Queue is empty"); // Handle underflow
    frontIndex++;
    count--;
    if (count > 0 && count == capacity / 4) {
        resize(capacity / 2); // Reduce capacity if underutilized
    }
}
```

#### **Front Operation**

The `front` function retrieves the front element without modifying the queue. If the queue is empty, an exception is thrown.

```cpp
int Queue::front() const {
    if (count == 0) throw std::out_of_range("Queue is empty"); // Handle empty queue
    return arr[frontIndex]; // Return front element
}
```

#### **Size and isEmpty Operations**

The `size` function returns the number of elements in the queue, while `isEmpty` checks if the queue is empty.

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
[examples/ResizingArrayQueue.hpp](examples/ResizingArrayQueue.hpp)

## Linked List Implementation

For a **linked list implementation** of queues, refer to [Linked_List_Queue.md](Linked_List_Queue.md)

After understanding Queue implementations, look at a comparison between Linked List Implementation and Array Implementation: [Comparison of Linked List and Array Implementations](Linked_List_vs_Array_Stack_Queue.md)
