/**********************************************************************************************
    Task 3:
        Implement a generic functor selection_sort that takes in an std::vector<T>& and sorts
        it (in place) using selection sort.

        Deliverables: selection_sort.hpp
*********************************************************************************************/

#ifndef SELECTION_SORT_HPP
#define SELECTION_SORT_HPP

#include <vector>

template <typename T>
class selection_sort {
public:
    void operator()(std::vector<T>& arr) {
        size_t n = arr.size();
        for (size_t i = 0; i < n - 1; ++i) {
            size_t min_index = i;
            for (size_t j = i + 1; j < n; ++j) {
                if (arr[j] < arr[min_index]) min_index = j;
            }
            std::swap(arr[i], arr[min_index]);
        }
    }
};

#endif // SELECTION_SORT_HPP