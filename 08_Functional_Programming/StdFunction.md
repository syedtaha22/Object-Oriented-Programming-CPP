# The Functional Library in C++

The C++ Standard Library’s **functional** utilities provide a robust and highly flexible set of tools for working with **callable entities**. At the heart of this library is `std::function`, a versatile **polymorphic function wrapper**. This means `std::function` can store, copy, and invoke virtually any callable object, as long as it matches a specific function signature you define. This remarkable versatility makes it a go-to choice for scenarios requiring abstracting callable behavior.

`std::function` is capable of holding a wide array of callable types, including:

  * **Plain functions:** Regular, standalone functions defined at global or namespace scope.
  * **Function pointers:** Variables that store the memory address of such plain functions.
  * **Lambda expressions:** Anonymous functions, even those with internal state due to **captured variables**.
  * **Functors:** Objects from classes or structs that have overloaded the function call operator (`operator()`).

-----

## General Syntax of `std::function`

To use `std::function`, you first need to include the `<functional>` header. The syntax for declaring a `std::function` variable specifies the signature of the callable it will wrap:

```cpp
#include <functional>

std::function<ReturnType(ParameterTypes...)> func;
```

Here, `func` is declared as a variable that can store any callable entity whose signature precisely matches `ReturnType` and `ParameterTypes...`. This makes `std::function` an incredibly powerful type for defining interfaces that accept various callable objects.

-----

## Key Features of `std::function`

`std::function` offers several compelling features that make it indispensable in modern C++ programming:

  * **Type Erasure:** This is one of `std::function`'s most significant capabilities. It "erases" the concrete type of the callable it wraps, allowing you to treat diverse callable types (like a lambda, a function pointer, or a functor) uniformly. You don't need to know the specific type of the callable when working with a `std::function` object; you only need to know its signature.
  * **Type Safety:** Despite type erasure, `std::function` remains rigorously type-safe. It ensures that only callable entities whose signatures are *compatible* with the `std::function`'s declared signature can be assigned to it. The compiler enforces these rules, preventing mismatches at compile time.
  * **Copyable and Assignable:** Unlike raw function pointers (especially member function pointers), `std::function` objects are regular value types. They can be easily copied, assigned, passed as arguments to functions, and returned from functions, just like any other object. This makes them highly manageable in complex program flows.
  * **Supports Stateful Callables:** A major advantage over traditional function pointers is `std::function`'s ability to store lambdas with captures or functors that maintain internal state. This is because `std::function` internally manages the lifetime of the captured data or functor object, ensuring it's available when the `std::function` is invoked.
  * **Some Overhead:** While extremely flexible, `std::function` does come with a slight runtime cost. It often uses dynamic memory allocation internally (e.g., to store captured state or functor objects), which can introduce some overhead compared to raw function pointers or direct lambda calls that are resolved at compile time. For performance-critical loops where the exact callable type is known at compile time, directly using a lambda or a template might be more efficient.

-----

## Example 1: Storing a Lambda

Lambdas are a perfect fit for `std::function`, especially when they capture variables.

```cpp
#include <iostream>
#include <functional> // Required for std::function

int main() {
    // A lambda that captures nothing and returns void, takes no parameters.
    // std::function<void()> is the correct type to wrap it.
    std::function<void()> greet = []() {
        std::cout << "Hello, std::function!" << std::endl;
    };
    greet();  // Invokes the lambda, prints "Hello, std::function!"
    return 0;
}
```

-----

## Example 2: Storing a Function Pointer

`std::function` can easily wrap traditional C-style function pointers, providing a modern, type-safe interface for them.

```cpp
#include <iostream>
#include <functional>

// A regular C++ function
int add(int a, int b) {
    return a + b;
}

int main() {
    // std::function<int(int, int)> is the correct type for a function
    // that takes two ints and returns an int.
    std::function<int(int, int)> op = add;
    std::cout << op(5, 3) << std::endl;  // Invokes 'add(5, 3)', output: 8
    return 0;
}
```

-----

## Example 3: Using `std::function` with a Functor

Functors, with their ability to maintain state, also seamlessly integrate with `std::function`.

```cpp
#include <iostream>
#include <functional>

// A simple functor class that multiplies by a stored factor
class Multiply {
    int factor; // The state of this functor
public:
    Multiply(int f) : factor(f) {}
    // The overloaded function call operator
    int operator()(int x) const { return x * factor; }
};

int main() {
    // Create an instance of our functor, configured to multiply by 4
    Multiply times4(4);

    // std::function<int(int)> matches the signature of Multiply::operator().
    // We can assign our 'times4' functor instance to it.
    std::function<int(int)> func = times4;
    std::cout << func(7) << std::endl;  // Invokes times4.operator()(7), output: 28
    return 0;
}
```

-----

## Summary

`std::function` is a powerful and flexible **polymorphic function wrapper** in C++ that enables uniform handling of any callable object that matches a given function signature. It excels at abstracting away the underlying callable type, providing **type safety**, and supporting **stateful callables** like lambdas with captures and functors. While it might introduce a minor runtime overhead compared to compile-time resolutions, its benefits in terms of flexibility, ease of use, and integration with modern C++ programming patterns (like callbacks and event handlers) make it an indispensable tool in the `functional` library. It's often the best choice when you need to store or pass around callable behavior without knowing its exact concrete type at compile time.

See [examples/](examples/) for more practical examples of using `std::function` in various contexts, including callbacks, event handling, and more complex scenarios.