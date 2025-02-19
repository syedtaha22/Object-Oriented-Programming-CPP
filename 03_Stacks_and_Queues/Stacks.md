# Stacks

A **stack** is a linear data structure that follows the **Last In, First Out (LIFO)** principle. This means that the last element added to the stack is the first one to be removed.

## Key Characteristics of a Stack  
1. **LIFO Order** – The most recently added element is removed first.
2. **Restricted Access** – Elements can only be added (pushed) or removed (popped) from the top of the stack.
3. **Fixed or Dynamic Size** – Can be implemented using a fixed-size array or a dynamically growing structure.
4. **Operations in Constant Time** – Push and pop operations take **O(1)** time complexity in a properly managed stack.

## Real-World Applications of Stacks  
Stacks are widely used in various applications, including:

### 1. Function Call Stack  
When a function is called in a program, the function call details (such as return address, local variables, etc.) are pushed onto a call stack. When the function completes, it is popped from the stack. This enables recursion and function nesting.

### 2. Undo/Redo Operations  
Many applications, such as text editors, maintain a stack to store changes. When you press "Undo," the last action is popped from the stack, restoring the previous state.

### 3. Expression Evaluation  
Stacks are used to evaluate expressions, particularly postfix (Reverse Polish Notation) expressions, and convert infix expressions to postfix or prefix notation.

### 4. Browser Back/Forward Navigation  
Web browsers use stacks to keep track of visited web pages. When you press "Back," the current page is popped, and the previous page is displayed.

### 5. Compiler Syntax Parsing
Compilers use stacks to parse and evaluate syntax, particularly for languages with nested structures like parentheses, brackets, and braces.

### 6. Depth-First Search (DFS)
Graph traversal algorithms, such as DFS, utilize a stack to explore nodes deeply before backtracking.

### 7. Memory Management  
Stacks are used in system memory allocation, particularly for managing function execution, local variables, and control flow in programming languages.

## Stack Operations  
1. **Push(x)** – Adds element `x` to the top of the stack.
2. **Pop()** – Removes and returns the top element.
3. **Peek()** – Returns the top element without removing it.
4. **isEmpty()** – Checks if the stack is empty.
5. **Size()** – Returns the number of elements in the stack.

---

## Next Steps  
Now that we understand what a stack is and its applications, we will explore its **implementation** using a **resizing array**.

Continue reading: [Stack Implementation using a Resizing Array](Resizing_Array_Stack.md).
Or: [Stack Implementation using a Linked List](Linked_List_Stack.md).

Or move on to the next topic: [Queues](Queues.md).

