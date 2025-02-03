# Constructors in C++  

A **constructor** is a special function in C++ that is automatically called when an object of a class is created. Its purpose is to initialize the object and set up necessary values.  

## **Why Use a Constructor?**  

Instead of manually initializing an object after creation, a constructor allows automatic and controlled initialization. This ensures:  

- The object is in a valid state immediately after creation.  
- Initialization logic is encapsulated inside the class.  
- No need to call a separate function for setup.  

---

## **Basic Rules of Constructors**  

1. A constructor **must have the same name** as the class.  
2. It **has no return type**, not even `void`.  
3. It is **automatically called** when an object is created.  
4. It can be **overloaded** (multiple constructors in the same class).  
5. If no constructor is provided, **C++ automatically generates a default constructor**.  

---

## **Types of Constructors**  

### **1. Default Constructor**  

A **default constructor** is a constructor that takes **no parameters**. It initializes the object with default values.  

#### **Example: Default Constructor**  

```cpp
#include <iostream>
using namespace std;

class Car {
public:
    string brand;
    int year;

    // Default constructor
    Car() {
        brand = "Unknown";
        year = 0;
        cout << "Default constructor called\n";
    }

    void display() {
        cout << "Brand: " << brand << ", Year: " << year << endl;
    }
};

int main() {
    Car myCar;  // Default constructor is automatically called
    myCar.display();
}
```

#### **Output:**  
```
Default constructor called  
Brand: Unknown, Year: 0  
```

If no constructor is defined, C++ automatically provides a trivial **default constructor** that does nothing. However, if you define any other constructor (like a parameterized constructor), C++ does **not** generate a default one unless explicitly defined.

---

### **2. Parameterized Constructor**  

A **parameterized constructor** allows passing arguments at the time of object creation, enabling **custom initialization**.  

#### **Example: Parameterized Constructor**  

```cpp
#include <iostream>
using namespace std;

class Car {
public:
    string brand;
    int year;

    // Parameterized constructor
    Car(string b, int y) {
        brand = b;
        year = y;
        cout << "Parameterized constructor called\n";
    }

    void display() {
        cout << "Brand: " << brand << ", Year: " << year << endl;
    }
};

int main() {
    Car car1("Toyota", 2022);  // Constructor is called with arguments
    Car car2("Honda", 2020);

    car1.display();
    car2.display();
}
```

#### **Output:**  
```
Parameterized constructor called  
Parameterized constructor called  
Brand: Toyota, Year: 2022  
Brand: Honda, Year: 2020  
```

#### **Why Use Parameterized Constructors?**  

- Allows setting **different values** for different objects.  
- Eliminates the need for a separate `set()` function.  

---

## **Constructor Overloading**  

Since C++ supports **function overloading**, we can define multiple constructors with different parameters. The correct constructor is chosen based on the provided arguments.  

#### **Example: Overloading Constructors**  

```cpp
#include <iostream>
using namespace std;

class Car {
public:
    string brand;
    int year;

    // Default constructor
    Car() {
        brand = "Unknown";
        year = 0;
        cout << "Default constructor called\n";
    }

    // Parameterized constructor
    Car(string b, int y) {
        brand = b;
        year = y;
        cout << "Parameterized constructor called\n";
    }

    void display() {
        cout << "Brand: " << brand << ", Year: " << year << endl;
    }
};

int main() {
    Car car1;  // Calls default constructor
    Car car2("Tesla", 2023);  // Calls parameterized constructor

    car1.display();
    car2.display();
}
```

#### **Output:**  
```
Default constructor called  
Parameterized constructor called  
Brand: Unknown, Year: 0  
Brand: Tesla, Year: 2023  
```

---

## **Using Default Arguments in Constructors**  

Instead of overloading, we can use **default arguments** in a constructor to achieve a similar effect.  

```cpp
class Car {
public:
    string brand;
    int year;

    // Single constructor with default arguments
    Car(string b = "Unknown", int y = 0) {
        brand = b;
        year = y;
    }

    void display() {
        cout << "Brand: " << brand << ", Year: " << year << endl;
    }
};

int main() {
    Car car1;  // Uses default values
    Car car2("Ford", 2021);  // Uses provided values

    car1.display();
    car2.display();
}
```

#### **Output:**  
```
Brand: Unknown, Year: 0  
Brand: Ford, Year: 2021  
```

This method reduces redundant code while still providing flexibility.

---

## **Initializer List in Constructors**  

C++ allows initialization of members using an **initializer list**. It is more efficient than assignment inside the constructor body, especially for **const** or **reference** members that must be initialized at declaration.  

#### **Example: Constructor with Initializer List**  

```cpp
#include <iostream>
using namespace std;

class Car {
public:
    const string brand;
    int year;

    // Initializer list constructor
    Car(string b, int y) : brand(b), year(y) {
        cout << "Constructor with initializer list called\n";
    }

    void display() {
        cout << "Brand: " << brand << ", Year: " << year << endl;
    }
};

int main() {
    Car car1("BMW", 2024);
    car1.display();
}
```

#### **Output:**  
```
Constructor with initializer list called  
Brand: BMW, Year: 2024  
```

### **Why Use Initializer Lists?**  
- **Efficiency** → Directly initializes members instead of assignment.  
- **Mandatory for `const` and references** → These cannot be assigned later.  
- **Better Performance** → Avoids unnecessary default construction followed by assignment.  

---

## **Key Takeaways**  

- A **constructor** is automatically called when an object is created.  
- If no constructor is defined, C++ provides a **default** one.  
- A **default constructor** has no parameters and initializes values manually or with defaults.  
- A **parameterized constructor** allows passing values at object creation.  
- **Overloading** constructors lets you define multiple ways to initialize an object.  
- Using **default arguments** in constructors simplifies initialization.  
- **Initializer lists** provide efficient initialization and are required for **const** or **reference** members.  

Next, check out **[Copy_Constructors.md](Copy_Constructors.md)** to learn about creating copies of objects in C++.
