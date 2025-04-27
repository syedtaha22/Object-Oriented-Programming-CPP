/**************************************************************************************************
    Task 6:
        Implement a class to evaluate the performance of different sorting algorithms using the
        Stopwatch utility developed in Task 1. This task focuses on applying the previously
        implemented components in a practical benchmarking scenario.
        Create a class responsible for performance testing. The class should include a function that
        accepts a sorting algorithm and evaluates its average execution time over multiple runs.
        Specifically, the function will:

            - Accept a callable sorting algorithm (such as the functor or function implemented in
              Tasks 2–5) and an integer N denoting the number of test runs.
            - For each run, generate a new std::vector<int> containing 100,000 randomly generated
              integers.
            - Measure the time taken to sort the array using the Stopwatch class.
            - Accumulate the timings across all runs and return the average execution time.

        The use of std::function or templates is encouraged to support different sorting algorithm
        types.

        Inside main, invoke this class to benchmark the performance of all three algorithms—
        insertion_sort, selection_sort, and shell_sort—and print their average execution times.
        Additionally, invoke it with a BinaryTree object, and measure the time. Comment on your
        findings and the time complexity of the various algorithms.

        Deliverables: main.cpp
**************************************************************************************************/

#include<iostream>
#include<vector>
#include<random>
#include<algorithm> // for std::generate

#include "binary_tree.hpp"
#include "selection_sort.hpp"
#include "insertion_sort.hpp"
#include "shell_sort.hpp"

#include "Stopwatch.hpp"

class Benchmark {
    std::mt19937 rng{ std::random_device{}() };
    std::uniform_int_distribution<int> dist;
public:
    Benchmark() : dist(0, 999999) {
        std::random_device rd;
        rng.seed(rd());
    }


    template<typename SortAlgorithm>
    double benchmark(SortAlgorithm sort_algorithm, int runs, int size = 100000) {
        double total_time = 0.0;
        for (int i = 0; i < runs; ++i) {
            std::vector<int> arr(size);
            std::generate(arr.begin(), arr.end(), [&]() { return dist(rng); });

            std::cout << "Running benchmark " << i + 1 << "..." << "\r";
            std::cout.flush();

            Stopwatch stopwatch;
            stopwatch.start();
            sort_algorithm(arr);
            stopwatch.stop();

            // If it's a BinaryTree, we need to call the clear method to clear the tree for the next run
            if constexpr (std::is_same_v<SortAlgorithm, BinaryTree<int>>) sort_algorithm.clear();

            total_time += stopwatch.get_elapsed_time_seconds();
        }
        return total_time / runs;
    }
};


int main() {
    Benchmark benchmarker;
    const int runs = 5; // Number of test runs

    // Benchmarking Insertion Sort
    double insertion_sort_time = benchmarker.benchmark(insertion_sort<int>(), runs);
    std::cout << "Average Insertion Sort Time: " << insertion_sort_time << " seconds" << std::endl;

    // Benchmarking Selection Sort
    double selection_sort_time = benchmarker.benchmark(selection_sort<int>(), runs);
    std::cout << "Average Selection Sort Time: " << selection_sort_time << " seconds" << std::endl;

    // Benchmarking Shell Sort
    double shell_sort_time = benchmarker.benchmark(shell_sort<int>, runs);
    std::cout << "Average Shell Sort Time: " << shell_sort_time << " seconds" << std::endl;

    // Benchmarking Binary Tree Inorder Traversal Sort
    double binary_tree_time = benchmarker.benchmark(BinaryTree<int>(), runs);
    std::cout << "Average Binary Tree Time: " << binary_tree_time << " seconds" << std::endl;

    return 0;
}