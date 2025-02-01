#ifndef SHARED_INT_POINTER_HPP
#define SHARED_INT_POINTER_HPP


class SharedIntPointer {
    int* num;
    int* refCount;
public:
    SharedIntPointer(int n);

    // Copy constructor
    SharedIntPointer(const SharedIntPointer& other);

    // Overloaded assignment operator
    SharedIntPointer& operator=(const SharedIntPointer& other);

    // Getter and setter methods
    int get();
    void set(int value);

    // Method to get the reference count
    int getRefCount();

    // Destructor
    ~SharedIntPointer();
};

#endif // SHARED_INT_POINTER_HPP