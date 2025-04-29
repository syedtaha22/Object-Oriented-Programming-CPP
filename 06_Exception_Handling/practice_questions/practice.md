# Practice Questions – Exception Handling in C++

These problems are designed to deepen your understanding of exception handling by introducing edge cases, design challenges, and realistic scenarios based on what you’ve learned in this module.

---

### 1. Exception Safety with Arrays  
Create a class `IntArray` that dynamically allocates an array of integers in its constructor.  
Now add a method `resize(size_t newSize)` that reallocates the array.  
Ensure that if memory allocation fails, there are no memory leaks and the object remains in a valid state.

---

### 2. Exception in Constructor  
Define a class `NetworkSession` that throws an exception from its constructor to simulate a failed connection.  
In `main()`, create multiple such objects and observe which destructors get called.  

---

### 3. Exception Propagation Across Threads (Conceptual)  
C++ exceptions cannot be propagated across threads.  
Write a short explanation of why this design choice exists.  
Then, using `std::promise` and `std::future`, simulate how one might manually catch an exception in a thread and forward it to the main thread for handling.

---

### 4. Exception in Destructor  
Create a class `Logger` whose destructor throws an exception.  
Now use an object of this class inside a `try` block that also throws.  
Observe the behavior and explain why the program calls `std::terminate()`.  
**Goal:** Understand why destructors must never throw during stack unwinding.

---

### 5. Polymorphic Exception Handling  
Create a base class `MyBaseException` (inheriting from `std::exception`) and a derived class `MyDerivedException`.  
Throw the derived type and catch it using both `catch (MyDerivedException&)` and `catch (MyBaseException&)`.  
Explain the role of polymorphism in exception handling and why catching base types is often used as a fallback.

---

### 6. Exception Inside Loops  
Write a loop that reads integers from the user.  
If the input is not a valid integer, throw an exception.  
Use exception handling to ensure the program **continues execution and prompts again**, rather than terminating.  
**Goal:** Practice integrating exception handling into user input flows.

---

### 7. Catching Unknown Exceptions  
Write a function that randomly throws an `int`, a `std::string`, or a `std::runtime_error`.  
Use `catch(...)` to catch unknown exception types.  
Also, add a comment on the limitations of `catch(...)` (e.g., lack of error context, inability to recover specific information).
