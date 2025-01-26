## Practice Questions: Classes and Objects

In this section, you'll practice writing and understanding C++ code that involves creating and manipulating classes and objects. By solving these problems, you'll solidify your understanding of how to define and interact with classes, as well as how to implement important Object-Oriented Programming concepts like encapsulation and abstraction.

---

### 1. **Book Class with Abstraction**

Create a `Book` class that represents a book in a library. The class should have:
- Private data members: `title`, `author`, `yearOfPublication`, and `status` (whether the book is available or checked out).
- Public functions to check out the book and check it back in. The status should update accordingly.
- A function to display the book details (title, author, year, and status).

---

### 2. **Car Class with Simple Methods**

Design a `Car` class that contains:
- Private data members: `make`, `model`, `year`, and `fuelLevel`.
- A constructor to initialize these attributes.
- A public method `drive()` that simulates driving the car (decreases the fuel level).
- A public method `refuel()` to refill the car’s fuel.

---

### 3. **Student Class with Constructor Overloading**

Create a `Student` class with the following private members:
- `name` (string)
- `age` (int)
- `grades` (array of integers)

Implement constructor overloading:
- A default constructor that sets the student’s name to `"Unknown"` and age to `0`.
- A parameterized constructor that initializes all member variables.
- A function to calculate and display the average grade of the student.

---

### 4. **Library System Class**

Create a `Library` class that represents a library with the following functionality:
- A private member `bookCount` (integer) to keep track of the number of books in the library.
- A public method `addBook()` that increments the `bookCount` by 1 when a new book is added.
- A public method `removeBook()` that decrements the `bookCount` by 1 when a book is removed.
- A method `getBookCount()` that returns the current number of books in the library.

---

### 5. **ATM Transaction Simulation**

Write a program that simulates real-world ATM transactions. You will need to implement multiple classes to represent the various aspects of an ATM system. The program should allow users to create accounts, make deposits, withdrawals, and perform secure transfers between accounts.

Some of the key actions to simulate:
- A user can create a bank account with a unique account number and an initial balance.
- The user should be able to deposit and withdraw money from the account, ensuring that withdrawals do not exceed the balance.
- The program should support transferring money between different accounts, with validation to ensure the sender has enough funds.
- Each transaction should be properly recorded, and account information (balance, transactions) should be kept secure.

### Things to Consider:
- How would you represent a bank account? (Think of the private members you might need.)
- What classes are required to simulate the ATM system?
- How will you ensure secure transfers between accounts? (Consider how to protect sensitive information like account numbers and balance.)
- What functions or methods will be necessary to simulate deposits, withdrawals, and transfers?

---

These questions will guide you through the essential concepts of classes and objects, giving you a deeper understanding of how to implement and manipulate classes effectively in C++.
