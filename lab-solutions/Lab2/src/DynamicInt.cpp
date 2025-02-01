
#include "../headers/DynamicInt.hpp"

DynamicInt::DynamicInt(int n) {
    num = new int(n);
}

// Copy constructor
DynamicInt::DynamicInt(const DynamicInt& other) {
    num = new int(*other.num);
}

// Overloaded assignment operator
DynamicInt& DynamicInt::operator=(const DynamicInt& other) {
    if (this != &other) {
        delete num;
        num = new int(*other.num);
    }
    return *this;
}

void DynamicInt::set(int n) {
    *num = n;
}

int DynamicInt::get() {
    return *num;
}

DynamicInt::~DynamicInt() {
    delete num;
}

