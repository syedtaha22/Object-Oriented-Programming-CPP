# Generic Programming

This module introduces **generic programming** in C++, a paradigm that allows writing **flexible**, **reusable**, and **type-independent** code. The main mechanism that enables this is the use of **templates**, which make it possible to write code that works for a wide range of types without duplication.

Templates are a core part of modern C++, and are widely used in the Standard Template Library (STL).

## Topics Covered

1. **Template Basics**  
   - Syntax and instantiation of function and class templates  
   - Type inference  
   - Templates with multiple parameters  
   - Member function definitions  
   - Common limitations and workarounds  

2. **Type Deduction** 
   - How the compiler deduces types in templated code  

3. **Best Practices**
   - When to use templates
   - Code bloat and compile-time considerations
   - Combining templates with object-oriented design

## Folder Structure

- [Templates.md](Templates.md): Basics of generic functions and classes using templates.  
- [TypeDeduction.md](TypeDeduction.md): Introduction to how types are inferred in templated code, and how to guide deduction effectively.  
- [examples/](examples/): Demonstration of template usage in small, focused C++ programs.  
- [practice_questions/](practice_questions/): Problems designed to reinforce your understanding of template definitions and usage.  

This module builds on your knowledge of **functions**, **classes**, and **constructors**, and gives you the tools to write **type-generic** code. Begin with [Templates.md](Templates.md) to learn how templates can eliminate code repetition and increase flexibility in C++.
