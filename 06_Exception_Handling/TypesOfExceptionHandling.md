# Types of Exceptions

In C++, exceptions can be classified into two broad categories: **built-in exceptions** and **user-defined exceptions**. Understanding both types of exceptions is essential for effective error handling in programs, as it allows developers to manage both common runtime errors and custom errors specific to their application.

This section will cover:

- **Built-in Exceptions**: Standard exceptions provided by the C++ Standard Library.
- **User-defined Exceptions**: Exceptions that can be created by the developer to represent specific error conditions.
- **Catching Multiple Exception Types**: How to handle different types of exceptions using multiple `catch` blocks.

---

## Built-in Exceptions

C++ provides a set of standard exceptions that are defined in the `<stdexcept>` header file. These exceptions are typically used for common runtime errors, and they help ensure that your program reacts to predictable errors without requiring custom error classes.

### Standard Exception Hierarchy

The C++ Standard Library defines a hierarchy of exception classes, which all derive from the base class `std::exception`. Here is a basic breakdown:

1. **`std::exception`**: The base class for all standard exceptions. It provides a `what()` function, which returns a std::string describing the exception.
2. **`std::logic_error`**: Used to indicate errors in the program's logic that should have been caught before runtime.
    - Examples: `std::invalid_argument`, `std::out_of_range`, etc.
3. **`std::runtime_error`**: Indicates errors that occur during program execution, typically due to unpredictable conditions.
    - Examples: `std::overflow_error`, `std::underflow_error`, etc.
4. **Other Specific Exceptions**: These include exceptions for specific error types like `std::bad_alloc` (for memory allocation failures) and `std::ios_base::failure` (for I/O stream errors).

### Example of Built-in Exception Handling

```cpp
#include <iostream>
#include <stdexcept>

void mayThrow(int num) {
    if (num == 0)
        throw std::invalid_argument("Argument cannot be zero");
    if (num < 0)
        throw std::out_of_range("Argument must be positive");
    std::cout << "Valid input: " << num << std::endl;
}

int main() {
    try {
        mayThrow(0);
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
}
```

**Output:**
```
Caught exception: Argument cannot be zero
```

Here, `std::invalid_argument` is thrown when an invalid argument is provided. The specific exception is caught in the corresponding `catch` block, allowing you to handle different error conditions separately.

---

## User-defined Exceptions

While built-in exceptions are useful for handling common error cases, there are situations where you might want to define custom exceptions for specific error conditions relevant to your application. In such cases, you can create your own exception classes.

### Defining a Custom Exception

To define a user-defined exception, create a class that inherits from `std::exception` (or one of its derived classes). The key method to implement is `what()`, which returns an error message when the exception is thrown.

### Example of User-defined Exception

```cpp
#include <iostream>
#include <exception>

class MyCustomException : public std::exception {
public:
    const char* what() const noexcept override {
        return "My custom exception occurred!";
    }
};

void testCustomException() {
    throw MyCustomException();
}

int main() {
    try {
        testCustomException();
    }
    catch (const MyCustomException& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }
}
```

**Output:**
```
Caught: My custom exception occurred!
```

In this example, `MyCustomException` is a user-defined exception that extends `std::exception` and provides a custom error message. You can define exceptions in this way when your program requires more specialized error handling.

### Why Use User-defined Exceptions?

- **Specificity**: You can define exception types that are tailored to your application’s needs.
- **Clarity**: Your code can throw exceptions with more specific error messages, making it easier to diagnose issues.
- **Separation of Concerns**: By using custom exceptions, you ensure that application-specific errors are separated from standard errors, enhancing maintainability.

---

## Catching Multiple Exception Types

In C++, it’s common to encounter different types of exceptions during program execution. Fortunately, the language provides a way to handle multiple exception types using **multiple `catch` blocks**. This allows you to define different error-handling logic for different error conditions.

### Multiple `catch` Blocks

Each `catch` block is evaluated in the order in which it appears. If an exception matches a `catch` block, that block handles the exception, and no other `catch` blocks are executed for that exception.

### Example of Catching Multiple Types of Exceptions

```cpp
#include <iostream>
#include <stdexcept>

void mayThrow(int num) {
    if (num == 0)
        throw std::invalid_argument("Argument cannot be zero");
    if (num < 0)
        throw std::out_of_range("Argument must be positive");
    std::cout << "Valid input: " << num << std::endl;
}

int main() {
    try {
        mayThrow(-1);  // Will throw std::out_of_range
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Caught invalid_argument: " << e.what() << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cout << "Caught out_of_range: " << e.what() << std::endl;
    }
}
```

**Output:**
```
Caught out_of_range: Argument must be positive
```

### Catching General and Specific Exceptions

You can also catch a general `std::exception` at the end to handle any other exception that doesn’t match a specific type.

```cpp
int main() {
    try {
        mayThrow(0);
    }
    catch (const std::invalid_argument& e) {
        std::cout << "Caught invalid_argument: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Caught a general exception: " << e.what() << std::endl;
    }
}
```

**Output:**
```
Caught invalid_argument: Argument cannot be zero
```

In this case, catching `std::exception` ensures that if an exception of a type not specifically handled earlier is thrown, it will still be caught.

### Catching Unknown Exceptions

Sometimes, you may not know what kind of exception might be thrown — especially when working with third-party code or in large applications. In such cases, you can use the **catch-all handler**:

```cpp
catch (...) {
    std::cout << "Caught an unknown exception!" << std::endl;
}
```

This syntax allows you to **catch any exception**, regardless of its type — including those that are **not derived from `std::exception`** or even non-class types like `int`, `char*`, etc.

#### Example:

```cpp
void throwUnknown() {
    throw 42; // throwing an int, not a standard exception
}

int main() {
    try {
        throwUnknown();
    }
    catch (const std::exception& e) {
        std::cout << "Caught std::exception: " << e.what() << std::endl;
    }
    catch (...) {
        std::cout << "Caught an unknown exception!" << std::endl;
    }
}
```

**Output:**
```
Caught an unknown exception!
```

#### Key Points to Remember

- `catch (...)` should typically come **last** in a series of catch blocks, because it will match *any* exception and prevent other more specific handlers from being reached.
- It **does not provide any diagnostic information** — you can’t access the exception object or call `what()` on it.
- It's mainly useful for logging, cleaning up resources, or **ensuring graceful program termination** in case something unexpected goes wrong.

---

## Conclusion

Understanding the types of exceptions and how to handle them in C++ is critical for writing robust and fault-tolerant applications. Built-in exceptions handle many common errors, while user-defined exceptions allow you to manage custom application-specific errors. By using multiple `catch` blocks, you can tailor error handling for different scenarios and make your code more maintainable and easier to debug.

Continue with [BestPractices.md](BestPractices.md) to learn more about the best practices for handling exceptions in C++ effectively.