/***************************************************************************************************
    Task 2:
        You are required to implement a sorting-based puzzle solver that models the behavior of a
        simplified warehouse robotic sorting system. The system is responsible for organizing a
        linear array of containers, each identified by a numerical priority code. The robot must sort
        the containers in ascending order — but under strict operational constraints.

        The robot can perform only a limited number of element movements (comparisons/swaps/shifts),
        and each sorting algorithm is modeled as a distinct robot strategy. Your task is to simulate
        and evaluate each of these strategies under the constraint of a fixed maximum number of
        allowed operations, K.

        Additionally, the sorting system must account for two types of operations:
            • Comparisons: The number of comparisons made between elements.
            • Swaps/Shifts: The number of times elements are swapped or shifted during the sorting
              process.

        You are required to evaluate and compare these strategies based on a weighted cost that
        considers comparisons, swaps and the number of remaining inversions. The objective is to
        find the optimal strategy based on a given weight for comparisons, swaps and remaining
        inversions.

        Objectives:
        For a given input array and an operation limit K, you must:
            1. Simulate partial versions of insertion, selection and shell sorts.
            2. For each strategy:
                a. Execute the algorithm until either the array is sorted or the operation limit K is
                   reached.
                b. Record the total number of operations used.
                c. Count and report the number of remaining inversions (i.e., pairs (i, j) where
                   i < j and arr[i] > arr[j]) after K operations.
                d. Count the number of comparisons and swaps made during the sorting process.
                e. Compute the weighted cost for each strategy:
                                weighted_cost=(weight_comparisons×comparisons)+(weight_swaps×swaps)
            3. Compare all strategies and determine:
                a. Whether the array could be fully sorted within K operations by each strategy.
                b. Which strategy brings the array closest to sorted form (i.e., with the fewest
                   inversions remaining).
                c. In the case of a tie in terms of inversions, report all equally effective
                   strategies.
                d. Report the strategy with the lowest weighted cost.


        System Requirements:
            • Arrays must be of size atleast 100.
            • Your implementation must:
                - Avoid any use of built-in sort or partial sort functions from STL.
                - Use object-oriented design:
                    - Define a base abstract class SortingStrategy.
                    - Derive each sorting algorithm from this base and override a
                      partialSort(std::vector<int>&, int K, int& comparisons, int& swaps) method.
                - Include a helper function to count total inversions in an array.
                - Ensure that comparisons and swaps are counted separately for each sorting
                  algorithm.

        Output Specifications:
        For each strategy, print:
            • The name of the sorting strategy.
            • The total number of operations used (out of K).
            • The number of comparisons made.
            • The number of swaps made.
            • The number of remaining inversions.

        Finally, report the name(s) of the strategy or strategies that resulted in the fewest
        remaining inversions, or the strategy with the lowest weighted cost.
**************************************************************************************************/


#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>
#include <random>
#include <iomanip>
#include <set>

// Function to count the number of inversions in an array
int countInversions(const std::vector<int>& arr) {
    int inversionCount = 0;
    for (size_t i = 0; i < arr.size(); ++i)
        for (size_t j = i + 1; j < arr.size(); ++j)
            if (arr[i] > arr[j]) ++inversionCount;
    return inversionCount;
}

// Abstract base class for sorting strategies
class SortingStrategy {
public:
    virtual std::string name() = 0;
    virtual void partialSort(std::vector<int>& arr, int K, int& comparisons, int& swaps) = 0;
    virtual ~SortingStrategy() {}
};

// Insertion Sort strategy
class InsertionSort : public SortingStrategy {
public:
    std::string name() override { return "Insertion Sort"; }

    void partialSort(std::vector<int>& arr, int K, int& comparisons, int& swaps) override {
        int n = arr.size();
        comparisons = 0;
        swaps = 0;

        for (int i = 1; i < n; ++i) {
            int key = arr[i];
            int j = i - 1;

            // Shift elements greater than key to the right
            while (j >= 0) {
                if (comparisons + swaps >= K) return;
                ++comparisons;

                if (arr[j] > key) {
                    if (comparisons + swaps >= K) return;
                    arr[j + 1] = arr[j]; ++swaps;
                }
                else break;
                --j;
            }

            // Place key in its correct position if allowed
            if (j + 1 != i && comparisons + swaps < K) {
                arr[j + 1] = key;
                ++swaps;
            }
        }
    }

};

// Selection Sort strategy
class SelectionSort : public SortingStrategy {
public:
    std::string name() override { return "Selection Sort"; }

    void partialSort(std::vector<int>& arr, int K, int& comparisons, int& swaps) override {
        int n = arr.size();
        comparisons = 0;
        swaps = 0;

        for (int i = 0; i < n - 1; ++i) {
            int min_index = i;

            for (int j = i + 1; j < n; ++j) {
                if (comparisons + swaps >= K) return;
                ++comparisons;

                if (arr[j] < arr[min_index]) min_index = j;
            }

            if (min_index != i && comparisons + swaps < K) {
                std::swap(arr[i], arr[min_index]);
                ++swaps;
            }
            if (comparisons + swaps >= K) return;
        }
    }
};

// Shell Sort strategy
class ShellSort : public SortingStrategy {
public:
    std::string name() override { return "Shell Sort"; }

    void partialSort(std::vector<int>& arr, int K, int& comparisons, int& swaps) override {
        int n = arr.size();
        comparisons = 0;
        swaps = 0;

        // Calculate the initial gap using Knuth's sequence
        int gap = 1;
        while (gap < n / 3) gap = 3 * gap + 1;

        while (gap >= 1) {
            for (int i = gap; i < n; ++i) {
                int temp = arr[i];
                int j = i;

                while (j >= gap) {
                    if (comparisons + swaps >= K) return;
                    ++comparisons;
                    if (arr[j - gap] > temp) {
                        if (comparisons + swaps >= K) return;
                        arr[j] = arr[j - gap];
                        ++swaps;
                    }
                    else break;
                    j -= gap;
                }
                if (j != i && comparisons + swaps < K) {
                    arr[j] = temp;
                    ++swaps;
                }
                if (comparisons + swaps >= K) return;
            }
            gap /= 3;
        }
    }
};


class Evaluator {
    double compare_weight;
    double swap_weight;
    double remaining_inversion_weight;

    double compute_cost(int comparisons, int swaps, int remaining_inversions) {
        return compare_weight * comparisons + swap_weight * swaps + remaining_inversion_weight * remaining_inversions;
    }

    void print(std::string name, double cost, double comparisons, double swaps, double remaining_inversions) {
        std::cout << std::left << std::setw(15) << name
            << " -> Operations used: " << std::right << std::setw(4) << (comparisons + swaps)
            << ", Comparisons: " << std::setw(4) << comparisons
            << ", Swaps: " << std::setw(4) << swaps
            << ", Remaining inversions: " << std::setw(5) << remaining_inversions
            << ", Cost: " << std::fixed << std::setprecision(2) << std::setw(6) << cost
            << '\n';
    }

public:

    Evaluator(double compare_weight, double swap_weight, double remaining_inversion_weight)
        : compare_weight(compare_weight), swap_weight(swap_weight), remaining_inversion_weight(remaining_inversion_weight) {
    }

    template<typename SortAlgorithm>
    double evaluate(SortAlgorithm& algorithm, std::vector<int> arr, int K) {
        int comparisons = 0, swaps = 0;
        algorithm.partialSort(arr, K, comparisons, swaps);
        int remaining_inversions = countInversions(arr);
        return compute_cost(comparisons, swaps, remaining_inversions);
    }

    // Perform runs number of runs on random arrays, and average cost accross all runs
    std::vector<std::string> evaluate_strategies(int K, int runs) {
        std::vector<double> costs(3); // Store costs for each strategy
        std::vector<double> total_compares(3); // Store comparisons for each strategy
        std::vector<double> total_swaps(3); // Store swaps for each strategy
        std::vector<double> total_remaining_inversions(3); // Store remaining inversions for each strategy
        std::vector<SortingStrategy*> strategies = { new InsertionSort(), new SelectionSort(), new ShellSort() };

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist(1, 1000); // Random numbers between 1 and 1000

        for (int i = 0; i < runs; ++i) {
            // Generate a random array of size 100
            std::vector<int> arr(100);
            std::generate(arr.begin(), arr.end(), [&]() { return dist(gen); });

            for (int j = 0; j < strategies.size(); ++j) {
                int comparisons = 0, swaps = 0;
                strategies[j]->partialSort(arr, K, comparisons, swaps);
                int remaining_inversions = countInversions(arr);
                double cost = compute_cost(comparisons, swaps, remaining_inversions);
                costs[j] += cost;
                total_compares[j] += static_cast<double>(comparisons);
                total_swaps[j] += static_cast<double>(swaps);
                total_remaining_inversions[j] += static_cast<double>(remaining_inversions);
            }
        }

        // Average the costs, comparisons, and swaps
        for (int j = 0; j < costs.size(); ++j) {
            costs[j] /= runs;
            total_compares[j] /= runs;
            total_swaps[j] /= runs;
            total_remaining_inversions[j] /= runs;
        }

        // Print the average costs, comparisons, and swaps for each strategy, use iomanip to format the output
        std::cout << "Average Costs, Comparisons, and Swaps for each strategy:\n";
        for (int j = 0; j < strategies.size(); ++j) {
            print(strategies[j]->name(), costs[j], total_compares[j], total_swaps[j], total_remaining_inversions[j]);
        }

        // Find the best strategy/strategies based on the lowest cost or lowest remaining inversions
        double lowest_cost = std::numeric_limits<double>::max();
        std::vector<std::string> best_strategies;
        for (int j = 0; j < costs.size(); ++j) {
            if (costs[j] < lowest_cost) {
                lowest_cost = costs[j];
                best_strategies = { strategies[j]->name() };
            }
            else if (costs[j] == lowest_cost) best_strategies.push_back(strategies[j]->name());
        }

        // Delete the strategy objects
        for (auto strategy : strategies) delete strategy;
        return best_strategies;
    }
};


template <typename T>
T get_random(T min, T max) {
    static std::mt19937 rng(std::random_device{}());

    if constexpr (std::is_integral_v<T>) {
        std::uniform_int_distribution<T> dist(min, max);
        return dist(rng);
    }
    else if constexpr (std::is_floating_point_v<T>) {
        std::uniform_real_distribution<T> dist(min, max);
        return dist(rng);
    }
    else static_assert(std::is_arithmetic_v<T>, "get_random requires an arithmetic type");
}

// Main function
int main() {
    const int arraySize = 100;
    std::vector<int> data(arraySize);

    // Initialize random number generator for array elements
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(1, arraySize);

    // Populate the array with random values
    std::generate(data.begin(), data.end(), [&]() { return dist(mt); });

    // Define the maximum operation limit based on the array size
    int operation_limit_min = (arraySize * arraySize) / 60;
    int operation_limit_max = (arraySize * arraySize);

    int operation_limit = get_random<int>(operation_limit_min, operation_limit_max);

    double compare_weight = get_random<double>(0.0, 1.0); // Random weight for comparisons
    double swap_weight = get_random<double>(0.0, 1.0); // Random weight for swaps
    double remaining_inversion_weight = get_random<double>(0.0, 0.1); // Random weight for remaining inversions

    std::cout << "Array Size: " << arraySize << std::endl;
    std::cout << "Operation Limit: " << operation_limit << std::endl;
    std::cout << "Compare Weight: " << compare_weight << std::endl;
    std::cout << "Swap Weight: " << swap_weight << std::endl;
    std::cout << "Remaining Inversion Weight: " << remaining_inversion_weight << "\n\n";


    // Evaluate the strategies with the defined operation limit and weights
    Evaluator evaluator(compare_weight, swap_weight, remaining_inversion_weight);
    std::vector<std::string> best_strategies = evaluator.evaluate_strategies(operation_limit, 10); // 10 runs for averaging


    std::cout << "\nBest Strategy/Strategies: \n";
    for (const std::string& strategyName : best_strategies) {
        std::cout << strategyName << '\n';
    }

    return 0;
}
