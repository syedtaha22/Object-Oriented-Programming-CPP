## **Practice Problems on Constructors, Destructors, and `this` Operator**

1. **Using `this` for Fluent Interface Design**  
   Create a class `Vector3D` with three member variables `x`, `y`, and `z`. Implement methods `addX`, `addY`, and `addZ`, each of which modifies one of the coordinates and returns `*this` to allow for method chaining.  
   Demonstrate method chaining by adding values to `x`, `y`, and `z` in a single line of code.

---

2. **Handling Multiple Constructors in a Single Class**  
   Write a class `Matrix` that represents a 2D array. Implement multiple constructors: one that initializes the matrix with given dimensions, and another that initializes it by copying another matrix. Ensure that the class handles memory management correctly using both constructors.  
   Test by creating multiple matrices and copying them. Check for any issues with deep copying and memory management.

---

3. **Handling Memory for a Linked List in a Destructor**  
    Create a class `Node` that represents a node in a singly linked list, with a constructor that dynamically allocates memory for an integer. Write a destructor for both the `Node` class and a `LinkedList` class to handle the deletion of all nodes when the list is destroyed.  
    Test by creating a linked list and ensure memory is freed without leaks.

---

4. **Smart Pointer Simulation with Destructor**  
    Implement a class `SmartPointer` that mimics the behavior of a smart pointer. The class should hold a dynamically allocated integer and have a constructor that initializes it, a copy constructor for deep copying, and a destructor that frees the memory.  
    Test by creating `SmartPointer` objects and ensure that memory is managed correctly.

---

5. **Resource Management in a File Handling Class**  
    Create a class `FileHandler` that manages a file stream (`std::ifstream` or `std::ofstream`). Implement a constructor that opens a file and a destructor that closes the file. Handle the case where an error occurs while opening the file.  
    Test by creating a `FileHandler` object and reading/writing to a file. Ensure proper cleanup when the object is destroyed.

---

6. **Memory Allocation and Cleanup in a Stack Class**  
    Implement a class `Stack` that holds a dynamically allocated array to represent a stack of integers. The class should have a constructor, destructor, and an overloaded assignment operator. Ensure that when objects are copied or assigned, memory is managed properly.  
    Test by performing stack operations and verifying that no memory is leaked.
