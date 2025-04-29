# Basics of Exception Handling

Exception handling in C++ provides a way to detect, manage, and recover from runtime errors gracefully. Instead of crashing the program or relying on scattered error codes, exceptions help isolate error-handling logic from normal operations. This results in cleaner, more readable, and more robust code—especially important in large and complex systems.

---

## What Are Exceptions?

An **exception** is an abnormal condition or error that arises during program execution. Examples include:

- Division by zero
- Array index out-of-bounds
- Failure to allocate memory
- Invalid input or logical inconsistencies

In C++, these conditions can be thrown as exceptions and handled using `try`/`catch` blocks. This allows a program to recover from errors or at least exit cleanly, without causing crashes or leaving resources unreleased.

**Example:**

```cpp
int divide(int a, int b) {
    if (b == 0)
        throw "Division by zero error";
    return a / b;
}
```

Here, instead of returning a sentinel value (like -1), the function throws an exception with an explanatory message.

---

## The `try`, `catch`, and `throw` Keywords

C++ uses three main keywords for exception handling:

- `throw`: Used to signal an error (raise an exception).
- `try`: Marks a block of code where an exception might occur.
- `catch`: Defines what to do when an exception is thrown.

### Basic Syntax:

```cpp
try {
    // Risky code that might throw
    operation();
}
catch (Type e) {
    // Error handling logic
}
```

### Example with Division:

```cpp
#include <iostream>

int divide(int a, int b) {
    if (b == 0)
        throw "Cannot divide by zero";
    return a / b;
}

int main() {
    try {
        int result = divide(10, 0);
        std::cout << "Result: " << result << std::endl;
    }
    catch (const char* message) {
        std::cout << "Error: " << message << std::endl;
    }
}
```

**Output:**
```
Error: Cannot divide by zero
```

The exception is caught, and the program exits gracefully instead of crashing.

---

### Stack Unwinding and Control Flow

When an exception is thrown, C++ begins a process called **stack unwinding**. This refers to the systematic rollback of function calls that were active at the time of the exception.

### What Actually Happens

1. C++ searches for a matching `catch` block up the call stack.
2. As each function is exited during this search, **all local  objects that were fully constructed before the `throw`** are destroyed, and their destructors are called.
3. Once a matching `catch` block is found, control is transferred there.
4. If no handler is found, the program calls `std::terminate()` and aborts.

Objects that were **in scope and fully constructed at the time of the `throw`** are destroyed during unwinding. Any code after the `throw` statement is skipped so **objects that were supposed to be constructed after `throw` will never be created** hence their destructors will not be called.

---

### Example: Stack Unwinding in Action

```cpp
#include <iostream>

class Tracker {
    std::string name;
public:
    Tracker(std::string n) : name(n) {
        std::cout << "Constructed: " << name << std::endl;
    }
    ~Tracker() {
        std::cout << "Destructed: " << name << std::endl;
    }
};

void C() {
    Tracker t3("t3");
    throw std::runtime_error("Error in C");
}

void B() {
    Tracker t2("t2");
    C();
}

void A() {
    Tracker t1("t1");
    try {
        B();
    }
    catch (const std::exception& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }
}

int main() {
    A();
}
```

**Output:**
```
Constructed: t1
Constructed: t2
Constructed: t3
Destructed: t3
Destructed: t2
Caught: Error in C
Destructed: t1
```

### Explanation:

- `A()` constructs `t1`, then calls `B()`, which constructs `t2` and calls `C()`, which constructs `t3`.
- When `C()` throws an exception, the program starts unwinding the stack:
    - **`t3`** is the most recently constructed object, so its destructor is called first. Even though `t4` is declared after the `throw`, it will never be constructed due to the exception interrupting the flow.
    - The stack unwinds to `B()`, where the destructor for **`t2`** is called.
    - Control then goes back to `A()`, where the exception is caught in the `catch` block.
- After the `catch` block executes, the program continues normal execution, and the destructor for **`t1`** is called when the function `A()` exits.

---

### Example: Stack Unwinding with Dynamically Allocated Resources

```cpp
#include <iostream>

class Resource {
    int* data;
public:
    Resource() {
        data = new int[100];
        std::cout << "Resource acquired\n";
    }

    ~Resource() {
        delete[] data;
        std::cout << "Resource released\n";
    }
};

int main() {
    try {
        Resource r;
        throw 42;
    }
    catch (int e) {
        std::cout << "Caught exception: " << e << std::endl;
    }
}
```

**Output:**
```
Resource acquired
Resource released
Caught exception: 42
```

This shows that the destructor for `Resource` is called even though an exception was thrown mid-function. This is a critical feature of stack unwinding—it helps prevent resource leaks when exceptions occur.

---

Continue with [TypesOfExceptionHandling.md](TypesOfExceptionHandling.md) to learn how to work with built-in exceptions, user-defined exceptions, and multiple `catch` blocks in C++.
