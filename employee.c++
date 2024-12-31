#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Employee {
private:
    int id;
    string name;
    string position;
    double salary;

public:
    // Constructor
    Employee(int id, const string& name, const string& position, double salary)
        : id(id), name(name), position(position), salary(salary) {}

    // Getters
    int getId() const { return id; }
    string getName() const { return name; }
    string getPosition() const { return position; }
    double getSalary() const { return salary; }

    // Setters
    void setName(const string& newName) { name = newName; }
    void setPosition(const string& newPosition) { position = newPosition; }
    void setSalary(double newSalary) { salary = newSalary; }

    // Display Employee Details
    void display() const {
        cout << "ID: " << id << ", Name: " << name
             << ", Position: " << position
             << ", Salary: $" << salary << endl;
    }
};

class EmployeeManager {
private:
    vector<Employee> employees;

    // Find employee by ID
    int findEmployeeById(int id) {
        for (size_t i = 0; i < employees.size(); i++) {
            if (employees[i].getId() == id)
                return i;
        }
        return -1; // Not found
    }

public:
    // Create Employee
    void createEmployee() {
        int id;
        string name, position;
        double salary;

        cout << "Enter Employee ID: ";
        cin >> id;
        cin.ignore(); // Ignore newline
        cout << "Enter Employee Name: ";
        getline(cin, name);
        cout << "Enter Employee Position: ";
        getline(cin, position);
        cout << "Enter Employee Salary: ";
        cin >> salary;

        employees.emplace_back(id, name, position, salary);
        cout << "Employee added successfully.\n";
    }

    // Read all Employees
    void readEmployees() {
        if (employees.empty()) {
            cout << "No employees to display.\n";
            return;
        }
        for (const auto& emp : employees) {
            emp.display();
        }
    }

    // Update Employee
    void updateEmployee() {
        int id;
        cout << "Enter Employee ID to update: ";
        cin >> id;

        int index = findEmployeeById(id);
        if (index == -1) {
            cout << "Employee not found.\n";
            return;
        }

        string name, position;
        double salary;
        cin.ignore(); // Ignore newline
        cout << "Enter New Name: ";
        getline(cin, name);
        cout << "Enter New Position: ";
        getline(cin, position);
        cout << "Enter New Salary: ";
        cin >> salary;

        employees[index].setName(name);
        employees[index].setPosition(position);
        employees[index].setSalary(salary);
        cout << "Employee updated successfully.\n";
    }

    // Delete Employee
    void deleteEmployee() {
        int id;
        cout << "Enter Employee ID to delete: ";
        cin >> id;

        int index = findEmployeeById(id);
        if (index == -1) {
            cout << "Employee not found.\n";
            return;
        }

        employees.erase(employees.begin() + index);
        cout << "Employee deleted successfully.\n";
    }
};

int main() {
    EmployeeManager manager;
    int choice;

    while (true) {
        cout << "\nEmployee Management System\n";
        cout << "1. Add Employee\n";
        cout << "2. View Employees\n";
        cout << "3. Update Employee\n";
        cout << "4. Delete Employee\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            manager.createEmployee();
            break;
        case 2:
            manager.readEmployees();
            break;
        case 3:
            manager.updateEmployee();
            break;
        case 4:
            manager.deleteEmployee();
            break;
        case 5:
            cout << "Exiting program.\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}
