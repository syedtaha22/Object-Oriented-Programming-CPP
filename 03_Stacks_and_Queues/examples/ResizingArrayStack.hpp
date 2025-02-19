#ifndef RESIZING_ARRAY_STACK_HPP
#define RESIZING_ARRAY_STACK_HPP

template <typename T>
class ResizingArrayStack {
    T* arr;
    int capacity;
    int count;
private:
    void resize(int newCapacity) {
        T* temp = new T[newCapacity];
        for (int i = 0; i < count; i++) temp[i] = arr[i];
        delete[] arr;
        arr = temp;
        capacity = newCapacity;
    }

public:

    ResizingArrayStack() : arr(new T[2]), capacity(2), count(0) {}

    ~ResizingArrayStack() { delete[] arr; }

    // Returns true if the stack is empty
    bool isEmpty() const { return count == 0; }

    // Returns the number of elements in the stack
    int size() const { return count; }

    // Adds an element to the top of the stack
    void push(T x) {
        if (count == capacity) resize(2 * capacity);
        arr[count++] = x;
    }

    // Removes the element at the top of the stack
    void pop() {
        if (isEmpty()) throw std::runtime_error("Stack is empty!");
        count--;
        if (count > 0 && count == capacity / 4) resize(capacity / 2);
    }

    // Returns the element at the top of the stack
    T top() const {
        if (isEmpty()) throw std::runtime_error("Stack is empty!");
        return arr[count - 1];
    }

};

#endif // RESIZING_ARRAY_STACK_HPP