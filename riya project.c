#include <stdio.h>   // Standard I/O operations
#include <stdlib.h>  // Standard library functions
#include <string.h>  // String manipulation functions

#define MAX_EMPLOYEES 100  // Define a constant for the maximum number of employees

// Structure to store employee details
struct Employee {
    int id;          // Employee ID
    char name[50];   // Employee Name
    char role[30];   // Employee Role
    float salary;    // Employee Salary
};

// Function to add an employee to the list
void addEmployee(struct Employee employees[], int *count) {
    if (*count >= MAX_EMPLOYEES) {  // Check if maximum employees limit is reached
        printf("Employee limit reached.\n");
        return;
    }

    // Collect employee details from user input
    printf("Enter Employee ID: ");
    scanf("%d", &employees[*count].id);
    printf("Enter Name: ");
    scanf("%s", employees[*count].name);
    printf("Enter Role: ");
    scanf("%s", employees[*count].role);
    printf("Enter Salary: ");
    scanf("%f", &employees[*count].salary);

    (*count)++;  // Increment employee count
    printf("Employee added successfully!\n");
}

// Function to delete an employee based on ID
void deleteEmployee(struct Employee employees[], int *count, int id) {
    for (int i = 0; i < *count; i++) {  // Loop through employees
        if (employees[i].id == id) {  // Check if ID matches
            for (int j = i; j < *count - 1; j++) {  // Shift remaining employees
                employees[j] = employees[j + 1];
            }
            (*count)--;  // Reduce employee count
            printf("Employee deleted successfully!\n");
            return;
        }
    }
    printf("Employee not found.\n");
}

// Function to search for an employee by ID
void searchEmployee(struct Employee employees[], int count, int id) {
    for (int i = 0; i < count; i++) {  // Loop through employees
        if (employees[i].id == id) {  // Check if ID matches
            // Display employee details
            printf("Employee Found: %s, Role: %s, Salary: %.2f\n",
                   employees[i].name, employees[i].role, employees[i].salary);
            return;
        }
    }
    printf("Employee not found.\n");
}

// Function to display all employees
void displayEmployees(struct Employee employees[], int count) {
    printf("\nEmployee List:\n");
    for (int i = 0; i < count; i++) {  // Loop through employees and print details
        printf("ID: %d, Name: %s, Role: %s, Salary: %.2f\n",
               employees[i].id, employees[i].name, employees[i].role, employees[i].salary);
    }
}

// Main function that drives the program
int main() {
    struct Employee employees[MAX_EMPLOYEES];  // Declare an array of employees
    int count = 0;  // Variable to track employee count
    int choice, id;  // Variables for user input

    // Infinite loop for the menu-driven system
    while (1) {
        printf("\nEmployee Management System\n");
        printf("1. Add Employee\n2. Delete Employee\n3. Search Employee\n4. Display Employees\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Process user choice using a switch-case
        switch (choice) {
            case 1:
                addEmployee(employees, &count);  // Call function to add an employee
                break;
            case 2:
                printf("Enter Employee ID to delete: ");
                scanf("%d", &id);
                deleteEmployee(employees, &count, id);  // Call function to delete an employee
                break;
            case 3:
                printf("Enter Employee ID to search: ");
                scanf("%d", &id);
                searchEmployee(employees, count, id);  // Call function to search for an employee
                break;
            case 4:
                displayEmployees(employees, count);  // Call function to display all employees
                break;
            case 5:
                printf("Exiting program.\n");  // Exit the program
                return 0;
            default:
                printf("Invalid choice. Try again.\n");  // Handle invalid input
        }
    }
}