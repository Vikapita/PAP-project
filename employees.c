#include <stdio.h>
#include <string.h>
#include "employees.h"
#include "validation.h"

/* Add a new employee */
void addEmployee(Employee employees[], int *numEmployees)
{
    Employee *employee;

    if (*numEmployees >= MAX_EMPLOYEES)
    {
        printf("\nEmployee limit reached.\n");
        return;
    }

    employee = &employees[*numEmployees];

    printf("\n========== ADD EMPLOYEE ==========\n");

    /* Employee ID */
    do
    {
        printf("Enter Employee ID: ");
        scanf("%d", &employee->employeeID);
        clearInputBuffer();

        if (employee->employeeID <= 0)
        {
            printf("Employee ID must be greater than 0.\n");
        }

    } while (employee->employeeID <= 0);

    /* Employee name */
    do
    {
        printf("Enter Employee Name: ");
        fgets(employee->name, sizeof(employee->name), stdin);

        employee->name[strcspn(employee->name, "\n")] = '\0';

        if (strlen(employee->name) == 0)
        {
            printf("Employee name cannot be empty.\n");
        }

    } while (strlen(employee->name) == 0);

    /* Department */
    do
    {
        printf("Enter Department: ");
        fgets(employee->department, sizeof(employee->department), stdin);

        employee->department[strcspn(employee->department, "\n")] = '\0';

        if (strlen(employee->department) == 0)
        {
            printf("Department cannot be empty.\n");
        }

    } while (strlen(employee->department) == 0);

    /* Basic salary */
    do
    {
        printf("Enter Basic Salary: N$ ");
        scanf("%f", &employee->basicSalary);
        clearInputBuffer();

        if (employee->basicSalary < 0)
        {
            printf("Basic salary cannot be negative.\n");
        }

    } while (employee->basicSalary < 0);

    /* Housing allowance */
    do
    {
        printf("Enter Housing Allowance: N$ ");
        scanf("%f", &employee->housingAllowance);
        clearInputBuffer();

        if (employee->housingAllowance < 0)
        {
            printf("Housing allowance cannot be negative.\n");
        }

    } while (employee->housingAllowance < 0);

    /* Transport allowance */
    do
    {
        printf("Enter Transport Allowance: N$ ");
        scanf("%f", &employee->transportAllowance);
        clearInputBuffer();

        if (employee->transportAllowance < 0)
        {
            printf("Transport allowance cannot be negative.\n");
        }

    } while (employee->transportAllowance < 0);

    (*numEmployees)++;

    printf("\nEmployee added successfully!\n");
}

/* Display all employees */
void displayEmployees(Employee employees[], int employeeCount)
{
    int i;

    if (employeeCount == 0)
    {
        printf("\nNo employees registered.\n");
        return;
    }

    printf("\n========== EMPLOYEE LIST ==========\n");

    for (i = 0; i < employeeCount; i++)
    {
        printf("\nEmployee %d:\n", i + 1);
        printf("------------------------------------\n");

        printf("Employee ID: %d\n",
               employees[i].employeeID);

        printf("Name: %s\n",
               employees[i].name);

        printf("Department: %s\n",
               employees[i].department);

        printf("Basic Salary: N$ %.2f\n",
               employees[i].basicSalary);

        printf("Housing Allowance: N$ %.2f\n",
               employees[i].housingAllowance);

        printf("Transport Allowance: N$ %.2f\n",
               employees[i].transportAllowance);

        printf("Total Salary: N$ %.2f\n",
               calculateSalary(employees[i]));
    }
}

/* Search for an employee using their ID */
void searchEmployee(Employee employees[],
                    int employeeCount,
                    int employeeID)
{
    int i;
    int found = 0;

    for (i = 0; i < employeeCount; i++)
    {
        if (employees[i].employeeID == employeeID)
        {
            printf("\n========== EMPLOYEE FOUND ==========\n");

            printf("Employee ID: %d\n",
                   employees[i].employeeID);

            printf("Name: %s\n",
                   employees[i].name);

            printf("Department: %s\n",
                   employees[i].department);

            printf("Basic Salary: N$ %.2f\n",
                   employees[i].basicSalary);

            printf("Housing Allowance: N$ %.2f\n",
                   employees[i].housingAllowance);

            printf("Transport Allowance: N$ %.2f\n",
                   employees[i].transportAllowance);

            printf("Total Salary: N$ %.2f\n",
                   calculateSalary(employees[i]));

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nEmployee with ID %d not found.\n", employeeID);
    }
}

/* Calculate total salary */
float calculateSalary(Employee employee)
{
    return employee.basicSalary
         + employee.housingAllowance
         + employee.transportAllowance;
} void employeeMenu(Employee employees[], int *numEmployees)
{
    int choice;
    int employeeID;

    do
    {
        printf("\n");
        printf("========================================\n");
        printf("       EMPLOYEE MANAGEMENT MENU\n");
        printf("========================================\n");
        printf("  1. Add Employee\n");
        printf("  2. Display Employees\n");
        printf("  3. Search Employee\n");
        printf("  4. Return to Main Menu\n");
        printf("========================================\n");

        choice = getValidInt("Enter choice (1-4): ", 1, 4);

        switch (choice)
        {
            case 1:
                addEmployee(employees, numEmployees);
                break;

            case 2:
                displayEmployees(employees, *numEmployees);
                break;

            case 3:
                employeeID = getValidInt("Enter Employee ID to search: ", 1, 999999);
                searchEmployee(employees, *numEmployees, employeeID);
                break;

            case 4:
                printf("\nReturning to Main Menu...\n");
                break;
        }

    } while (choice != 4);
}