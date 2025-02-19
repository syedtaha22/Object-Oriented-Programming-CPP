# Resizing Array-Based Stack  

In this section, we implement a **stack** using a **dynamically resizing array**. Unlike a fixed-size array, this implementation adjusts its size as elements are pushed and popped, ensuring efficient memory usage. The stack automatically expands when it reaches capacity and shrinks when it becomes underutilized, optimizing memory allocation dynamically.  

## Implementation Overview  

A **resizing array stack** dynamically increases or decreases the allocated storage based on the number of elements. This prevents wasted memory from over-allocation and avoids stack overflows due to insufficient space. The stack follows the **Last In, First Out (LIFO)** principle, meaning that elements are added and removed from the same end. The implementation uses an array internally, resizing it when needed to maintain efficient memory usage.

## Core Operations  

The stack supports the following fundamental operations:  

1. **Push** – Adds an element to the top of the stack. If the current capacity is reached, the array size doubles before inserting the element.
2. **Pop** – Removes and returns the top element. If the number of elements falls below one-fourth of the capacity, the array size is halved to free unused memory.
3. **Top** – Retrieves the top element without removing it.
4. **Size** – Returns the number of elements in the stack.
5. **isEmpty** – Checks whether the stack is empty.

## Integer Stack Implementation  

We now implement a stack specifically for **integers**, using a dynamically resizing array. This allows efficient memory usage while ensuring fast operations. The stack starts with an initial capacity and grows or shrinks as needed.

### Class Prototype  

```cpp
class Stack {
private:
    int* arr;       // Pointer to dynamically allocated array
    int capacity;   // Total allocated size of the array
    int count;      // Number of elements in the stack

    void resize(int newCapacity); // Helper function to resize the array

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

#### **Resize Function**  

The `resize` function handles dynamic memory allocation when the stack needs to grow or shrink. When increasing capacity, it doubles the current size. When decreasing, it halves the size if the number of elements falls below one-fourth of the capacity.

```cpp
void Stack::resize(int newCapacity) {
    int* newArr = new int[newCapacity]; // Allocate new array
    for (int i = 0; i < count; i++) {
        newArr[i] = arr[i]; // Copy existing elements
    }
    delete[] arr; // Free old memory
    arr = newArr; // Point to new array
    capacity = newCapacity;
}
```

#### **Constructor & Destructor**  

The constructor initializes the stack with an initial capacity and an empty array. The destructor ensures that dynamically allocated memory is freed when the stack is destroyed.

```cpp
Stack::Stack() : capacity(2), count(0) {
    arr = new int[capacity]; // Initialize array with capacity 2
}

Stack::~Stack() {
    delete[] arr; // Free allocated memory
}
```

#### **Push Operation**  

The `push` function inserts an element at the top of the stack. If the stack is full, it first doubles its capacity to accommodate new elements.

```cpp
void Stack::push(int item) {
    if (count == capacity) {
        resize(2 * capacity);  // Double the capacity if full
    }
    arr[count++] = item; // Add element and increase count
}
```

#### **Pop Operation**  

The `pop` function removes the top element. If the stack becomes underutilized (size falls below one-fourth of capacity), the array size is halved to prevent wasted memory.

```cpp
void Stack::pop() {
    if (count == 0) throw std::out_of_range("Stack is empty"); // Handle underflow
    count--; // Remove the top element
    if (count > 0 && count == capacity / 4) {
        resize(capacity / 2); // Reduce capacity if underutilized
    }
}
```

#### **Top Operation**  

The `top` function retrieves the top element without modifying the stack. If the stack is empty, an exception is thrown.

```cpp
int Stack::top() const {
    if (count == 0) throw std::out_of_range("Stack is empty"); // Handle empty stack
    return arr[count - 1]; // Return top element
}
```

#### **Size and isEmpty Operations**  

The `size` function returns the number of elements in the stack, while `isEmpty` checks if the stack is empty.

```cpp
int Stack::size() const {
    return count;
}

bool Stack::isEmpty() const {
    return count == 0;
}
```

## Complete Implementation  

The complete implementation can be found here:  
[examples/ResizingArrayStack.hpp](examples/ResizingArrayStack.hpp)  


## Linked List Implementation  

For a **linked list implementation** of stacks, refer to [Linked_List_Stack.md](Linked_List_Stack.md)  

After understanding Stack implementations, look at a comparison between Linked List Implementation and Array Implementation: [Comparison of Linked List and Array Implementations](Linked_List_vs_Array_Stack_Queue.md)
