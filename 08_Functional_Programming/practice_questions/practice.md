# Practice Problems: Callable Objects in C++

This practice set is designed to solidify your understanding and practical application of various callable entities in C++: **function pointers**, **functors (function objects)**, **lambda expressions**, and the **`std::function` wrapper**. Mastering these concepts is fundamental for writing flexible, efficient, and modern C++ code, especially when working with algorithms, callbacks, and generic programming patterns.

The problems are organized into three difficulty tiers: **Beginner**, **Intermediate**, and **Advanced**. It is highly recommended to work through them sequentially. Start with the Beginner problems to grasp the core syntax and usage of each callable type. Progress to the Intermediate section to explore common use cases, state management, and more complex interactions between these features. Finally, tackle the Advanced problems to delve into more intricate scenarios, including member function pointers, recursive lambdas, and performance considerations.

Each problem provides a clear objective. Focus on writing clean, correct, and idiomatic C++ code for each solution.

---

### Beginner

These problems cover the foundational syntax and basic usage of function pointers, functors, and lambdas, along with an introduction to `std::function`.

1.  **Function Pointer for Addition**
    Write a simple C++ function named `addTwoIntegers` that accepts two `int` parameters and returns their sum as an `int`. Then, declare a function pointer capable of pointing to such a function. Assign the `addTwoIntegers` function to this pointer and use the function pointer to call `addTwoIntegers` with arbitrary integer values, printing the result.

2.  **Simple Multiplication Functor**
    Define a C++ class or struct named `Multiplier`. Overload its function call operator (`operator()`) so that an instance of `Multiplier` can be called with two `int` arguments, returning their product. In your `main` function, create an object of `Multiplier` and use it to compute the product of `5` and `7`, displaying the output.

3.  **Lambda Capturing by Value**
    In your `main` function, declare a local `int` variable, for example, `int value = 10;`. Create a lambda expression that captures this `value` **by value**. Inside the lambda's body, print the captured value. Demonstrate that modifying the original `value` after the lambda's creation does not affect the value captured and printed by the lambda.

4.  **`std::function` with a Summing Lambda**
    Declare a `std::function` object that is capable of wrapping any callable entity which takes two `int` arguments and returns an `int`. Assign a lambda expression to this `std::function` object, where the lambda's purpose is to sum its two integer parameters. Finally, invoke the `std::function` object with arbitrary integers and print the computed sum.

5.  **Function Pointer Callback**
    Write a C++ function named `executeCallback` that accepts two arguments: a function pointer (capable of pointing to a function that takes two `int`s and returns `void`) and two `int` values. Inside `executeCallback`, call the function pointed to by the function pointer, passing the two `int` values. Create a simple `void` function (e.g., `printProduct`) to serve as the target for the function pointer and demonstrate its use with `executeCallback`.

---

### Intermediate

These problems delve deeper, exploring stateful callable objects, collections of callable entities, and more nuanced capture mechanisms with lambdas.

1.  **Stateful Counter Functor**
    Implement a functor class named `CallCounter`. This functor should maintain an internal integer state representing the number of times its `operator()` has been invoked. Each time `operator()` is called, it should increment this internal counter. Demonstrate this by creating an instance of `CallCounter`, calling it multiple times (e.g., five times), and then printing the final count.

2.  **Array of Arithmetic Function Pointers**
    Define four separate simple functions: `add`, `subtract`, `multiply`, and `divide`, each taking two `double` arguments and returning a `double`. Create an array of function pointers, where each element can point to one of these arithmetic functions. Populate this array with your four defined functions. Then, iterate through the array, using each function pointer to perform its respective operation on a fixed pair of numbers (e.g., `10.0` and `5.0`), printing the result of each operation.

3.  **Lambda with Mixed Capture**
    Declare two local variables: an `int` (e.g., `x`) and a `double` (e.g., `y`). Create a lambda expression that captures `x` **by value** and `y` **by reference**. Inside the lambda's body, increment `x` (the captured copy) and modify `y` (the original variable). After the lambda's definition, modify the original `x`. Invoke the lambda, then print the values of the original `x` and `y` to demonstrate the effects of mixed capture.

4.  **Runtime Behavior Switching with `std::function`**
    Declare a single `std::function<double(double, double)>` object. Initially, assign a lambda to it that performs addition. Call the `std::function` object and print the result. Then, reassign the *same* `std::function` object to a different lambda that performs multiplication. Call it again with the same parameters and print the new result. This demonstrates `std::function`'s ability to switch callable behaviors at runtime.

5.  **`std::function` Callback for Vector Processing**
    Write a function `processVector` that takes two arguments: a `const std::vector<int>&` and a `std::function<int(int)>` callback. The `processVector` function should iterate through the input vector, apply the `std::function` callback to each element, and print the result of each application. Demonstrate its usage by passing a vector and a lambda (e.g., one that squares an integer or adds 5 to it) to `processVector`.

6.  **Stateful Predicate Functor for `std::count_if`**
    Create a functor class named `ThresholdChecker`. Its constructor should take an `int` argument representing a `threshold`. Overload its `operator()` to accept an `int` and return `true` if the input number is greater than the stored `threshold`, and `false` otherwise. Use an instance of `ThresholdChecker` as the predicate with `std::count_if` on a `std::vector<int>` to count how many numbers in the vector are above a specific threshold (e.g., count numbers greater than 5).

---

### Advanced

These problems involve more complex template metaprogramming, member function pointers, recursive lambdas, and performance considerations, pushing the boundaries of callable object usage.

1.  **Function Pointer to Member Function**
    Define a class named `Calculator` with a public non-static member function, for example, `int multiply(int a, int b)`. Declare a pointer to a function capable of pointing to `Calculator::multiply`. Create an instance of `Calculator` and use the member function pointer (with the `.*` or `->*` operator) to invoke `multiply` on your `Calculator` object, printing the result.

2.  **Functor as a Custom Comparator for `std::sort`**
    Design a functor class named `StringLengthComparator`. Its `operator()` should take two `const std::string&` arguments and return `true` if the first string's length is less than the second string's length, thus defining an ordering by length. Create a `std::vector<std::string>` and populate it with several strings of varying lengths. Use `std::sort` with an instance of `StringLengthComparator` to sort the vector by string length, then print the sorted vector.

3.  **Recursive Lambda for Factorial Calculation**
    Write a lambda expression that calculates the factorial of a given integer `n`. This lambda should be recursive, meaning it calls itself. To enable recursion for an anonymous lambda, you will need to store it in a `std::function` object, which provides the necessary self-referential capability. Demonstrate by calculating `factorial(5)`.

4.  **Overloaded Functor Operations**
    Create a class named `OperationPerformer`. Overload its `operator()` multiple times with different parameter types. For example:
    * `operator()(int a, int b)` that prints "Performing integer operation: sum = `a + b`".
    * `operator()(double a, double b)` that prints "Performing double operation: product = `a * b`".
    * `operator()(const std::string& s)` that prints "Processing string: `s.length()`".
    Demonstrate calling a single instance of `OperationPerformer` with arguments corresponding to each overloaded `operator()` to show its polymorphic behavior.

5.  **Callable Object Pipeline with `std::function`**
    Implement a function `createPipeline` that takes an `std::vector<std::function<int(int)>>` as input. This function should return a single `std::function<int(int)>` that represents a pipeline: when invoked, it passes its input through each callable in the vector sequentially, with the output of one serving as the input for the next. For example, if the vector contains `f1`, `f2`, `f3`, the returned function `pipeline(x)` should compute `f3(f2(f1(x)))`. Demonstrate with a pipeline that squares, then adds 5, then multiplies by 2.

6.  **Generic Callable Timer Function**
    Write a C++ generic function template named `timeExecution`. This function template should take two template parameters: a callable type `Callable` and a positive integer `iterations`. `timeExecution` should accept one argument of type `Callable`. Inside `timeExecution`, it should execute the provided `Callable` entity `iterations` number of times, measuring the total time taken using `std::chrono`. The function should then print the total execution time. Demonstrate `timeExecution` with a function pointer, a lambda (e.g., one that does a simple calculation), and a functor, all performing some non-trivial work to make timing noticeable.