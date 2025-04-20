/*********************************************************************************************************************
 * Task 3:
 *      In this lab task, you will develop a program to manage employee records. The program should provide
 *      functionalities to add, delete, and display employee records, as well as to perform various operations
 *      on the records using functors, function pointers, and lambdas with STL.
 *      Task Instructions:
 *
 *      Define a class named Employee with the following attributes:
 *          • Employee ID (int)
 *          • Name (std::string)
 *          • Department (std::string)
 *          • Salary (double)
 *
 *      Implement a class named EmployeeManager to manage employee records. This class should have the following
 *      functionalities:
 *          1. Add a new employee record.
 *          2. Delete an existing employee record by ID.
 *          3. Display all employee records.
 *          4. Sort employee records based on different criteria using functors, function pointers, or lambdas.
 *          5. Find employees with salaries above a certain threshold using a lambda function.
 *          6. Calculate the average salary of all employees.
 *          7. Customize display of employee records by providing different display options using function pointers.
 *
 *      Note: Use std::map to store employee records.
 *
 *      Task Requirements:
 *          1. Implement the Employee class with the specified attributes.
 *          2. Implement the EmployeeManager class with the specified functionalities.
 *          3. Use functors, function pointers, or lambdas where appropriate to perform sorting, filtering, and
 *             customization of display.
 *          5. Test the program with various scenarios to ensure correctness and functionality.
 **********************************************************************************************************************/

#include <iostream>
#include <map>
#include <algorithm>
#include <functional>
#include <numeric>

class Employee {
public:
    int id;
    std::string name;
    std::string department;
    double salary;

    Employee(int id, const std::string& name, const std::string& department, double salary)
        : id(id), name(name), department(department), salary(salary) {
    }

    Employee() : id(0), name(""), department(""), salary(0.0) {
    }


    // Overload << operator for easy printing
    friend std::ostream& operator<<(std::ostream& os, const Employee& employee) {
        os << "ID: " << employee.id << ", Name: " << employee.name
            << ", Department: " << employee.department << ", Salary: " << employee.salary;
        return os;
    }
};

class EmployeeManager {
private:
    std::map<int, Employee> employees; // Map to store employee records with ID as key
public:
    // Add a new employee record
    void addEmployee(const Employee& employee) {
        employees[employee.id] = employee;
    }

    // Delete an existing employee record by ID
    void deleteEmployee(int id) {
        employees.erase(id);
    }

    // Display all employee records
    void displayEmployees() const {
        std::for_each(employees.begin(), employees.end(),
            [](const std::pair<int, Employee>& pair) {
                std::cout << pair.second << std::endl;
            });
    }

    // Sort employee records based on different criteria using functors, function pointers, or lambdas
    std::vector<Employee> sortEmployees(const std::function<bool(const Employee&, const Employee&)>& comparator) {
        std::vector<Employee> sortedEmployees;
        for (const auto& pair : employees) { sortedEmployees.push_back(pair.second); }

        std::sort(sortedEmployees.begin(), sortedEmployees.end(), comparator);
        return sortedEmployees;
    }

    // Find employees with salaries above a certain threshold using a lambda function
    std::vector<Employee> findHighSalaryEmployees(double threshold) const {
        std::vector<Employee> result;
        std::for_each(employees.begin(), employees.end(),
            [threshold, &result](const auto& pair) {
                if (pair.second.salary > threshold) {
                    result.push_back(pair.second); // filter + transform
                }
            });
        return result;
    }


    // Calculate the average salary of all employees
    double calculateAverageSalary() const {
        if (employees.empty()) return 0.0;

        double sum = std::accumulate(employees.begin(), employees.end(), 0.0,
            [](double sum, const std::pair<int, Employee>& pair) {return sum + pair.second.salary;});

        return sum / employees.size();
    }

    // Customize display of employee records by providing different display options using function pointers
    void displayWithOption(void (*displayFunc)(const Employee&)) const {
        for (const auto& pair : employees) {
            displayFunc(pair.second);
        }
    }
};

// Function to display employee details in a custom format
void customDisplay(const Employee& employee) {
    std::cout << "Employee Details: " << employee.name << " (ID: " << employee.id << ") - Salary: " << employee.salary << "\n";
}

void print(const std::string& title, const std::vector<Employee>& items) {
    std::cout << title << "\n";
    std::for_each(items.begin(), items.end(), [](const Employee& item) {std::cout << item << "\n";});
    std::cout << "\n";
}

int main() {
    EmployeeManager manager;

    // Adding employees
    manager.addEmployee(Employee(3, "C", "Media", 600));
    manager.addEmployee(Employee(4, "D", "IT", 700));
    manager.addEmployee(Employee(1, "A", "HR", 900));
    manager.addEmployee(Employee(5, "E", "HR", 500));
    manager.addEmployee(Employee(2, "B", "IT", 800));

    // Display all employees
    std::cout << "All Employees:\n";
    manager.displayEmployees();
    std::cout << "\n";

    // Sort employees by salary using a lambda function
    auto sortedBySalary = manager.sortEmployees([](const Employee& a, const Employee& b) { return a.salary < b.salary; });
    print("Sorted Employees by Salary:", sortedBySalary);

    // Find employees with salary above a certain threshold
    auto highSalaryEmployees = manager.findHighSalaryEmployees(700);
    print("Employees with Salary > 700:", highSalaryEmployees);

    // Calculate average salary
    double averageSalary = manager.calculateAverageSalary();
    std::cout << "Average Salary: " << averageSalary << "\n\n";

    // Customize display of employee records
    std::cout << "Custom Display:\n";
    manager.displayWithOption(customDisplay);

    return 0;
}
