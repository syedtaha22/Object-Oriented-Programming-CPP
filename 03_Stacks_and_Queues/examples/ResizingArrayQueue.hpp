#ifndef RESIZING_ARRAY_QUEUE_HPP
#define RESIZING_ARRAY_QUEUE_HPP

// Normal Queue, not circular

template <typename T>
class ResizingArrayQueue {
    T* arr;
    int capacity;
    int frontIndex;
    int count;

private:
    void resize(int newCapacity) {
        T* temp = new T[newCapacity];
        for (int i = 0; i < count; i++) temp[i] = arr[frontIndex + i];
        delete[] arr;
        arr = temp;
        frontIndex = 0;
        capacity = newCapacity;
    }

public:
    ResizingArrayQueue() : arr(new T[2]), capacity(2), frontIndex(0), count(0) {}

    ~ResizingArrayQueue() { delete[] arr; }

    // Returns true if the queue is empty
    bool isEmpty() const { return count == 0; }

    // Returns the number of elements in the queue
    int size() const { return count; }

    // Adds an element to the back of the queue
    void enqueue(T x) {
        if (count == capacity) resize(2 * capacity);
        arr[frontIndex + count] = x;
        count++;
    }

    // Removes the element at the front of the queue
    void dequeue() {
        if (isEmpty()) throw std::runtime_error("Queue is empty!");

        count--;
        frontIndex++;
        if (count > 0 && count == capacity / 4) resize(capacity / 2);
    }

    // Returns the element at the front of the queue
    T front() const {
        if (isEmpty()) throw std::runtime_error("Queue is empty!");
        return arr[frontIndex];
    }

    // Returns the element at the back of the queue
    T back() const {
        if (isEmpty()) throw std::runtime_error("Queue is empty!");
        return arr[frontIndex + count - 1];
    }

};

#endif // RESIZING_ARRAY_QUEUE_HPP