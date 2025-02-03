# Classes and Objects  

This document explains the concepts of **classes** and **structures** in C++, highlighting their differences, features, and usage. It also introduces related concepts such as access modifiers, encapsulation, and abstraction.  

---

## Structures vs. Classes  

### **Structures**  
- Structures are used to group variables of different types into a single unit.  
- All members of a structure are **public** by default.  
- Example:  

```cpp
struct Point {
    int x;
    int y;
};
```

### **Classes**  
- Classes group data (variables) and functions (methods) together.  
- All members of a class are **private** by default.  
- Example:  

```cpp
class Point {
private:
    int x;
    int y;

public:
    void setCoordinates(int xValue, int yValue) {
        x = xValue;
        y = yValue;
    }
};
```

**Key difference**: Structures are better suited for simple data grouping, while classes are used when functions need to operate on the data within the same unit.  

---

## Members of a Class  

A class can have:  
1. **Data Members**: Variables that hold data.  
2. **Member Functions**: Functions that define behavior or operations on the data.  

### Example:  

```cpp
class Rectangle {
private:
    int length, width;

public:
    void setDimensions(int l, int w) {
        length = l;
        width = w;
    }

    int calculateArea() {
        return length * width;
    }
};
```

In this example:  
- `length` and `width` are data members.  
- `setDimensions` and `calculateArea` are member functions.  

---

## Access Modifiers  

Access modifiers determine the visibility of members in a class or structure:  
- **Public**: Members are accessible from outside the class.  
- **Private**: Members are only accessible within the class.  
- **Protected**: Members are accessible within the class and its derived classes.  

### Example:  

```cpp
class Example {
private:
    int privateValue;  // Cannot be accessed directly outside the class

public:
    int publicValue;   // Can be accessed directly
};
```

---

## Encapsulation  

Encapsulation means restricting direct access to some of a class’s components and providing controlled access through methods.  

### Example:  

```cpp
class BankAccount {
private:
    double balance;

public:
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    double getBalance() const {
        return balance;
    }
};
```

In this example:  
- The `balance` variable is private and cannot be modified directly.  
- Controlled access is provided through the `deposit` and `getBalance` functions.  

---

## Creating and Using Objects  

### Example:  

```cpp
int main() {
    Rectangle rect;
    rect.setDimensions(10, 5);
    std::cout << "Area: " << rect.calculateArea() << std::endl; // Output: Area: 50

    return 0;
}
```

Steps:  
1. **Define the class**: Use the `class` keyword.  
2. **Create an object**: Declare an object using the class name.  
3. **Access members**: Use the dot operator (`.`) to call public methods or access public variables.  

---

## Abstraction  

Abstraction refers to hiding unnecessary implementation details and exposing only essential features.  

### Example:  

```cpp
class Car {
public:
    void startEngine() {
        std::cout << "Engine started" << std::endl;
    }
};

int main() {
    Car myCar;
    myCar.startEngine(); // No need to know how the engine works internally

    return 0;
}
```

In this example, the user can start the engine without needing to understand its internal mechanics.  

---

This document provides an overview of classes, structures, and related concepts. Additional examples can be found in the [examples/](examples/) folder, and related exercises are in the [practice_questions/](practice_questions/) folder.

Next, proceed to [02_Constructors_Destructors_This_Operator/](../02_Constructors_Destructors_This_Operator/README.md) to learn about constructors, destructors, and the `this` pointer.
