# Static and Dynamic Casting in C++

## Introduction

Casting in C++ is a way to convert one type into another. When dealing with **Object-Oriented Programming (OOP)** and **polymorphism**, two primary forms of casting are used: **static_cast** and **dynamic_cast**. These are particularly important when working with **base class pointers** and **derived class objects**.

Understanding when to use `static_cast` and `dynamic_cast` is crucial for writing efficient and safe code. This document covers both in detail, explaining how they work, their advantages and disadvantages, and when to use them.

---

## 1. `static_cast`

### What is `static_cast`?

`static_cast` is used for **compile-time type conversions**. It is a safer and more explicit alternative to C-style casting. When applied to pointers in an inheritance hierarchy, `static_cast` allows the conversion between a **base class pointer and a derived class pointer**.

### Behavior and Rules

- `static_cast` **performs conversions at compile time**.
- It does **not** perform runtime type checking.
- It can convert **pointers** or **references** between related types (base and derived classes).
- The compiler assumes the programmer knows what they are doing.
- If incorrectly used to cast a base class pointer to an unrelated derived class pointer, **undefined behavior** may occur.

### Example: Upcasting (Base Pointer from Derived Object)

Upcasting is **safe and implicit**, but `static_cast` can still be used for clarity.

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    virtual void show() { cout << "Base class" << endl; }
};

class Derived : public Base {
public:
    void show() override { cout << "Derived class" << endl; }
};

int main() {
    Derived d;
    Base* b = static_cast<Base*>(&d); // Upcasting
    b->show(); // Output: Derived class (due to virtual function)
    return 0;
}
```

### Example: Downcasting (Derived Pointer from Base Pointer)

Downcasting should be done **only when you are sure the object is actually of the derived type**, as `static_cast` does **not** perform runtime type checking.

```cpp
int main() {
    Base* b = new Derived(); // Base pointer pointing to Derived object
    Derived* d = static_cast<Derived*>(b); // Downcasting
    d->show(); // Output: Derived class
    delete b;
    return 0;
}
```

If the base pointer does **not** actually point to a derived object, using `static_cast` will result in **undefined behavior**.

### Pros and Cons of `static_cast`

| Pros | Cons |
|------|------|
| Fast (compile-time conversion). | No runtime type checking. |
| Safe for upcasting. | Unsafe for downcasting unless correctness is guaranteed. |
| More explicit than C-style casts. | Can cause undefined behavior if misused. |

---

## 2. `dynamic_cast`

### What is `dynamic_cast`?

`dynamic_cast` is used for **safe runtime type conversions** in polymorphic class hierarchies. It performs **runtime type checking** and ensures that the conversion is valid before proceeding.

### Behavior and Rules

- `dynamic_cast` **only works with polymorphic classes** (i.e., classes that have at least one `virtual` function).
- If the cast is **valid**, it returns a valid pointer/reference to the derived class.
- If the cast is **invalid**, it returns `nullptr` for pointers and throws `std::bad_cast` for references.
- `dynamic_cast` incurs a **runtime performance cost** due to type checking.

### Example: Safe Downcasting with `dynamic_cast`

```cpp
int main() {
    Base* b = new Derived(); // Base pointer to Derived object
    Derived* d = dynamic_cast<Derived*>(b);
    if (d) {
        d->show(); // Output: Derived class
    } else {
        cout << "Cast failed" << endl;
    }
    delete b;
    return 0;
}
```

If `b` were actually pointing to a `Base` object instead of a `Derived` object, `dynamic_cast` would return `nullptr`, avoiding undefined behavior.

### Example: Casting References with `dynamic_cast`

```cpp
int main() {
    try {
        Base* b = new Derived();
        Derived& d = dynamic_cast<Derived&>(*b); // Safe downcast
        d.show();
        delete b;
    } catch (bad_cast& e) {
        cout << "Bad cast exception: " << e.what() << endl;
    }
    return 0;
}
```

If the cast is invalid, `dynamic_cast` throws a `bad_cast` exception.

### Pros and Cons of `dynamic_cast`

| Pros | Cons |
|------|------|
| Safe (prevents invalid downcasting). | Slower due to runtime type checking. |
| Returns `nullptr` for invalid casts instead of causing undefined behavior. | Requires polymorphic base class (must have a `virtual` function). |
| Useful when the actual type of an object is unknown at compile-time. | Cannot be used with non-polymorphic classes. |

---

## 3. When to Use `static_cast` vs `dynamic_cast`

| Scenario                               | Use `static_cast`             | Use `dynamic_cast`           |
|----------------------------------------|------------------------------ |------------------------------|
| **Upcasting (Base* from Derived*)**    | Safe and efficient            | Unnecessary                  |
| **Downcasting (Derived* from Base*)**  | Only if 100% sure of type     | Safe with runtime check      |
| **Checking object type at runtime**    | Cannot check type             | Returns `nullptr` on failure |
| **Performance-critical code**          | Faster                        | Slower                       |
| **Non-polymorphic classes**            | Allowed                       | Not allowed                  |

### Summary
- Use `static_cast` **when upcasting** or when you are **certain** of the object’s actual type.
- Use `dynamic_cast` **when you need runtime safety** while downcasting.
- If you are unsure whether an object is of a derived type, `dynamic_cast` is the safest option.

---

## 4. Conclusion

Understanding `static_cast` and `dynamic_cast` is essential when working with polymorphism in C++.
- `static_cast` is useful when conversions are known to be safe and performance is a concern.
- `dynamic_cast` should be used when **safety** is more important than performance.

By choosing the right type of cast, you can ensure your program is both efficient and robust.

For practice problems and further examples, refer to:

- [practice/practice.md](practice_questions/practice.md)
- [examples/](examples/)

