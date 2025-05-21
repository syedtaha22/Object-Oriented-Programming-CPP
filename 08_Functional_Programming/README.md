# Function Pointers, Lambdas, and Functors in C++

This module contains notes and explanations about key callable concepts in C++: **function pointers**, **lambdas**, **functors**, and **`std::function`**. Understanding these will enhance your ability to write flexible, reusable, and modern C++ code.

---

## Topics Covered

1. **Function Pointers**

   * What function pointers are
   * Syntax and usage
   * Calling functions indirectly
   * Passing functions as arguments
   * Common use cases like callbacks

2. **Lambda Expressions**

   * Defining anonymous functions
   * Capturing variables by value, reference, or mixed
   * Using `mutable` lambdas
   * Return type deduction and explicit return types

3. **Functors (Function Objects)**

   * Defining callable classes with `operator()`
   * Advantages over function pointers
   * Using functors with STL algorithms

4. **Function Wrappers**

   * Using `std::function` for type-safe, polymorphic callables
   * Storing function pointers, lambdas, and functors
   * When and why to prefer `std::function` over raw pointers

---

## Folder Structure

* [FunctionPointers.md](FunctionPointers.md): Covers syntax and usage of function pointers in C++.
* [LambdaExpressions.md](LambdaExpressions.md): Introduces lambdas, captures, and related syntax.
* [Functors.md](Functors.md): Explains function objects and their advantages.
* [StdFunction.md](StdFunction.md): Details `std::function` usage and best practices.

---

Start with [FunctionPointers.md](FunctionPointers.md) to learn how functions can be handled as first-class objects in C++, then proceed to lambdas, functors, and function wrappers.