# Function Pointers

**Function pointers** are powerful features in C++ that allow you to treat functions as data. Essentially, a function pointer is a variable that holds the memory address of an executable function. This capability enables a range of advanced programming techniques, such as making indirect function calls, passing functions as arguments to other functions, and implementing **callbacks**. It's important to note that function pointers, in their most basic form, can only point to non-member functions or **stateless lambdas** (lambdas that don't capture any variables from their surrounding scope).

-----

## Syntax

To declare a function pointer, its signature must precisely match the signature of the function it intends to point to. This includes the function's return type and the types of all its parameters, in the correct order.

```cpp
return_type (*pointer_name)(parameter_types);
```

Breaking down this syntax:

  * `return_type`: This is the data type that the function pointed to will return.
  * `(*pointer_name)`: The parentheses around `*pointer_name` are crucial. They indicate that `pointer_name` is a pointer. Without them, it would look like a function declaration returning a `return_type` pointer.
  * `(parameter_types)`: This lists the types of the parameters that the function pointed to expects, separated by commas.

-----

## Basic Usage

Let's look at how you declare a function pointer and then assign a function's address to it.

### Example: Declaring and Assigning a Function Pointer

```cpp
// Function definition
int add(int a, int b) {
    return a + b;
}

// Function pointer declaration: 'funcPtr' can point to a function that
// takes two integers and returns an integer.
int (*funcPtr)(int, int);

// Assign the 'add' function's address to 'funcPtr'.
// The address-of operator '&' is technically optional here,
// as the compiler implicitly converts the function name to its address.
funcPtr = add;
```

Once a function pointer holds the address of a function, you can invoke that function using the pointer.

### Example: Calling a Function via a Function Pointer

```cpp
// Call the 'add' function through 'funcPtr'.
// The dereference operator '*' is also optional here,
// as the compiler implicitly dereferences the function pointer for the call.
int result = funcPtr(3, 4);  // This effectively calls add(3, 4), and 'result' will be 7.
```

-----

## Array of Function Pointers

You can also create arrays that store multiple function pointers. This is incredibly useful for implementing dispatch tables or menus where different actions are performed based on an index or user input.

```cpp
// Define two simple functions
int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }

// Declare an array 'operations' that can hold two function pointers.
// Each pointer in the array must match the signature (int)(int, int).
int (*operations[2])(int, int) = { add, subtract };

// Call the 'add' function via the first element of the array
int result1 = operations[0](10, 5);  // Calls add(10, 5), result1 will be 15

// Call the 'subtract' function via the second element of the array
int result2 = operations[1](10, 5);  // Calls subtract(10, 5), result2 will be 5
```

-----

## Callbacks

A **callback** is a classic application of function pointers. It's a mechanism where you pass a function (the "callback" function) as an argument to another function. The receiving function can then "call back" or execute the passed function at a later, appropriate time. This is fundamental to event-driven programming and asynchronous operations.

```cpp
// A simple callback function
void callbackFunc(int value) {
    std::cout << "Callback executed with value: " << value << std::endl;
}

// A function that accepts a function pointer as an argument
void performAction(void (*callback)(int), int data) {
    std::cout << "Performing action..." << std::endl;
    // Call the function pointed to by 'callback'
    callback(data);
    std::cout << "Action completed." << std::endl;
}

// Usage:
// performAction passes 'callbackFunc' as the callback and 100 as data.
performAction(callbackFunc, 100);
```

In this example, `performAction` doesn't know *what* `callbackFunc` does, only that it expects an integer argument and returns `void`. This decoupling makes `performAction` highly reusable.

-----

## Pointer to Member Functions

While regular function pointers point to freestanding functions, **pointers to member functions** are specifically designed to point to non-static member functions of a class. Because member functions operate on a specific object instance, their pointers have a distinct syntax and require an object to be invoked.

### Syntax

```cpp
return_type (ClassName::*pointer_name)(parameter_types);
```

Here:

  * `ClassName::`: Specifies the class to which the member function belongs.
  * `(ClassName::*pointer_name)`: Indicates that `pointer_name` is a pointer to a member of `ClassName`.

### Example:

```cpp
#include <iostream>

class MyClass {
public:
    void greet() {
        std::cout << "Hello from MyClass!" << std::endl;
    }
    void farewell() {
        std::cout << "Goodbye from MyClass!" << std::endl;
    }
};

int main() {
    MyClass obj; // An instance of MyClass

    // Declare a pointer to a member function of MyClass.
    // It must take no arguments and return void.
    void (MyClass::*memFuncPtr)() = &MyClass::greet;

    // Call the member function through the pointer using the '.*' operator
    // for objects.
    (obj.*memFuncPtr)(); // Calls MyClass::greet on 'obj', outputs "Hello from MyClass!"

    // You can reassign the pointer to another member function
    memFuncPtr = &MyClass::farewell;

    // Call the newly assigned member function
    (obj.*memFuncPtr)(); // Calls MyClass::farewell on 'obj', outputs "Goodbye from MyClass!"

    // If you have a pointer to an object, use '->*'
    MyClass* objPtr = &obj;
    (objPtr->*memFuncPtr)(); // Calls MyClass::farewell on the object pointed to by 'objPtr'

    return 0;
}
```

The `.*` operator (or `->*` for pointers to objects) is used to invoke a member function through its pointer on a specific object instance.

-----

## Summary

  * **Function pointers** store addresses of free functions or static member functions, enabling indirect calls and dynamic execution flow.
  * They demand strict **signature matching** (return type and parameter types) for correct assignment and invocation.
  * **Member function pointers** are a specialized type designed for non-static class methods and require `.*` or `->*` syntax for invocation on an object instance.
  * Both types of pointers are invaluable for implementing **callbacks**, designing **dynamic dispatch** mechanisms, and creating highly **flexible APIs** that can adapt their behavior at runtime.

Understanding function pointers is a stepping stone to more advanced C++ features like `std::function` and lambdas, which often provide safer and more convenient alternatives for similar use cases.

Move on to the next section, [Lambda Expressions](LambdaExpressions.md), to learn about anonymous functions and their powerful capabilities in C++.