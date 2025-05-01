#ifndef SORTING_ALGORITHMS_HPP
#define SORTING_ALGORITHMS_HPP

#include <vector>
#include <utility>

template <typename T>
class sorting_algorithms {
public:
    static std::pair<int, int> insertion_sort(std::vector<T>& arr) {
        int comparisons = 0;
        int swaps = 0;
        for (size_t i = 1; i < arr.size(); ++i) {
            T key = arr[i];
            int j = static_cast<int>(i) - 1;
            while (j >= 0) {
                ++comparisons;
                if (arr[j] > key) {
                    arr[j + 1] = arr[j]; ++swaps; // Move element
                    --j;
                }
                else break;
            }
            arr[j + 1] = key;
            ++swaps;  // Insertion of key
        }
        return { comparisons, swaps };
    }

    static std::pair<int, int> selection_sort(std::vector<T>& arr) {
        size_t n = arr.size();
        int comparisons = 0;
        int swaps = 0;
        for (size_t i = 0; i < n - 1; ++i) {
            size_t min_index = i;
            for (size_t j = i + 1; j < n; ++j) {
                ++comparisons;
                if (arr[j] < arr[min_index]) min_index = j;
            }
            std::swap(arr[i], arr[min_index]);
            ++swaps;
        }

        return { comparisons, swaps };
    }

    static std::pair<int, int> shell_sort(std::vector<T>& arr) {
        size_t n = arr.size();
        int comparisons = 0;
        int swaps = 0;

        // Using the Knuth sequence for gap calculation
        size_t gap = 1;
        while (gap < n / 3) gap = 3 * gap + 1; // Knuth's formula

        while (gap >= 1) {
            for (size_t i = gap; i < n; ++i) {
                T temp = arr[i];
                size_t j = i;
                while (j >= gap) {
                    ++comparisons;
                    if (arr[j - gap] > temp) {
                        arr[j] = arr[j - gap]; ++swaps; // Move element
                        j -= gap;
                    }
                    else break;
                }
                arr[j] = temp; ++swaps; // Insertion of temp
            }
            gap /= 3; // Reduce the gap for the next iteration
        }
        return { comparisons, swaps };
    }
};

#endif // SORTING_ALGORITHMS_HPP    

