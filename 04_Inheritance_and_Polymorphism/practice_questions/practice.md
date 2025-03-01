# **Practice Problems: Inheritance, Polymorphism, and Casting**

## **Easy**

1. You are designing a basic **shape hierarchy** where each shape can calculate its area. Create a `Shape` base class with a `calculateArea()` function. Derive two classes, `Rectangle` and `Circle`, that override this function. Implement a program where an array of `Shape*` stores different shapes, demonstrating polymorphism by calling `calculateArea()` dynamically.

2. Consider a **vehicle rental system** where all vehicles have a `displayInfo()` function. Create a base class `Vehicle` and derive two classes, `Car` and `Bike`. Override `displayInfo()` in both derived classes. Store `Car` and `Bike` objects in `Vehicle*` pointers and observe how function calls behave.

3. A **university system** has different types of members: `Person`, `Student`, and `Professor`. The `Person` class has a `getRole()` function that is overridden in the derived classes. Use a `Person*` pointer to store objects of `Student` and `Professor`, ensuring the correct role is printed.

4. Develop a **banking application** with a `BankAccount` base class and two derived classes: `SavingsAccount` and `CheckingAccount`. The base class should have a `withdraw()` function, which is overridden in both derived classes to implement different withdrawal limits. Create objects dynamically and call `withdraw()` through a `BankAccount*` pointer.

5. Create a **media player system** where a base class `MediaFile` has a `play()` function. The derived classes `AudioFile` and `VideoFile` override `play()`. Store objects of `AudioFile` and `VideoFile` in a `MediaFile*` array and observe the function behavior.

6. Implement a **pet management system** with a base class `Pet` and derived classes `Dog` and `Cat`. The `Pet` class has a `makeSound()` function, which is overridden in `Dog` and `Cat`. Demonstrate polymorphism by storing both objects in a `Pet*` array.

---

## **Intermediate**

1. You are building an **employee management system**. The `Employee` base class has a function `calculateSalary()`, which is overridden in `FullTimeEmployee` and `PartTimeEmployee`. Additionally, implement a `displayRole()` function. Store objects in an `Employee*` array and ensure dynamic function calls work correctly. Use `static_cast` to check whether an object is of type `FullTimeEmployee` or `PartTimeEmployee`.

2. Design a **file management system** with a base class `File` and derived classes `TextFile` and `ImageFile`. The base class has a `read()` function, which is overridden. Additionally, introduce a function `convertToImage()` in `ImageFile`. Use `dynamic_cast` to check if a `File*` points to an `ImageFile` and call `convertToImage()` accordingly.

3. Create a **game character system** with a base class `Character` and derived classes `Warrior` and `Mage`. The base class has a `performAction()` function, which the derived classes override. Use `dynamic_cast` to check if a `Character*` is pointing to a `Mage`, and if so, call a `castSpell()` function.

4. Implement an **electronics hierarchy** where `Device` is the base class, with `Laptop` and `Smartphone` as derived classes. `Laptop` has a `compileCode()` function, while `Smartphone` has a `makeCall()` function. Store objects in a `Device*` array and use `dynamic_cast` to check if a `Device*` points to a `Smartphone`, allowing it to make a call.

5. Create a **transportation system** with a base class `Transport` and derived classes `Train` and `Airplane`. The base class has a `travel()` function. `Airplane` has an additional function `fly()`. Store objects in a `Transport*` array and use `dynamic_cast` to check if an object is an `Airplane`, allowing it to fly.

6. Design a **software licensing system** where a base class `Software` has a `getLicenseType()` function. The derived classes `OpenSourceSoftware` and `ProprietarySoftware` override it. Introduce an additional function `activateLicense()` in `ProprietarySoftware`. Store objects in a `Software*` array and use `dynamic_cast` to check whether an object is proprietary, calling `activateLicense()` accordingly.

---

## **Advanced**

1. You are designing a **robotic automation system** where `Robot` is the base class. `AutonomousRobot` and `ManualRobot` are derived classes. `AutonomousRobot` has an additional function `navigate()` while `ManualRobot` has `receiveCommand()`. Store robots in a `Robot*` array, implement deep polymorphism with virtual destructors, and use `dynamic_cast` to differentiate between autonomous and manual robots dynamically.

2. Develop a **compiler simulation** where `Token` is the base class. Derived classes include `KeywordToken` and `OperatorToken`. Introduce a `getTokenType()` function that is overridden. Further, introduce a `parseKeyword()` function in `KeywordToken`. Use `dynamic_cast` to check if a `Token*` points to a `KeywordToken`, allowing it to be parsed differently.

3. Implement a **hierarchical banking system** where `Bank` is the base class. Derived classes include `InternationalBank` and `LocalBank`. `InternationalBank` has an `exchangeCurrency()` function. Store bank objects in a `Bank*` array, override a `processTransaction()` function, and use `dynamic_cast` to check if a bank is international.

4. Create a **simulation for self-driving vehicles** with a base class `Vehicle`. Derived classes include `ElectricVehicle` and `GasolineVehicle`. `ElectricVehicle` has a `chargeBattery()` function. Store vehicles in a `Vehicle*` array and dynamically call `chargeBattery()` only if the vehicle is electric.

5. Develop a **medical diagnosis system** where `MedicalCondition` is the base class. Derived classes include `InfectiousDisease` and `GeneticDisorder`. `InfectiousDisease` has an `isContagious()` function. Use `dynamic_cast` to check if a `MedicalCondition*` points to an `InfectiousDisease`, allowing special handling of contagious diseases.

6. Implement a **plugin-based architecture** where `Plugin` is the base class. Derived classes include `VideoPlugin` and `AudioPlugin`. `VideoPlugin` has a `renderVideo()` function. Store plugins in a `Plugin*` array and use `dynamic_cast` to check if a plugin is a `VideoPlugin`, calling `renderVideo()` accordingly.
