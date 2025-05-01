
#include<iostream>
#include<vector>
#include<random>
#include<algorithm> // for std::generate
#include<fstream> // For file operations

#include "sorting_algorithms.hpp"


class Benchmark {
    std::mt19937 rng{ std::random_device{}() };
    std::uniform_int_distribution<int> dist;
public:
    Benchmark() : dist(0, 999999) {
        std::random_device rd;
        rng.seed(rd());
    }


    template<typename SortAlgorithm>
    std::pair<int, int> benchmark(SortAlgorithm sort_algorithm, int runs, int size = 1000) {
        int comparisons = 0;
        int swaps = 0;

        double total_time = 0.0;
        for (int i = 0; i < runs; ++i) {
            std::vector<int> arr(size);
            std::generate(arr.begin(), arr.end(), [&]() { return dist(rng); });

            // Best case for insertion_sort, selection_sort, and shell_sort
            // std::sort(arr.begin(), arr.end()); // Comment out for average case
            // std::reverse(arr.begin(), arr.end()); // Reverse the sorted array, worst case.

            auto [c, s] = sort_algorithm(arr); // For insertion_sort, selection_sort, and shell_sort
            comparisons += c;
            swaps += s;
        }

        //  Return average comparisons and swaps (do not print anything here)
        int avg_comparisons = comparisons / runs;
        int avg_swaps = swaps / runs;

        return { avg_comparisons, avg_swaps };
    }
};


int main() {
    Benchmark benchmarker;
    const int runs = 5; // Number of test runs
    const int max_size = 10000; // Maximum size of the array to sort

    // Open a csv file to write the results
    std::ofstream file("benchmark_results.csv");
    if (!file.is_open()) {
        std::cerr << "Error opening file for writing." << std::endl;
        return 1;
    }

    // Write the header to the CSV file
    file << "Size,Insertion Compares,Insertion Swaps,Selection Compares,Selection Swaps,Shell Compares,Shell Swaps\n";

    for (int i = 1; i < max_size; ++i) {
        auto [average_comparisons_insertion, average_swaps_insertion] =
            benchmarker.benchmark(sorting_algorithms<int>::insertion_sort, runs, i);

        auto [average_comparisons_selection, average_swaps_selection] =
            benchmarker.benchmark(sorting_algorithms<int>::selection_sort, runs, i);

        auto [average_comparisons_shell, average_swaps_shell] =
            benchmarker.benchmark(sorting_algorithms<int>::shell_sort, runs, i);

        // Write the results to the CSV file
        file << i << ","
            << average_comparisons_insertion << ","
            << average_swaps_insertion << ","
            << average_comparisons_selection << ","
            << average_swaps_selection << ","
            << average_comparisons_shell << ","
            << average_swaps_shell << "\n";

        std::cout << "Completed size " << i << "..." << "\r";
    }

    std::cout << "Benchmarking completed. Results saved to benchmark_results.csv." << std::endl;
    file.close(); // Close the file after writing

    return 0;
}