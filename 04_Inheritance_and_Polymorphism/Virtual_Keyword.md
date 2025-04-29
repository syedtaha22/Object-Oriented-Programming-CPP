# The `virtual` Keyword in C++

The `virtual` keyword in C++ is essential for supporting **polymorphism**, allowing derived classes to override base class methods. It ensures that the correct function version is called at runtime, even when a pointer or reference to a base class is used.

## 1. Basic Concept of `virtual`

In C++, when a derived class overrides a base class method, you usually expect the derived class's version of the function to be called. Without the `virtual` keyword, the base class version is called instead, even if you're working with a derived class object.

### Example Without `virtual`
```cpp
class Base {
public:
    void show() { std::cout << "Base class" << std::endl; }
};

class Derived : public Base {
public:
    void show() { std::cout << "Derived class" << std::endl; }
};

int main() {
    Base* obj = new Derived();
    obj->show();  // Calls Base::show(), NOT Derived::show()
    delete obj;
    return 0;
}
```
**Output:**
```
Base class
```
Even though `obj` points to a `Derived` object, the base class version of `show()` is called.

## 2. Correcting the Function Call with `virtual`

To make sure that the derived class's version of a function is called, declare the function `virtual` in the base class.

### Example With `virtual`
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
    obj->show();  // Calls Derived::show() because of virtual
    delete obj;
    return 0;
}
```
**Output:**
```
Derived class
```
By adding `virtual`, the correct `show()` function is called from the derived class.

## 3. Object Destruction and Virtual Destructors

In C++, when you have base class pointers or references that point to derived class objects, proper destruction of those derived objects is crucial. If you don't handle destruction properly, it can lead to **resource leaks** or **undefined behavior**.

### The Issue: Incomplete Destruction

When you delete an object through a base class pointer, **only the base class's destructor** is called if the base class destructor is **not virtual**. This can cause **memory leaks** or lead to **resource leaks** if the derived class has resources that need to be cleaned up (like dynamic memory or file handles).

Even though you're working with derived objects, only the base class destructor runs, which can leave parts of the object in an undefined state.

### Example Without Virtual Destructor
```cpp
class Base {
public:
    ~Base() { std::cout << "Base Destructor" << std::endl; }
};

class Derived : public Base {
public:
    ~Derived() { std::cout << "Derived Destructor" << std::endl; }
};

int main() {
    Base* obj = new Derived();
    delete obj;  // Calls Base destructor only!
    return 0;
}
```
**Output:**
```
Base Destructor
```

In this example, when `delete obj` is called, **only the `Base` destructor** is executed, and the `Derived` destructor is skipped. This means that if `Derived` manages any resources (e.g., dynamic memory or other resources), those resources won't be released properly, causing potential memory or resource leaks.

### The Solution: Virtual Destructor

To fix this issue, you need to declare the base class destructor as `virtual`. This ensures that when deleting a derived object through a base class pointer, the destructor of the derived class is called first, followed by the destructor of the base class. This guarantees that all resources, whether managed by the base or derived class, are properly cleaned up.

### Example With Virtual Destructor
```cpp
class Base {
public:
    virtual ~Base() { std::cout << "Base Destructor" << std::endl; }
};

int main() {
    Base* obj = new Derived();
    delete obj;  // Calls both Derived and Base destructors
    return 0;
}
```
**Output:**
```
Derived Destructor
Base Destructor
```

Now, with the `virtual` destructor in the base class, both the `Derived` and `Base` destructors are called correctly, ensuring proper cleanup of resources.

### Why Virtual Destructors Matter, Even Without Dynamic Memory
Even if you're not using dynamic memory (`new`), you should still make the base class destructor virtual if polymorphism is involved. This ensures proper destruction, even for stack-allocated objects, preventing incomplete cleanup.

---

## 4. Abstract Classes and Pure Virtual Functions

A **pure virtual function** is a function declared in a base class that doesn't have a body. This makes the class **abstract**, meaning it cannot be instantiated. Any derived class must provide an implementation of the pure virtual function to be instantiable.

### Example of a Pure Virtual Function
```cpp
class AbstractBase {
public:
    virtual void show() = 0;  // Pure virtual function
};
```
Any derived class **must** provide an implementation of the pure virtual function:

```cpp
class Derived : public AbstractBase {
public:
    void show() override { std::cout << "Derived class" << std::endl; }
};
```

---

## 5. How Virtual Functions Work Behind the Scenes

Internally, C++ uses a **virtual table (vtable)** to manage dynamic function calls. Each class with virtual functions has a vtable, which is a list of pointers to the virtual functions.

When you call a virtual function on an object, the **vptr** (virtual pointer) inside the object points to the correct function in the vtable. This allows for dynamic dispatch, ensuring the correct function is called at runtime.

### Example
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
    obj->show();  // Resolves to Derived::show() via vtable
    delete obj;
    return 0;
}
```
The vtable mechanism ensures that the correct function (`Derived::show()`) is called at runtime, even when accessed via a base class pointer.

---

## 6. Virtual Functions in Multiple Inheritance

When a class inherits from multiple base classes with virtual functions, each base class contributes its own vtable. This can add complexity to method resolution, as multiple vtables are involved.

### Example of Multiple Inheritance
```cpp
class Base1 {
public:
    virtual void show() { std::cout << "Base1" << std::endl; }
};

class Base2 {
public:
    virtual void show() { std::cout << "Base2" << std::endl; }
};

class Derived : public Base1, public Base2 {
public:
    void show() override { std::cout << "Derived" << std::endl; }
};
```

In this case, the `Derived` class will have two vtables—one for `Base1` and another for `Base2`. This leads to complexity in method resolution, but C++ manages this automatically through the vtable mechanism.

---

## 7. Virtually Inheriting Classes

Virtually inheriting a class ensures that only one instance of a common base class is shared among multiple derived classes in the case of multiple inheritance. This solves the **diamond problem**, where the derived class could inherit the same base class multiple times through different paths.

### Example of Virtually Inheriting
```cpp
class Base {
public:
    virtual void show() { std::cout << "Base class" << std::endl; }
};

class A : virtual public Base {
public:
    void show() override { std::cout << "Class A" << std::endl; }
};

class B : virtual public Base {
public:
    void show() override { std::cout << "Class B" << std::endl; }
};

class Derived : public A, public B {
public:
    void show() override { std::cout << "Derived class" << std::endl; }
};
```

Here, both `A` and `B` virtually inherit `Base`, so only one `Base` class is included in the `Derived` object.

---

## Summary

| Feature                   | Description |
|---------------------------|-------------|
| **Virtual functions**      | Allow dynamic function calls to be resolved at runtime. |
| **Override keyword**       | Ensures a method correctly overrides a base class function. |
| **Virtual destructors**    | Ensure proper cleanup of derived objects when deleted. |
| **Pure virtual functions** | Make a class abstract and force derived classes to implement specific methods. |
| **vtable & vptr**          | Underlying mechanism for dynamic function resolution. |
| **Virtual inheritance**    | Ensures only one instance of a common base class in multiple inheritance. |

The `virtual` keyword is crucial for **polymorphism**, making your C++ code more flexible and maintainable. By understanding its role in function resolution and memory management, you can avoid common pitfalls and create robust object-oriented programs.


See [Polymorphism.md](Polymorphism.md) for a deeper dive into **polymorphism** and its various forms in C++.
