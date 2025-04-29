# Best Practices in Exception Handling

Exception handling is a powerful mechanism in C++, but it must be used with care. Following best practices ensures that your code remains robust, readable, and maintainable. This section outlines key principles and techniques every C++ developer should follow.

---

## 1. Exception Safety

**Exception safety** refers to the guarantees your code provides in the presence of exceptions. There are three commonly discussed levels:

### a) Basic Guarantee
- Ensures that no resources are leaked.
- The program remains in a **valid but possibly altered** state.
- No undefined behavior occurs.

### b) Strong Guarantee
- Ensures **rollback semantics**.
- If an operation fails (throws an exception), the program state remains **unchanged** as if the operation never happened.

### c) No-throw Guarantee
- The operation is **guaranteed not to throw exceptions**.
- Often expected from destructors and some low-level operations.

### Example:

```cpp
class SafeVector {
    int* data;
    size_t size;

public:
    SafeVector(size_t n) : size(n) {
        data = new int[n];  // if new throws, no resource is leaked
    }

    ~SafeVector() {
        delete[] data;  // destructor must never throw
    }
};
```

In this example:
- The constructor provides the **basic guarantee**: if allocation fails, no memory is leaked.
- The destructor is marked **no-throw** by design.

---

## 2. Resource Management with RAII

C++ encourages **RAII** (Resource Acquisition Is Initialization) to tie resource lifetimes to object lifetimes. This is critical for writing exception-safe code.

### Principle:
- Resources (like memory, file handles, network sockets) should be owned by objects.
- When the object is destroyed (due to normal control flow or exception), its destructor automatically releases the resource.

### Benefits:
- No need to remember to manually `delete` or `close`.
- Prevents resource leaks even when exceptions are thrown.

### Example:

```cpp
#include <fstream>

void writeToFile(const string& filename) {
    ofstream file(filename); // RAII in action
    if (!file)
        throw runtime_error("Cannot open file");

    file << "Writing to file...\n";
} // file is automatically closed when going out of scope
```

If an exception is thrown after the file is opened, the `ofstream` destructor will still close the file properly — even though the control leaves the function prematurely.

---

## 3. Exceptions vs Error Codes

### When to Use Exceptions:
- For **exceptional situations**: errors that are **rare** and **unexpected**.
- When the error cannot be handled locally.
- When writing **high-level** business logic where cleaner separation of error-handling logic improves clarity.

```cpp
double divide(double a, double b) {
    if (b == 0.0)
        throw invalid_argument("Division by zero");
    return a / b;
}
```

### When to Use Error Codes:
- For **predictable, frequent conditions** (e.g., invalid user input).
- In **performance-critical** or **low-level code** (e.g., device drivers).
- In environments where exceptions are not allowed (e.g., some embedded systems).

```cpp
bool divide(double a, double b, double& result) {
    if (b == 0.0)
        return false;
    result = a / b;
    return true;
}
```

### Summary:

| Situation                      | Use Exceptions | Use Error Codes                 |
|--------------------------------|----------------|---------------------------------|
| Unexpected/fatal error         | $\checkmark$   | $\times$                        |
| Frequent or expected condition | $\times$       | $\checkmark$                    |
| Complex call chains            | $\checkmark$   | $\times$                        |
| Performance-critical path      | $\times$       | $\checkmark$                    |
| Library/public API design      | $\checkmark$   | $\checkmark$ (for C-style APIs) |

---

## Final Tips

- Never throw exceptions from destructors.
- Always catch exceptions **by reference** (`catch (const std::exception& e)`).
- Avoid using `catch (...)` unless absolutely necessary.
- Prefer RAII and smart pointers over raw `new`/`delete`.
- Design your code so that if an exception is thrown, **no resources are leaked** and the program remains in a **valid state**.

Now, for practice problems and further examples, refer to:

- [practice_questions/practice.md](practice_questions/practice.md)
- [examples/](examples/)
