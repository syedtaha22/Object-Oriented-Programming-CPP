# Functors (Function Objects)

**Functors**, also known as **function objects**, are a powerful concept in C++ that allows you to create objects which can be called just like regular functions. This is achieved by overloading the function call operator, `operator()`, within a class or struct. By making an object callable, functors bridge the gap between traditional functions and objects, offering a unique blend of flexibility and statefulness.

-----

## What is a Functor?

At its core, a functor is simply any object for which the `operator()` member function has been defined. This special operator gives instances of that class the ability to be invoked using the familiar function call syntax (e.g., `myObject(arg1, arg2)`).

The key distinguishing feature that sets functors apart from plain functions or raw function pointers is their capacity to **maintain state**. Unlike a standalone function that operates solely on its input arguments, a functor can hold data members. These data members can store information that influences the functor's behavior across multiple calls, allowing it to remember past operations or carry configuration settings.

-----

## General Syntax

Creating a functor involves defining a class or struct and implementing one or more `operator()` member functions within it.

```cpp
class FunctorName {
public:
    // Define operator() with any signature you need.
    // It can take parameters and return a value, just like a regular function.
    ReturnType operator()(ParameterTypes) {
        // This is where the functor's logic resides.
        // It can access member variables of FunctorName.
    }
};
```

Once you've defined your functor class, you can create an instance of it and then use that instance as if it were a function:

```cpp
FunctorName myFunctorInstance;
// Now you can "call" myFunctorInstance, passing arguments as needed.
auto result = myFunctorInstance(arguments);
```

-----

## Example: Simple Functor

Let's illustrate with a practical example. Imagine you want a function-like entity that always multiplies its input by a specific, pre-configured factor. A functor is perfect for this.

```cpp
#include <iostream>

class MultiplyBy {
    int factor; // This is the state the functor maintains

public:
    // Constructor to set the factor when the functor is created
    MultiplyBy(int f) : factor(f) {}

    // Overload the function call operator.
    // It takes an integer 'x' and returns an integer.
    // 'const' indicates that calling this operator won't change the functor's internal state.
    int operator()(int x) const {
        return x * factor; // Uses the stored 'factor'
    }
};

int main() {
    // Create a functor instance that will multiply by 3
    MultiplyBy times3(3);
    // Call the functor like a function
    std::cout << times3(10) << std::endl;  // Output: 30

    // Create another functor instance that will multiply by 5
    MultiplyBy times5(5);
    std::cout << times5(10) << std::endl;  // Output: 50
    return 0;
}
```

In this example, `MultiplyBy` is a functor. Its `operator()` multiplies the input by the `factor` that was provided during its construction. This clearly demonstrates how a functor can **maintain state** (`factor`) that influences its callable behavior.

-----

## Advantages of Functors over Function Pointers

While function pointers can also enable indirect function calls, functors offer several compelling advantages:

  * **Statefulness:** This is perhaps the most significant benefit. Functors can hold internal data members, allowing them to carry context or configuration information between calls. Function pointers, on the other hand, are stateless; they only store an address.
  * **Compile-Time Optimization (Inlining):** Because functors are objects, the compiler often has more information about them at compile time. This frequently allows the compiler to **inline** functor calls, potentially leading to better performance by avoiding the overhead of a traditional function call. Function pointer calls are generally harder for the compiler to inline.
  * **Type Safety:** Functors are strongly typed objects. The compiler can perform robust type checking at compile time, leading to fewer runtime errors compared to raw function pointers which can sometimes be less type-safe in complex scenarios.
  * **Flexible Interfaces:** A class can overload `operator()` multiple times with different parameter lists, allowing a single functor object to exhibit different behaviors based on the arguments provided. Functors can also expose other public member functions, providing a richer interface than a simple function pointer.
  * **Inheritance and Polymorphism:** Functors, being classes, can participate in inheritance hierarchies and polymorphism, though this is less common with `operator()` directly and more often achieved through `std::function`.

-----

## Using Functors with STL Algorithms

Functors truly shine when used with the C++ Standard Template Library (STL) algorithms. Many STL algorithms (like `std::sort`, `std::for_each`, `std::find_if`, `std::transform`, etc.) accept a function object as an argument to customize their behavior.

Example:

```cpp
#include <algorithm> // For std::count_if
#include <iostream>
#include <vector>

// Functor to check if a number is even
class IsEven {
public:
    // This operator() takes an int and returns a bool
    bool operator()(int x) const {
        return x % 2 == 0;
    }
};

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6};

    // Use std::count_if with an instance of our IsEven functor.
    // IsEven() creates a temporary functor object.
    auto count = std::count_if(numbers.begin(), numbers.end(), IsEven());
    std::cout << "Number of even elements: " << count << std::endl;  // Output: 3
    return 0;
}
```

In this example, `IsEven` is a functor that acts as a **predicate** for `std::count_if`. It defines the custom logic for what it means for an element to be "counted." This illustrates how functors allow you to inject custom behavior into generic algorithms without writing a separate named function for every specific check.

-----

## Summary

  * **Functors** are objects created from classes or structs that **overload the function call operator (`operator()`)**, making them callable like functions.
  * Their primary advantage over function pointers is their ability to **maintain state**, allowing them to store data that influences their behavior across multiple invocations.
  * Functors often lead to better **performance** due to compiler inlining opportunities and provide enhanced **type safety**.
  * They integrate seamlessly with **STL algorithms**, enabling you to customize the behavior of generic algorithms by providing stateful and flexible operations.

Functors, along with function pointers and lambda expressions, are crucial tools in C++ for implementing flexible and expressive code, especially in the context of generic programming and algorithms.

See [StdFunction.md](StdFunction.md) for more details on how functors can be used with `std::function` to create type-safe, polymorphic callables.