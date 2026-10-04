#include <stdio.h>
#include "reports.h"

/* Budget data is stored in budget.c */
extern Budget budgets[MAX_DEPARTMENTS];
extern int budgetCount;

/* Employee Report */
void displayEmployeeReport(Employee employees[], int numEmployees)
{
    int i;
    float totalSalary = 0.0f;
    float averageSalary;
    float highestSalary;
    float lowestSalary;

    printf("\n==========================================\n");
    printf("         MUNICIPAL EMPLOYEE REPORT\n");
    printf("==========================================\n");

    if (numEmployees == 0)
    {
        printf("No employee data available.\n");
        printf("==========================================\n");
        return;
    }

    highestSalary = calculateSalary(employees[0]);
    lowestSalary = calculateSalary(employees[0]);

    for (i = 0; i < numEmployees; i++)
    {
        float salary = calculateSalary(employees[i]);

        totalSalary += salary;

        if (salary > highestSalary)
        {
            highestSalary = salary;
        }

        if (salary < lowestSalary)
        {
            lowestSalary = salary;
        }
    }

    averageSalary = totalSalary / numEmployees;

    printf("Total Employees: %d\n", numEmployees);
    printf("Total Salary: N$ %.2f\n", totalSalary);
    printf("Average Salary: N$ %.2f\n", averageSalary);
    printf("Highest Salary: N$ %.2f\n", highestSalary);
    printf("Lowest Salary: N$ %.2f\n", lowestSalary);
    printf("==========================================\n");
}

/* Budget Report */
void displayBudgetReport(void)
{
    int i;
    float totalAllocated = 0.0f;
    float totalExpenditure = 0.0f;
    float totalRemaining = 0.0f;
    int exceededCount = 0;

    printf("\n==========================================\n");
    printf("           MUNICIPAL BUDGET REPORT\n");
    printf("==========================================\n");

    if (budgetCount == 0)
    {
        printf("No budget data available.\n");
        printf("==========================================\n");
        return;
    }

    for (i = 0; i < budgetCount; i++)
    {
        totalAllocated += budgets[i].allocatedBudget;
        totalExpenditure += budgets[i].expenditure;
        totalRemaining += budgets[i].remainingBudget;

        if (budgets[i].expenditure > budgets[i].allocatedBudget)
        {
            exceededCount++;
        }
    }

    printf("Total Departments: %d\n", budgetCount);
    printf("Total Allocated Budget: N$ %.2f\n", totalAllocated);
    printf("Total Expenditure: N$ %.2f\n", totalExpenditure);
    printf("Total Remaining Budget: N$ %.2f\n", totalRemaining);
    printf("Departments Over Budget: %d\n", exceededCount);

    printf("\nDepartment Budget Summary:\n");
    printf("------------------------------------------\n");

    for (i = 0; i < budgetCount; i++)
    {
        printf("%-20s | Allocated: N$ %.2f | Expenditure: N$ %.2f | Remaining: N$ %.2f\n",
               budgets[i].department,
               budgets[i].allocatedBudget,
               budgets[i].expenditure,
               budgets[i].remainingBudget);
    }

    printf("==========================================\n");
}

/* Supplier Report */
void displaySupplierReport(Supplier suppliers[], int numSuppliers)
{
    int i;

    printf("\n==========================================\n");
    printf("         MUNICIPAL SUPPLIER REPORT\n");
    printf("==========================================\n");
    printf("Total Suppliers Registered: %d\n", numSuppliers);
    printf("------------------------------------------\n");

    if (numSuppliers == 0)
    {
        printf("No supplier data available to generate report.\n");
        printf("==========================================\n");
        return;
    }

    printf("%-5s | %-20s | %-20s | %-15s | %-15s\n",
           "ID", "Name", "Email", "Phone", "Location");

    printf("--------------------------------------------------------------------------------\n");

    for (i = 0; i < numSuppliers; i++)
    {
        printf("%-5d | %-20s | %-20s | %-15s | %-15s\n",
               suppliers[i].supplierID,
               suppliers[i].name,
               suppliers[i].email,
               suppliers[i].phone,
               suppliers[i].location);
    }

    printf("==========================================\n");
}

/* Asset Report */
void displayAssetReport(Asset assets[], int numAssets)
{
    int i;
    float totalValue = 0.0f;

    printf("\n==========================================\n");
    printf("           MUNICIPAL ASSET REPORT\n");
    printf("==========================================\n");

    if (numAssets == 0)
    {
        printf("No asset data available.\n");
        printf("==========================================\n");
        return;
    }

    for (i = 0; i < numAssets; i++)
    {
        totalValue += assets[i].purchaseValue;
    }

    printf("Total Assets: %d\n", numAssets);
    printf("Total Asset Value: N$ %.2f\n", totalValue);

    printf("\nAsset Summary:\n");
    printf("------------------------------------------\n");

    for (i = 0; i < numAssets; i++)
    {
        printf("ID: %d | Name: %s | Type: %s | Value: N$ %.2f | Department: %s | Condition: %s\n",
               assets[i].assetID,
               assets[i].name,
               assets[i].type,
               assets[i].purchaseValue,
               assets[i].department,
               assets[i].condition);
    }

    printf("==========================================\n");
}

/* Reports Menu */
void reportsMenu(
    Employee employees[],
    int numEmployees,
    Supplier suppliers[],
    int numSuppliers,
    Asset assets[],
    int numAssets
)
{
    int choice;

    do
    {
        printf("\n==========================================\n");
        printf("             REPORTS MODULE\n");
        printf("==========================================\n");
        printf("1. Employee Report\n");
        printf("2. Budget Report\n");
        printf("3. Supplier Report\n");
        printf("4. Asset Report\n");
        printf("5. Return to Main Menu\n");
        printf("==========================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                displayEmployeeReport(employees, numEmployees);
                break;

            case 2:
                displayBudgetReport();
                break;

            case 3:
                displaySupplierReport(suppliers, numSuppliers);
                break;

            case 4:
                displayAssetReport(assets, numAssets);
                break;

            case 5:
                printf("\nReturning to Main Menu...\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 5);
}