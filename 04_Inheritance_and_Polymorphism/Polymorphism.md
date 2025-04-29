# Polymorphism in C++

Polymorphism is one of the four fundamental principles of Object-Oriented Programming (OOP), alongside encapsulation, abstraction, and inheritance. It allows objects of different derived classes to be treated as objects of a common base class, enabling code reusability and scalability.

## What is Polymorphism?

The term **polymorphism** comes from the Greek words _poly_ (meaning "many") and _morph_ (meaning "forms"). In C++, polymorphism allows a single interface to represent different underlying data types. This means that the same function call or operation can behave differently depending on the object it is acting upon.

Polymorphism in C++ is primarily categorized into two types:
1. **Compile-time polymorphism (Static polymorphism)**
2. **Runtime polymorphism (Dynamic polymorphism)**

Each type has its own distinct mechanism and use cases.

---

# 1. Compile-Time Polymorphism (Static Polymorphism)

Compile-time polymorphism is resolved at **compile-time**, meaning the function that will be executed is determined by the compiler before the program runs. It is implemented using:

### 1.1 Function Overloading
Function overloading allows multiple functions in the same scope to share the same name but have different parameters.

```cpp
#include <iostream>

class Math {
public:
    int add(int a, int b) { return a + b; }
    double add(double a, double b) { return a + b; }
    int add(int a, int b, int c) { return a + b + c; }
};

int main() {
    Math obj;
    std::cout << obj.add(5, 10) << std::endl;       // Calls add(int, int)
    std::cout << obj.add(5.5, 2.2) << std::endl;   // Calls add(double, double)
    std::cout << obj.add(1, 2, 3) << std::endl;     // Calls add(int, int, int)
    return 0;
}
```

### 1.2 Operator Overloading
Operator overloading allows operators such as `+`, `-`, `*`, etc., to be redefined for user-defined types.

```cpp
#include <iostream>

class Complex {
public:
    int real, imag;
    Complex(int r, int i) : real(r), imag(i) {}
    Complex operator+(const Complex& obj) {
        return Complex(real + obj.real, imag + obj.imag);
    }
    void display() { std::cout << real << " + " << imag << "i" << std::endl; }
};

int main() {
    Complex c1(2, 3), c2(3, 4);
    Complex c3 = c1 + c2; // Calls operator+ function
    c3.display();
    return 0;
}
```

---

# 2. Runtime Polymorphism (Dynamic Polymorphism)

Runtime polymorphism is achieved using **function overriding** and the `virtual` keyword. Unlike static polymorphism, function calls are resolved **at runtime** using the **vtable (virtual table) mechanism**.

### 2.1 Function Overriding
Function overriding occurs when a derived class provides a specific implementation of a function that is already defined in its base class. To achieve runtime polymorphism, the base class function must be declared **virtual**.

```cpp
#include <iostream>

class Base {
public:
    virtual void show() { std::cout << "Base class" << std::endl; }
};

class Derived : public Base {
public:
    void show() override { std::cout << "Derived class" << std::endl; }
};

int main() {
    Base* obj = new Derived(); // Base class pointer storing Derived class object
    obj->show();  // Calls Derived::show() because of virtual function
    delete obj;
    return 0;
}
```

---

# 3. Storing Derived Class Objects in Base Class Pointers

One of the most important aspects of polymorphism is the ability to store a derived class object in a base class pointer:

```cpp
Base* obj = new Derived();
```

This allows dynamic method dispatch where the function call is resolved at runtime based on the actual type of the object being pointed to. This mechanism enables polymorphic behavior where a base class reference or pointer can call derived class methods without knowing the actual derived type.

This is useful in many real-world applications, such as:
- Implementing generic data structures that can work with multiple derived types.
- Using polymorphic containers such as `vector<Base*>` to store multiple types of objects.
- Allowing dynamic memory allocation for derived types without changing function signatures.

---

# 4. Virtual Table (vtable) Mechanism

The **vtable (virtual table)** is an internal mechanism used by C++ to implement runtime polymorphism.

### How the Vtable Works
1. If a class contains **at least one virtual function**, the compiler creates a **vtable** (a table of function pointers).
2. Each **object** of that class has a **vptr** (virtual pointer) that points to the vtable.
3. When a virtual function is called, the **vptr is used** to dynamically resolve the correct function from the vtable.

### Example:
```cpp
class Base {
public:
    virtual void show() { std::cout << "Base class" << std::endl; }
};

class Derived : public Base {
public:
    void show() override { std::cout << "Derived class" << std::endl; }
};

int main() {
    Base* obj = new Derived();
    obj->show(); // Looks up vtable, calls Derived::show()
    delete obj;
    return 0;
}
```

**Behind the scenes:**
```
Base vtable: [Base::show()]
Derived vtable: [Derived::show()]
```

Each object of `Derived` has a `vptr` pointing to the `Derived vtable`, ensuring the correct function is called dynamically.

---

# 5. Why Use Polymorphism?

Polymorphism provides several key benefits:

### 5.1 Code Reusability
- Functions and operators can be reused across multiple data types and classes.
- Common base class methods can be overridden to suit different derived class implementations.

### 5.2 Scalability
- New derived classes can be added without modifying the existing base class implementation.

### 5.3 Flexibility
- Base class pointers or references can store derived class objects, allowing for flexible data handling and operations.

### 5.4 Dynamic Binding
- Using virtual functions ensures correct method resolution at runtime, avoiding unnecessary conditional logic.

---

# 6. Summary

| Feature | Static Polymorphism | Dynamic Polymorphism |
|---------|--------------------|---------------------|
| Mechanism | Function overloading, Operator overloading | Virtual functions, Function overriding |
| Resolution Time | Compile-time | Runtime (via vtable) |
| Efficiency | Faster (resolved at compile-time) | Slightly slower (lookup via vtable) |
| Use Case | Same function name with different parameters | Same function behavior for different derived classes |

Polymorphism is essential for writing **scalable, reusable, and maintainable code** in C++. Understanding both compile-time and runtime polymorphism allows developers to design robust and flexible applications.

---

For further details on type conversions in polymorphism, see: [static_and_dynamic_casting.md](static_and_dynamic_casting.md)

