// Dynamic Array class

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <stdexcept>

namespace DataStructures {

    template <typename T>
    class Vector {
        T* data;
        int capacity;
        int size;

        // double when full, half when less than 1/4 full
        void resize(int newCapacity) {
            T* newData = new T[newCapacity];
            for (int i = 0; i < size; ++i) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            capacity = newCapacity;
        }

    public:
        Vector() : data(nullptr), capacity(0), size(0) {}

        ~Vector() {
            delete[] data;
        }

        void push_back(const T& value) {
            if (size == capacity) {
                resize(capacity == 0 ? 1 : capacity * 2);
            }
            data[size++] = value;
        }

        void pop_back() {
            if (size == 0) {
                throw std::runtime_error("Vector is empty");
            }
            if (size <= capacity / 4) {
                resize(capacity / 2);
            }
            --size;
        }

        T& operator[](int index) {
            if (index < 0 || index >= size) {
                throw std::out_of_range("Index out of bounds");
            }
            return data[index];
        }

        const T& operator[](int index) const {
            if (index < 0 || index >= size) {
                throw std::out_of_range("Index out of bounds");
            }
            return data[index];
        }

        int getSize() const {
            return size;
        }
    };

} // namespace DataStructures



#endif // VECTOR_HPP