# Abstract Classes

An **abstract class** in C++ is a class that **cannot be instantiated** directly and serves primarily as a **base class** for other classes. It provides a blueprint for derived classes by defining **pure virtual functions** that must be overridden.

## Why Use Abstract Classes?

- **Enforce a contract** for derived classes.
- **Promote code reuse** for shared implementation.
- **Separate interface from implementation**.
- **Enable polymorphism** by working with base class pointers/references.

## Defining an Abstract Class

A class becomes abstract when it has **at least one pure virtual function**.  
A **pure virtual function** is declared by assigning `= 0` in its prototype.

### Syntax

```cpp
class AbstractBase {
public:
    virtual void pureVirtualFunction() = 0; // Pure virtual function
};
```

- `= 0` indicates that the function is **pure** and must be **overridden** in any concrete derived class.
- The abstract class can have normal (non-pure) member functions as well.

### Example

```cpp
#include <iostream>

class Shape {
public:
    virtual void draw() = 0; // Pure virtual function
    void info() {
        std::cout << "This is a shape." << std::endl;
    }
};

class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a circle." << std::endl;
    }
};

int main() {
    // Shape s; // Error: cannot instantiate abstract class
    Circle c;
    c.draw();
    c.info(); // Inherited normal function
    return 0;
}
```

### Output

```
Drawing a circle.
This is a shape.
```

---

## Key Properties of Abstract Classes

- You **cannot create an object** of an abstract class.
- Derived classes **must override** all pure virtual functions to become concrete (instantiable).
- If a derived class does **not** override all pure virtual functions, it also becomes **abstract**.
- Abstract classes can have **constructors**, **destructors**, **member functions**, and **data members**.

### Example of Inheriting Without Overriding

```cpp
class IncompleteShape : public Shape {
    // No override → still abstract
};
```

- `IncompleteShape` is still abstract because it doesn't override `draw()`.

---

## Abstract Class with Some Implementations

Abstract classes can provide **partial implementation** to derived classes.

```cpp
class Animal {
public:
    virtual void sound() = 0; // Pure virtual
    void breathe() {
        std::cout << "Breathing..." << std::endl;
    }
};
```

Derived classes inherit the `breathe()` method without needing to override it.

---

## Notes

- Abstract classes are a cornerstone for **interface-based programming** in C++.
- Helps in designing **extensible** and **scalable** systems.
- Facilitates **polymorphism** by allowing manipulation of derived objects through base class pointers/references.

---

**Next:**  
Go to [Interfaces.md](Interfaces.md) to understand how **interfaces** are modeled in C++ using abstract classes.