# Lambda Expressions

A **lambda function** (often simply called a **lambda expression**) in C++ is a powerful and concise feature introduced in C++11 that allows for the creation of anonymous, inline functions directly within your code. Think of them as miniature functions that you can define and use on the spot, without the need for a separate named function declaration. This capability is incredibly useful for situations where you need a small piece of executable code, often to be passed as an argument to algorithms or for quick, one-off operations. Lambdas effectively serve as compact **function objects** (or **functors**), and they can seamlessly integrate wherever traditional function pointers or function objects are expected, significantly improving code readability and expressiveness.

## Syntax

The basic structure of a lambda expression is highly recognizable due to its distinct components:

```cpp
[capture](parameters) -> return_type {
    // function body
}
```

## Lambda Components

Each part of the lambda syntax serves a specific purpose, contributing to its flexibility and power:

### Capture Clause `[]`

The capture clause is the most unique and powerful aspect of lambdas. It specifies which variables from the surrounding scope (the scope where the lambda is defined) are accessible inside the lambda's body, and *how* they are accessible.

  * **Capture by Value (`[x]`):** When a variable is captured by value, a *copy* of that variable is made at the time the lambda is created. Any modifications to this captured copy inside the lambda's body will *not* affect the original variable in the outer scope. This is useful when the original variable might go out of scope before the lambda is executed, as the lambda holds its own independent copy.
  * **Capture by Reference (`[&x]`):** When a variable is captured by reference, the lambda holds a *reference* to the original variable. This means that any modifications to the captured variable inside the lambda *will* directly affect the original variable in the outer scope. This is powerful for modifying external state, but it comes with a **warning**: if the original variable goes out of scope *before* the lambda is executed, accessing the captured reference will result in **undefined behavior**, as it would be a dangling reference.

### Parameters `()`

The parameter list defines the input arguments that the lambda accepts, just like regular function parameters.

  * **Explicit Types:** You can explicitly specify the types of parameters, such as `(int x, float y)`.
  * **Generic Lambdas with `auto` (C++14 and later):** For increased flexibility, you can use `auto` for parameters, making the lambda a "generic lambda" that can operate on various argument types. For example, `[](auto a, auto b) { return a + b; }`.
  * **Optional:** The parameter list can be omitted entirely if the lambda does not require any input arguments, for example `[]() { std::cout << "Hello"; }`.

### Return Type `->`

The `-> return_type` syntax explicitly specifies what the lambda returns.

  * **Optional Specification:** In many simple cases, the return type can be omitted. The compiler is usually smart enough to **automatically deduce** the return type based on the expressions within the lambda's body.
  * **Explicit Specification for Clarity or Complexity:** For more complex lambdas, especially those with multiple return paths or type conversions, explicitly specifying the return type can improve clarity or be necessary if the compiler cannot deduce it unambiguously.

### Function Body `{}`

The function body contains the executable code of the lambda.

  * **Enclosed in Curly Braces:** Like any C++ function, the code is enclosed within curly braces `{}`.
  * **Valid C++ Statements:** The body can contain any valid C++ statements, including declarations, loops, conditionals, and calls to other functions.
  * **Consistent Return Types:** If the lambda returns a value, all return statements within its body must result in expressions of compatible types (or the explicitly specified return type).

# Lambda Captures in C++

Understanding capture mechanisms is key to effectively using lambdas for various scenarios.

## 1\. Capture by Value

When you capture a variable by value, the lambda gets its own independent copy of that variable at the time the lambda is defined.

```cpp
int x = 10;
// Capture x by value
auto lambda = [x]() {
    std::cout << "Captured by value: " << x << std::endl; // x is 10
};
x = 20; // Original x changes
lambda(); // Output: Captured by value: 10 (because the lambda copied x=10)
```

## Key Points:

  * **Independent Copy:** The lambda stores an independent copy of the variable. Changes to the original variable outside the lambda do not affect the captured copy.
  * **Original Can Go Out of Scope Safely:** Since the lambda holds a copy, the original variable can be destroyed (e.g., if it's a local variable in a function that returns) without affecting the lambda's ability to access its captured value. This makes captured-by-value lambdas generally safer for asynchronous operations or when the lambda might outlive its creation scope.
  * **Cannot Modify Captured Value (Unless `mutable`):** By default, captured-by-value variables are `const` within the lambda. To modify a captured-by-value variable inside the lambda, you must declare the lambda as `mutable` after the parameter list:
    ```cpp
    int y = 5;
    auto mutableLambda = [y]() mutable {
        y += 1; // This is allowed because of 'mutable'
        std::cout << "Modified captured value: " << y << std::endl;
    };
    mutableLambda(); // Output: Modified captured value: 6 (original y is still 5)
    ```

## 2\. Capture by Reference

Capturing by reference allows the lambda to access and modify the original variable from the outer scope.

```cpp
int x = 10;
// Capture x by reference
auto lambda = [&x]() {
    x += 5; // Modifies the original x
    std::cout << "Captured by reference: " << x << std::endl;
};
lambda(); // Output: Captured by reference: 15 (original x is now 15)
std::cout << "Original x after lambda: " << x << std::endl; // Output: Original x after lambda: 15
```

**Warning:**
This is a powerful feature but comes with a critical caveat. **Undefined behavior** will occur if the original variable goes out of scope (is destroyed) *before* the lambda executes. The lambda would then be holding a "dangling reference" to memory that is no longer valid. This risk makes capture-by-reference less suitable for lambdas that might be stored and executed much later or in different threads, unless you can guarantee the lifetime of the referenced variable.

## 3\. Capture All by Value (`[=]`)

This shorthand captures all accessible variables from the surrounding scope that are mentioned in the lambda's body *by value*.

```cpp
int a = 10;
double b = 3.14;
auto lambda = [=]() { // a and b are captured by value
    std::cout << "a = " << a << ", b = " << b << std::endl;
};
lambda(); // Output: a = 10, b = 3.14
```

While convenient, be cautious with `[=]` in complex scenarios, as it might inadvertently capture large objects by value, leading to performance issues or unexpected behavior if `mutable` is used.

## 4\. Capture All by Reference (`[&]`)

This shorthand captures all accessible variables from the surrounding scope that are mentioned in the lambda's body *by reference*.

```cpp
int a = 10;
int b = 20;
auto lambda = [&]() { // a and b are captured by reference
    a += 5;
    b += 10;
    std::cout << "a = " << a << ", b = " << b << std::endl;
};
lambda(); // Output: a = 15, b = 30 (original a and b are modified)
```

Like individual reference captures, `[&]` carries the risk of dangling references if the lambda outlives the captured variables. Use with care, especially in asynchronous contexts.

### Implicit `this` Capture

When a lambda is defined inside a non-static member function of a class, it can implicitly capture the `this` pointer.

  * **`[this]`:** Explicitly captures `this` by value. Allows access to member variables and functions.
  * **`[=]`:** Implicitly captures `this` by value if any member is used.
  * **`[&]`:** Implicitly captures `this` by reference if any member is used.

Capturing `this` allows the lambda to interact with the object it was created within.

# Calling Lambdas

Lambdas, once defined, can be called in several ways, similar to regular functions or function objects.

## Immediate Invocation (IIFE - Immediately Invoked Function Expression)

A lambda can be defined and executed immediately after its definition. This is useful for self-contained blocks of code that need to run once.

```cpp
int main() {
    // A lambda defined and invoked immediately
    []() {
        std::cout << "Hello, World!" << std::endl;
    }(); // The '()' after the lambda definition triggers its immediate execution
}
```

## With Parameters

You can pass arguments directly to an immediately invoked lambda, just like a regular function call.

```cpp
// A lambda that takes two integers and prints their sum, invoked immediately
[](int a, int b) {
    std::cout << "Sum: " << a + b << std::endl;
}(3, 4); // Output: Sum: 7
```

## Storing Lambdas

Lambdas can be stored in variables of type `auto` (as the compiler creates a unique, unnamed type for each lambda) or `std::function` (a general-purpose polymorphic function wrapper).

```cpp
auto myLambda = [](int x) {
    return x * x;
};
int result = myLambda(5); // result is 25

std::function<void()> sayHello = [](){
    std::cout << "Hello from std::function!" << std::endl;
};
sayHello();
```

## With STL Algorithms

One of the most common and powerful uses of lambdas is as predicates or custom operations with algorithms from the C++ Standard Template Library (STL), like `std::sort`, `std::for_each`, `std::find_if`, etc.

```cpp
#include <vector>
#include <algorithm>
#include <iostream>

std::vector<int> vec = {5, 2, 8, 1, 9};

// Sort the vector using a lambda as the comparison predicate
std::sort(vec.begin(), vec.end(), [](int a, int b){
    return a < b; // Sorts in ascending order
});

for (int val : vec) {
    std::cout << val << " "; // Output: 1 2 5 8 9
}
std::cout << std::endl;
```


## Summary: Lambda Expressions in C++

* Lambdas are anonymous, inline functions defined directly within code for concise and expressive behavior.
* Syntax includes:

  * Capture clause `[]` to specify how variables from the surrounding scope are accessed (by value or reference).
  * Parameter list `()`
  * Optional return type `-> return_type`
  * Function body `{}`
* Capture mechanisms:

  * Explicit captures: `[x]` (by value), `[&x]` (by reference)
  * Implicit captures: `[=]` (all by value), `[&]` (all by reference)
  * Lambdas in member functions can implicitly capture `this` pointer.
* Common uses:

  * Custom predicates for STL algorithms
  * Callbacks in asynchronous operations
  * Simplifying code when passing behavior as parameters
* Support immediate invocation (IIFE) for one-off execution.
* Can be stored in variables declared with `auto` or in `std::function` objects.
* Return types are usually deduced automatically but can be explicitly specified if needed.
* The `mutable` keyword allows modification of variables captured by value inside the lambda body.

For more examples of how they are used, check out the [examples/](examples/) directory.

Check out the next section, [Functors](Functors.md), to learn about function objects and their advantages over lambdas and function pointers.