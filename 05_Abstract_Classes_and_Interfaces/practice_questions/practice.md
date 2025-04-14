# Practice Questions: Abstract Classes and Interfaces


1. **Abstract Appliance**  
   You are tasked with modeling household appliances.  
   Create an abstract class `Appliance` that has a pure virtual method `turnOn()`.  
   Derive the classes `WashingMachine` and `Microwave` from `Appliance`.  
   Implement the `turnOn()` method in both `WashingMachine` and `Microwave` with behavior specific to their type:
   - `WashingMachine`: prints "Washing machine is starting."
   - `Microwave`: prints "Microwave is heating."

   In `main()`, create instances of both and call `turnOn()` polymorphically using a pointer to `Appliance`.

---

2. **Interface-Based Logger**  
   Design a simple logging system using interfaces.  
   Create an interface `Logger` with a method `log(string message)`.  
   Implement two classes:
   - `FileLogger`: simulates logging to a file by printing a message "Logging to file: <message>"
   - `ConsoleLogger`: simulates logging to the console by printing a message "Logging to console: <message>"

   In `main()`, create instances of both classes and call `log()` polymorphically using a pointer to `Logger`.

---

3. **Button Click Handler**  
   Build a simple button-click handler system using interfaces.  
   Define an interface `Clickable` with a method `onClick()`.  
   Implement two classes:
   - `Button`: prints "Button clicked."
   - `ImageButton`: prints "Image button clicked."

   In `main()`, create instances of both classes and call `onClick()` polymorphically using a pointer to `Clickable`.

---

4. **Employee Payment System**  
   You are designing a payment system for different types of employees.  
   Create an abstract class `Employee` with a pure virtual method `calculatePay()`.  
   Derive the classes `HourlyEmployee` and `SalariedEmployee`:
   - `HourlyEmployee`: has an additional member `hourlyRate` and `hoursWorked`. Calculate pay as `hourlyRate * hoursWorked`.
   - `SalariedEmployee`: has a fixed salary. Return the salary value in `calculatePay()`.

   In `main()`, create instances of both types of employees, call `calculatePay()`, and print the result polymorphically.

---

5. **Notification System**  
   You are building a simple notification system that sends messages via different channels.  
   Define an interface `Notifier` with a method `send(string message)`.  
   Implement two classes:
   - `EmailNotifier`: simulates sending a message via email by printing "Email sent: <message>"
   - `SMSNotifier`: simulates sending a message via SMS by printing "SMS sent: <message>"

   In `main()`, create instances of both classes and call `send()` polymorphically using a pointer to `Notifier`.

---

6. **Temperature Sensor Interface**  
   You are designing a system to read data from multiple types of sensors.  
   Create an interface `Sensor` with methods `readValue()` (returns a `double`) and `calibrate()`.  
   Implement two classes:
   - `TemperatureSensor`: returns a simulated temperature value in `readValue()` and prints "Calibrating temperature sensor..." in `calibrate()`.
   - `PressureSensor`: returns a simulated pressure value in `readValue()` and prints "Calibrating pressure sensor..." in `calibrate()`.

   In `main()`, create instances of both sensor types and call `readValue()` and `calibrate()` polymorphically.

---

7. **Zoo Management System**  
   Design a zoo management system.  
   Create an abstract class `Animal` with pure virtual methods `feed()` and `clean()`.  
   Derive three classes:
   - `Lion`: implements `feed()` and `clean()` with behavior specific to lions.
   - `Elephant`: implements `feed()` and `clean()` with behavior specific to elephants.
   - `Penguin`: implements `feed()` and `clean()` with behavior specific to penguins.

   In `main()`, create a list of `Animal*` and perform the `feed()` and `clean()` operations on each animal polymorphically.

---

8. **Plugin System**  
   Build a simple plugin system.  
   Create an interface `Plugin` with a method `execute()`.  
   Implement two classes:
   - `LoggingPlugin`: prints "Logging Plugin Executed."
   - `AuthenticationPlugin`: prints "Authentication Plugin Executed."

   In `main()`, create a list of `Plugin*`, add instances of both plugins, and execute them polymorphically.

---

9. **Streaming Service Simulation**  
   Simulate a streaming service with different types of media.  
   Define an interface `Playable` with methods `play()` and `pause()`.  
   Implement three classes:
   - `Movie`: implements `play()` and `pause()` with behavior specific to movies.
   - `TVShow`: implements `play()` and `pause()` with behavior specific to TV shows.
   - `MusicTrack`: implements `play()` and `pause()` with behavior specific to music tracks.

   In `main()`, create a list of `Playable*`, add instances of all three types, and test the `play()` and `pause()` methods polymorphically.

---

10. **Robot Controller**  
    Design a system to control different types of robots.  
    Create an abstract class `Robot` with pure virtual methods `moveForward()`, `rotate()`, and `shutdown()`.  
    Derive two classes:
    - `CleaningRobot`: implements `moveForward()` to simulate moving and `rotate()` to simulate rotating.
    - `SecurityRobot`: implements `moveForward()` and `rotate()` with different behaviors.

    In `main()`, create instances of both robots and control them polymorphically, calling `moveForward()`, `rotate()`, and `shutdown()`.
