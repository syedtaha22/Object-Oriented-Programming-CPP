#include <iostream>

template <typename T, int SIZE>
class FixedArray {
    T data[SIZE];
public:
    T& operator[](int index) { return data[index]; }
    int getSize() const { return SIZE; }
};

int main() {
    FixedArray<int, 4> arr;

    for (int i = 0; i < arr.getSize(); ++i) {
        arr[i] = i * 10;
    }

    for (int i = 0; i < arr.getSize(); ++i) {
        std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
    }

    return 0;
}
