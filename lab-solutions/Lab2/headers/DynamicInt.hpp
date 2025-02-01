#ifndef DYNAMIC_INT_HPP
#define DYNAMIC_INT_HPP

class DynamicInt {
    int* num;
public:
    DynamicInt(int n);
    DynamicInt(const DynamicInt& other);
    DynamicInt& operator=(const DynamicInt& other);

    void set(int n);
    int get();

    ~DynamicInt();

};

#endif // DYNAMIC_INT_HPP