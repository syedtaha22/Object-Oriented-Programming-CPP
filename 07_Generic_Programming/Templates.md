# Template Basics

Templates are one of the most powerful features in C++, enabling a programming style called **generic programming**. Unlike writing code that only works for a specific data type, templates allow you to write functions and classes that can operate with any data type, making your code more flexible and reusable. This avoids duplication and allows you to express your algorithms and data structures in a type-independent way.

Generic programming using templates is a core part of modern C++ development. The Standard Template Library (STL), for example, is built almost entirely using templates, enabling generic containers like `std::vector` and algorithms like `std::sort` to work with any type seamlessly. Understanding how templates work is essential for writing efficient, maintainable, and scalable C++ code.

This document introduces the fundamental concepts of **function templates** and **class templates**, covering their syntax, basic usage, and how to work with multiple template parameters, including non-type parameters. It also explains the proper way to define member functions outside the class template, which is a common source of confusion.

-----

## 1\. Function Templates

Function templates allow you to write a blueprint for a function where the data type is a parameter. Instead of creating multiple versions of the same function for different types (e.g., one for `int`, one for `double`, etc.), you write a single generic function. The compiler then generates specific versions of this function as needed, based on how you use it. This process, known as **template instantiation**, occurs at compile time, ensuring that the generated code is highly optimized and type-safe.

This mechanism greatly reduces code duplication and helps maintain consistency because you only write the logic once. The template parameter acts as a placeholder that is replaced by the compiler with the actual data type during compilation.

### Syntax

A function template begins with the `template` keyword, followed by one or more template parameters enclosed in angle brackets (`<>`). The most common template parameter is a **type parameter**, declared with `typename` or `class` (both keywords are interchangeable here). Then you write the function using this parameter as a normal type.

```cpp
template <typename T>
ReturnType functionName(ParameterList) {
    // Function body using T
}
```

### Example: Maximum of Two Values

One of the classic examples is a function that returns the maximum of two values. Instead of writing separate `max` functions for `int`, `double`, or other types, you define a function template:

```cpp
template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}
```

When you call `max(3, 5)`, the compiler deduces `T` as `int`. When you call `max(2.5, 1.7)`, it deduces `T` as `double`. This automatic deduction of types makes templates incredibly convenient to use. You can also explicitly specify the type like `max<int>(7, 2)`, though this is rarely needed thanks to the powerful **type inference** or **template argument deduction** capabilities of C++.

### Why Use Function Templates?

  * **Avoid code duplication:** Write the function logic once and reuse it for various data types, significantly reducing boilerplate code.
  * **Type safety:** The compiler strictly checks types at compile time, preventing type-related errors that might arise from manual type casting in non-generic code.
  * **Maintainability:** Any bug fix or improvement to the generic function immediately applies to all its instantiations, simplifying maintenance efforts.
  * **Performance:** Since the code is generated at compile-time, there's no runtime overhead associated with dynamic dispatch or type checking, leading to highly efficient code.

## 2\. Class Templates

Class templates extend the idea of generic programming to classes, allowing you to create generic data structures or wrappers that work with any type. Instead of writing separate versions of a class for different types, you write one class template that can be instantiated with any type.

This is the foundation for most generic containers, smart pointers, and other reusable components in C++. By parameterizing the type, your class can store or manipulate data of any type safely and efficiently, making your code highly adaptable and robust.

### Syntax

Similar to function templates, class templates start with the `template` keyword and type parameters:

```cpp
template <typename T>
class ClassName {
    // Members using T
};
```

Inside the class, you can use `T` just like a regular type for member variables, function parameters, and return types. This allows the class to behave as a blueprint for creating type-specific instances.

### Example: A Simple Box Class

Here is a simple generic container class `Box` that holds a value of any type:

```cpp
template <typename T>
class Box {
    T value;                     // Holds the value of generic type T
public:
    Box(T v) : value(v) {}      // Constructor initializing value
    T get() const { return value; } // Getter to retrieve the value
};
```

You can create `Box` objects for `int`, `double`, `std::string`, or any other type, demonstrating the versatility of class templates:

```cpp
Box<int> intBox(123);
Box<std::string> strBox("Hello World");
```

This flexibility means you don't need to rewrite the `Box` class for every data type you want to store; the template handles it all.

### Defining Member Functions Outside the Class Template

In C++, you can define class member functions inside the class body or outside. For class templates, defining member functions outside the class body requires repeating the `template` declaration and specifying the template parameters for the class. This explicit qualification is crucial for the compiler to correctly associate the member function with the correct template instance.

This might seem verbose, but it is necessary to help the compiler correctly associate the member function with the right template instance. It also promotes cleaner separation between the class declaration (what the class does) and its implementation (how it does it).

### Syntax for External Definitions

```cpp
template <typename T>
ReturnType ClassName<T>::memberFunction(ParameterList) {
    // Implementation
}
```

### Example

Consider a `Wrapper` class template:

```cpp
template <typename T>
class Wrapper {
    T data;
public:
    Wrapper(T val);
    void show() const;
};

// Definition of the constructor outside the class
template <typename T>
Wrapper<T>::Wrapper(T val) : data(val) {}

// Definition of the show method outside the class
template <typename T>
void Wrapper<T>::show() const {
    std::cout << data << std::endl;
}
```

This separation allows cleaner class declarations and easier code organization, especially for complex classes with many member functions. It can also improve readability by keeping the interface (the class declaration) concise.

## 3\. Templates with Multiple Parameters

Templates are not limited to just one type parameter. You can specify multiple type parameters or even **non-type parameters**, such as integral constants, pointers, or references that are known at compile time.

This feature makes templates extremely flexible and powerful, allowing you to encode both type and value information into your generic code. This greatly expands the scope of what can be achieved with generic programming.

### Multiple Type Parameters

You can define templates with multiple type parameters by listing them in the template declaration. This enables you to write generic classes or functions that operate on more than one type at the same time, providing a highly adaptable design.

### Syntax

```cpp
template <typename T1, typename T2>
class Pair {
    T1 first;
    T2 second;
public:
    Pair(T1 a, T2 b) : first(a), second(b) {}
};
```

This `Pair` class can hold two related values of possibly different types, like an integer and a double, mirroring common real-world data relationships.

### Usage

```cpp
Pair<int, double> p(42, 3.14);
```

This demonstrates how `Pair` can be instantiated with distinct types, creating a versatile data structure.

### Non-Type Template Parameters

Templates can also accept **non-type parameters** — values known at compile time. These are often integral constants like `int`, `char`, or pointers to objects with static storage duration. Non-type parameters are distinct from type parameters because they represent concrete values rather than placeholders for types.

Non-type parameters allow the compiler to generate code that depends on fixed values, such as array sizes or compile-time flags, offering more control over behavior without runtime cost. This is particularly useful for optimizing performance or enforcing constraints at compile time.

### Syntax

```cpp
template <int a, int b>
int add() {
    return a + b;
}
```

### Usage

```cpp
int result = add<2, 3>();  // result is 5
```

Non-type parameters enhance template flexibility and are heavily used in low-level or performance-critical code, such as fixed-size arrays or compile-time arithmetic operations.

### Important Considerations

  * **Template Instantiation and Code Bloat:** Templates are resolved and instantiated by the compiler, meaning the compiler generates specialized code for each unique set of template arguments used in your program. While this provides great flexibility, it can lead to **code bloat** if templates are overused or instantiated with many different types, as the compiled executable will contain multiple versions of the same code.
  * **Header-Only Design:** Because templates require full definitions to be available at the point of instantiation, template code is usually placed entirely in **header files** (e.g., `.h` or `.hpp`) rather than source files (e.g., `.cpp`). This ensures the compiler can generate the necessary instances for every translation unit that uses the template. Attempting to separate template declarations and definitions across `.h` and `.cpp` files often leads to "unresolved external symbol" errors during linking.
  * **Complex Error Messages:** Errors in templates can be more complex to understand and debug because they often happen during template instantiation and can involve lengthy, unfamiliar compiler messages. These "template metaprogramming errors" can be intimidating for beginners. Therefore, it’s best to start with simple templates and gradually increase complexity, thoroughly testing each step. Debugging techniques like `static_assert` and `concept` (in C++20) can help provide clearer error messages.

## Summary

  * **Function and class templates** are fundamental C++ features that enable writing generic, type-independent code.
  * Templates significantly **reduce code duplication** and **improve maintainability** by allowing a single implementation to serve many different data types.
  * You can define class template member functions **outside the class body**, but this requires repeating the template declaration with the appropriate template parameters.
  * Templates are highly flexible and can accept **multiple parameters**, including both type parameters (`typename T`) and **non-type parameters** (e.g., `int N`), enabling compile-time customization.
  * Mastering these basics is essential for understanding more advanced template features like specialization, partial specialization, and the intricacies of type deduction.

Proceed to [TypeDeduction.md](TypeDeduction.md) to explore how C++ automatically infers template parameters and uses utilities like `auto` and `decltype` to further improve template usability and flexibility.