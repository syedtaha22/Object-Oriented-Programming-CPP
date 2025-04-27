/******************************************************************************************
    Task 2:
        Implement a generic functor insertion_sort that takes in an std::vector<T>& and sorts it
        (in place) using insertion sort.

        Deliverables: insertion_sort.hpp
********************************************************************************************/

#ifndef INSERTION_SORT_HPP
#define INSERTION_SORT_HPP

#include <vector>

template <typename T>
class insertion_sort {
public:
    void operator()(std::vector<T>& arr) {
        for (size_t i = 1; i < arr.size(); ++i) {
            T key = arr[i];
            int j = static_cast<int>(i) - 1;

            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                --j;
            }
            arr[j + 1] = key;
        }
    }
};

#endif // INSERTION_SORT_HPP