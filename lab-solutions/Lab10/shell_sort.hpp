/*******************************************************************************************
    Task 4:
        Implement a generic function shell_sort that takes in an std::vector<T>& and sorts
        it (in place) using shell sort.

        Deliverables: shell_sort.hpp
*********************************************************************************************/

#ifndef SHELL_SORT_HPP
#define SHELL_SORT_HPP

#include <vector>
#include <string>
#include <algorithm> // for std::swap

template <typename T>
void shell_sort(std::vector<T>& arr) {
    size_t n = arr.size();

    // Using the Knuth sequence for gap calculation
    size_t gap = 1;
    while (gap < n / 3) gap = 3 * gap + 1; // Knuth's formula

    while (gap >= 1) {
        for (size_t i = gap; i < n; ++i) {
            T temp = arr[i];
            size_t j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
        gap /= 3; // Reduce the gap for the next iteration
    }
}



#endif // SHELL_SORT_HPP    