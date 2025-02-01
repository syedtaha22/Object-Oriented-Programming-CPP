#include "../headers/SharedIntPointer.hpp"

SharedIntPointer::SharedIntPointer(int n) {
    // Allocate memory for the integer
    num = new int(n);
    // Initialize the reference count to 1
    refCount = new int(1);
}

// Copy constructor
SharedIntPointer::SharedIntPointer(const SharedIntPointer& other) {
    // Copy the Pointer and the reference count
    num = other.num;
    refCount = other.refCount;
    // Increment the reference count
    (*refCount)++;
}

SharedIntPointer& SharedIntPointer::operator=(const SharedIntPointer& other) {
    if (this == &other) return *this; // Prevent self-assignment
    /*
        The Object may already be pointing to another integer.
        So first Decrement the reference count of the current integer.
        Check if the reference count is 0, if it is, delete the integer.

        Then Copy the Pointer and the reference count from the other object.
        Increment the reference count.
    */
    (*refCount)--;
    if (*refCount == 0) {
        delete num;
        delete refCount;
    }

    num = other.num;
    refCount = other.refCount;
    (*refCount)++;
    return *this;
}

int SharedIntPointer::get() {
    return *num;
}

void SharedIntPointer::set(int value) {
    *num = value;
}

int SharedIntPointer::getRefCount() {
    return *refCount;
}

SharedIntPointer::~SharedIntPointer() {
    (*refCount)--;
    if (*refCount == 0) {
        delete num;
        delete refCount;
    }
}

