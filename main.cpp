#include <iostream>
#include<employee.c++>
using namespace std;

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
