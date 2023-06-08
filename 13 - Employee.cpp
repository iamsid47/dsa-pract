#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

const int MAX_RECORDS = 100;

struct Employee {
    int empID;
    char name[50];
    char designation[50];
    double salary;
};

struct Index {
    int empID;
    int filePos;
};

void addEmployee() {
    Employee emp;

    cout << "\nEnter Employee ID: ";
    cin >> emp.empID;
    cin.ignore();
    cout << "Enter Name: ";
    cin.getline(emp.name, 50);
    cout << "Enter Designation: ";
    cin.getline(emp.designation, 50);
    cout << "Enter Salary: ";
    cin >> emp.salary;

    ofstream dataFile("employeeData.dat", ios::binary | ios::app);
    dataFile.write(reinterpret_cast<char*>(&emp), sizeof(Employee));
    dataFile.close();

    cout << "\nEmployee added successfully!" << endl;
}

void deleteEmployee() {
    int empID;
    bool found = false;

    cout << "\nEnter Employee ID to delete: ";
    cin >> empID;

    ifstream inFile("employeeData.dat", ios::binary);
    ofstream tempFile("tempData.dat", ios::binary);

    Employee emp;
    while (inFile.read(reinterpret_cast<char*>(&emp), sizeof(Employee))) {
        if (emp.empID == empID) {
            found = true;
            continue;
        }
        tempFile.write(reinterpret_cast<char*>(&emp), sizeof(Employee));
    }

    inFile.close();
    tempFile.close();

    remove("employeeData.dat");
    rename("tempData.dat", "employeeData.dat");

    if (found) {
        cout << "\nEmployee deleted successfully!" << endl;
    } else {
        cout << "\nEmployee not found!" << endl;
    }
}

void displayEmployee() {
    int empID;
    bool found = false;

    cout << "\nEnter Employee ID to display: ";
    cin >> empID;

    ifstream inFile("employeeData.dat", ios::binary);

    Employee emp;
    while (inFile.read(reinterpret_cast<char*>(&emp), sizeof(Employee))) {
        if (emp.empID == empID) {
            found = true;
            break;
        }
    }

    inFile.close();

    if (found) {
        cout << "\nEmployee ID: " << emp.empID << endl;
        cout << "Name: " << emp.name << endl;
        cout << "Designation: " << emp.designation << endl;
        cout << "Salary: " << emp.salary << endl;
    } else {
        cout << "\nEmployee not found!" << endl;
    }
}

int main() {
    int choice;

    while (true) {
        cout << "\nEmployee Management System\n";
        cout << "1. Add Employee\n";
        cout << "2. Delete Employee\n";
        cout << "3. Display Employee\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                deleteEmployee();
                break;
            case 3:
                displayEmployee();
                break;
            case 4:
                cout << "\nExiting...\n";
                exit(0);
            default:
                cout << "\nInvalid choice! Please try again.\n";
        }
    }

    return 0;
}
