# Inheritance in C++

Inheritance is a fundamental concept in **Object-Oriented Programming (OOP)** that allows a class to derive properties and behaviors from another class. It enables **code reuse, hierarchical structuring, and extensibility** while reducing redundancy.

## 1. Understanding Inheritance

Before diving into the syntax and complexities of inheritance, it is important to understand **why inheritance exists** and **how it benefits software design**.

Imagine a scenario where you are developing software to manage different types of animals in a zoo. Without inheritance, you might define separate classes for **Lion, Tiger, Elephant, and Giraffe**, each with similar attributes such as **age, weight, and species**. This leads to code duplication, making maintenance difficult. 

Instead, **inheritance allows you to define a common base class** `Animal` containing shared properties, while each specific animal type can inherit from it and define its own behaviors.

This approach offers:
- **Code reusability**: Common functionality is written once and shared across derived classes.
- **Better organization**: Logical hierarchies represent real-world relationships.
- **Extensibility**: New classes can be easily introduced with minimal modification to existing code.

---

## 2. Basic Syntax of Inheritance

In C++, a class can inherit from another using the following syntax:

```cpp
class BaseClass {
    // Members of the base class
};

class DerivedClass : public BaseClass {
    // Members of the derived class
};
```

### Example:
```cpp
#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    void eat() {
        cout << "This animal is eating." << endl;
    }
};

// Derived class
class Dog : public Animal {
public:
    void bark() {
        cout << "The dog is barking." << endl;
    }
};

int main() {
    Dog myDog;
    myDog.eat();  // Inherited function
    myDog.bark(); // Derived class function
    return 0;
}
```

### How It Works:
- The `Dog` class **inherits** from the `Animal` class using the `public` keyword.
- The `eat()` method is defined in `Animal`, but since `Dog` inherits it, instances of `Dog` can call it.
- The `Dog` class also has its own method, `bark()`, which is exclusive to `Dog`.

---

## 3. Types of Inheritance

C++ supports multiple types of inheritance, each serving different purposes in software design.

### 3.1 Single Inheritance
This is the most common type where a **single derived class** inherits from a **single base class**.

```cpp
class Parent {
    // Base class members
};
class Child : public Parent {
    // Derived class members
};
```

This type of inheritance is useful when **one class logically extends another**. For instance, a `Car` class can inherit from a `Vehicle` class, gaining its properties and behaviors.

### 3.2 Multiple Inheritance
A **single derived class** inherits from **multiple base classes**.

```cpp
class Base1 {
public:
    void showBase1() { cout << "Base1" << endl; }
};

class Base2 {
public:
    void showBase2() { cout << "Base2" << endl; }
};

class Derived : public Base1, public Base2 {
public:
    void showDerived() { cout << "Derived class" << endl; }
};
```

#### **Issue with Multiple Inheritance: Diamond Problem**
One of the biggest problems in multiple inheritance is the **diamond problem**, where ambiguity arises when a class inherits from two classes that both inherit from the same base class.

```cpp
class A {
public:
    void show() { cout << "Class A" << endl; }
};

class B : public A {};
class C : public A {};

class D : public B, public C {
    // Ambiguity: which 'show' method should be used?
};
```

If `D` calls `show()`, the compiler does not know whether to invoke `A::show()` from `B` or from `C`.

**Solution:** Use **virtual base classes** (covered in [Virtual_Keyword.md](Virtual_Keyword.md)).

### 3.3 Multilevel Inheritance
A **derived class inherits from another derived class**, forming a chain.

```cpp
class GrandParent {
public:
    void showGrandParent() { cout << "Grandparent" << endl; }
};

class Parent : public GrandParent {
public:
    void showParent() { cout << "Parent" << endl; }
};

class Child : public Parent {
public:
    void showChild() { cout << "Child" << endl; }
};
```

### 3.4 Hierarchical Inheritance
A **single base class** is inherited by **multiple derived classes**.

```cpp
class Parent {
public:
    void show() { cout << "Parent class" << endl; }
};

class Child1 : public Parent {};
class Child2 : public Parent {};
```

### 3.5 Hybrid Inheritance
A mix of multiple inheritance types, often leading to complex scenarios like the **diamond problem**.

```cpp
class A {};
class B : public A {};
class C : public A {};
class D : public B, public C {};  // Diamond problem arises
```

Solution: **Virtual base classes** (covered in [Virtual_Keyword.md](Virtual_Keyword.md)).

---

## 4. Constructor and Destructor Behavior in Inheritance

When a derived class is instantiated:
- **Base class constructors execute first**, ensuring the base is properly initialized.
- **Derived class constructors execute next**.
- **Destructors execute in reverse order**.

```cpp
class Base {
public:
    Base() { cout << "Base Constructor\n"; }
    ~Base() { cout << "Base Destructor\n"; }
};

class Derived : public Base {
public:
    Derived() { cout << "Derived Constructor\n"; }
    ~Derived() { cout << "Derived Destructor\n"; }
};

int main() {
    Derived obj;
    return 0;
}
```
**Output:**
```
Base Constructor
Derived Constructor
Derived Destructor
Base Destructor
```

---

## 5. Function Overriding in Inheritance
A derived class can redefine methods inherited from a base class.

```cpp
class Base {
public:
    void show() { cout << "Base class" << endl; }
};
class Derived : public Base {
public:
    void show() { cout << "Derived class" << endl; }
};
```
---


## 6. Access Control in Inheritance

In C++, the accessibility of the members (attributes and methods) of a base class in a derived class depends on the **access specifier** used when declaring the inheritance relationship. The three primary access specifiers are **public**, **protected**, and **private**. These affect how the members of the base class are inherited by the derived class.

### 6.1 Public Inheritance
When you use **public inheritance**, the public and protected members of the base class are inherited as **public** and **protected** members, respectively, in the derived class.

```cpp
class Base {
public:
    int publicVar;
protected:
    int protectedVar;
private:
    int privateVar;
};

class Derived : public Base {
    // publicVar is public
    // protectedVar is protected
    // privateVar is not accessible
};
```

In public inheritance:
- **Public members** of the base class are inherited as **public** in the derived class.
- **Protected members** of the base class are inherited as **protected** in the derived class.
- **Private members** of the base class are **not inherited** and are inaccessible in the derived class.

Public inheritance models the "is-a" relationship (e.g., a `Dog` **is a** type of `Animal`).

### 6.2 Protected Inheritance
With **protected inheritance**, both the **public** and **protected** members of the base class are inherited as **protected** in the derived class. The **private** members are still inaccessible.

```cpp
class Derived : protected Base {
    // publicVar and protectedVar are protected
    // privateVar is not accessible
};
```

In protected inheritance:
- **Public members** of the base class are inherited as **protected** in the derived class.
- **Protected members** of the base class remain **protected** in the derived class.
- **Private members** remain inaccessible.

Protected inheritance is less common and generally used for internal use within a class hierarchy.

### 6.3 Private Inheritance
With **private inheritance**, both the **public** and **protected** members of the base class are inherited as **private** in the derived class. The **private** members remain inaccessible.

```cpp
class Derived : private Base {
    // publicVar and protectedVar are private
    // privateVar is not accessible
};
```

In private inheritance:
- **Public members** of the base class are inherited as **private** in the derived class.
- **Protected members** of the base class are inherited as **private** in the derived class.
- **Private members** remain inaccessible.

Private inheritance is often used when the derived class **has a "has-a" relationship** with the base class, rather than an "is-a" relationship.

### 

6.4 Default Inheritance (No Specifier)
If you do not specify any inheritance access modifier, C++ assumes **private inheritance** by default.

```cpp
class Derived : Base {
    // Same as private inheritance
};
```

This default inheritance is mostly used in cases where the derived class does not need to expose any of the base class members and intends to use the base class only internally.

**Summary of Access Modifiers in Inheritance**:

| Inheritance Type  | Public Members | Protected Members | Private Members  |
|-------------------|----------------|--------------------|-----------------|
| **Public**        | public         | protected          | private         |
| **Protected**     | protected      | protected          | private         |
| **Private**       | private        | private            | private         |
| **Default**       | private        | private            | private         |

---

Inheritance is a powerful mechanism in C++, but it must be used carefully to avoid complexity and ambiguity. To fully harness its potential, understanding **virtual functions, polymorphism, and access control** is crucial. These topics, along with solutions to common inheritance-related issues, are discussed further in [Virtual_Keyword.md](Virtual_Keyword.md).



