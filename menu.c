#include <stdio.h>
#include "menu.h"
#include "validation.h"
#include "budget.h"
#include "reports.h"

void displayMainMenu(void)
{
    printf("\n");
    printf("===================================================\n");
    printf("       MUNICIPAL FINANCIAL MANAGEMENT SYSTEM       \n");
    printf("===================================================\n");
    printf("  1. Employee Management\n");
    printf("  2. Budget Management\n");
    printf("  3. Supplier Management\n");
    printf("  4. Asset Management\n");
    printf("  5. Reports Module\n");
    printf("  6. Exit System\n");
    printf("===================================================\n");
}

void runMenuSystem(
    Employee employees[],
    int *numEmployees,
    Supplier suppliers[],
    int *numSuppliers,
    Asset assets[],
    int *numAssets
)
{
    int choice;

    do
    {
        displayMainMenu();
        choice = getValidInt("Enter choice (1-6): ", 1, 6);

        switch (choice)
        {
            case 1:
    employeeMenu(employees, numEmployees);
    break;

            case 2:
                printf("\n--- Budget Management ---\n");
                budgetMenu();
                break;

            case 3:
                printf("\n--- Supplier Management ---\n");
                supplierMenu(suppliers, numSuppliers);
                break;

            case 4:
                printf("\n--- Asset Management ---\n");
                assetMenu(assets, numAssets);
                break;

            case 5:
    printf("\n--- Reports Module ---\n");
    reportsMenu(
        employees,
        *numEmployees,
        suppliers,
        *numSuppliers,
        assets,
        *numAssets
    );
    break;

            case 6:
                printf("\nExiting Municipal Financial Management System. Goodbye!\n");
                break;
        }

    } while (choice != 6);
}