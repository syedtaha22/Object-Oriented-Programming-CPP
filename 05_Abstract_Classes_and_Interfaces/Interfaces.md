# Interfaces

In C++, there is **no explicit `interface` keyword** like in some other languages (e.g., Java, C#).  
Instead, **interfaces are modeled using abstract classes** where:

- **All** member functions are **pure virtual** (`= 0`).
- **No data members** (except constants) are typically present.

An **interface** thus acts as a **pure blueprint** for what derived classes must implement.

---

## Why Use Interfaces?

- Define a **contract** that multiple classes must follow.
- Promote **loose coupling** and **extensibility**.
- Enable **multiple inheritance** for behavior sharing without data duplication.

---

## Defining an Interface

An interface is simply an abstract class where **every function is pure virtual**.

### Syntax

```cpp
class InterfaceName {
public:
    virtual void function1() = 0;
    virtual void function2() = 0;
    // No data members (except constants)
};
```

---

## Example

```cpp
#include <iostream>

class Printable {
public:
    virtual void print() = 0; // Pure virtual
};

class Scannable {
public:
    virtual void scan() = 0; // Pure virtual
};

class PrinterScanner : public Printable, public Scannable {
public:
    void print() override {
        std::cout << "Printing document..." << std::endl;
    }

    void scan() override {
        std::cout << "Scanning document..." << std::endl;
    }
};

int main() {
    PrinterScanner device;
    device.print();
    device.scan();
    return 0;
}
```

### Output

```
Printing document...
Scanning document...
```

---

## Key Properties of Interfaces

- **Cannot instantiate** an interface directly.
- A class that **inherits an interface** must **implement all its functions** to become concrete.
- A class can **implement multiple interfaces** through multiple inheritance.
- Interfaces usually **do not have** constructors, destructors, or data members (other than constants).

---

## Interface vs Abstract Class

| Aspect                     | Abstract Class                | Interface                       |
|-----------------------------|--------------------------------|---------------------------------|
| Purpose                     | Partial blueprint + implementation | Pure blueprint only |
| Pure Virtual Functions Only | No                             | Yes (100% pure virtual)         |
| Data Members                | Allowed                       | Typically avoided (except constants) |
| Multiple Inheritance        | Allowed                       | Often used for multiple inheritance |

---

## Notes

- In C++, using interfaces gives flexibility similar to Java/C# but **with manual enforcement**.
- Helps achieve **polymorphism** without tying down to specific class hierarchies.
- Design systems around **"programming to interfaces"** rather than **"programming to implementations"** for better modularity.

---

**Next:**  
Explore [examples/](examples/) to see how abstract classes and interfaces are applied practically in C++!