# Practice Problems – Generic Programming

This problem set is designed to reinforce your understanding of function templates, class templates, and template-based design in C++. Generic programming, through the use of templates, is a cornerstone of modern C++ development, allowing you to write highly flexible, reusable, and type-safe code. These exercises will guide you through various aspects of template usage, from basic syntax to advanced compile-time techniques.

The problems are categorized into three difficulty levels: **Easy**, **Medium**, and **Hard**. It is recommended to start with the Easy problems to build a solid foundation with function templates and static arrays. As you gain confidence, progress to the Medium and Hard problems, which will challenge you with class templates, variadic templates, and more complex compile-time logic.

Solving these problems will not only solidify your theoretical understanding but also provide practical experience in debugging and refining templated code, preparing you for real-world C++ development scenarios.

-----

## Easy

These problems focus on the fundamental concepts of function templates and their basic usage. They are designed to be straightforward and help you get comfortable with declaring and using `typename` or `class` template parameters.

2.  **Swap Function**
    Write a function template `swap<T>(T& a, T& b)` that efficiently swaps the values of two variables of any given type `T`.

3.  **Fill Array**
    Create a function template `fillArray<T, int N>(T (&arr)[N], T value)` that initializes every element of a static-sized C-style array with a specified `value`.

4.  **Compare Values**
    Implement a function template `isEqual<T>(T a, T b)` that returns `true` if the two input values of type `T` are equivalent, and `false` otherwise.

5.  **Default Value Provider**
    Write a function template `getDefault<T>()` that returns a default-constructed object of type `T`.

-----

## Medium

These problems build upon the Easy concepts by introducing class templates, more complex function template scenarios, and compile-time size considerations. You'll start designing generic data structures and algorithms.

6.  **Fixed-Size Circular Buffer**
    Design a class template `CircularBuffer<T, int Capacity>` that functions as a fixed-size queue, storing up to `Capacity` elements in FIFO (First-In, First-Out) order. Utilize a static array internally. Provide public methods: `push()` to add an element, `pop()` to remove and return the oldest element, and `peek()` to view the oldest element without removing it.

7.  **Reverse Array**
    Write a function template `reverseArray<T, int N>(T (&arr)[N])` that reverses the contents of a static array in place.

8.  **Clamp Function**
    Implement a function template `clamp<T>(T val, T min, T max)` that returns `val` constrained within the inclusive range defined by `min` and `max`. Assume all arguments (`val`, `min`, `max`) are of the same type `T`.

9.  **Type-Specific Function Behavior Using Overloading**
    Write overloaded function templates `printValue` for `int`, `float`, and a generic template for all other types. Each overload should print a different, distinct message to the console without using `if constexpr`.

10. **Fixed-Dimension Matrix**
    Create a class template `Matrix<T, int Rows, int Cols>` that stores a fixed-size 2D array. Provide methods for element access (e.g., using `operator()`) and assignment.

-----

## Hard

These problems delve into more advanced template features, including variadic templates, compile-time type manipulation, and perfect forwarding. They are designed to push your understanding of generic programming to a higher level.

11. **Recursive Tuple Implementation**
    Implement a variadic class template `Tuple<Types...>` that can hold an arbitrary number of elements of different types. Support construction and recursive printing of all elements.

12. **Smaller Type Selector**
    Create a template struct `SmallerType<T1, T2>` with a nested type alias `type` that resolves to the "smaller" of the two types `T1` and `T2` based on their `sizeof` value.

13. **Perfect Forwarding Factory Function**
    Implement a function template `makeInstance<T, Args...>(Args&&... args)` that takes an arbitrary number of arguments and perfectly forwards them to construct and return an object of type `T`.

14. **Fixed-Dimension Vector Class**
    Write a class template `Vector<T, int Dim>` that holds `Dim` elements of type `T` in a static array, with member functions for element access (e.g., `operator[]`), vector addition, and scalar multiplication.

-----

Start with the **Easy** problems to build confidence with function templates and static arrays, then progress to the **Medium** and **Hard** problems to master class templates, variadic templates, and compile-time logic.

See the [examples/](./examples/) folder for reference implementations of core concepts.