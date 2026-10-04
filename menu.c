#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "validation.h"

void displayMainMenu(void) {
    printf("\n");
    printf("===================================================\n");
    printf("       MUNICIPAL FINANCIAL MANAGEMENT SYSTEM       \n");
    printf("===================================================\n");
    printf("  1. Employee Management\n");
    printf("  2. Budget Management\n");
    printf("  3. Supplier Management\n");
    printf("  4. Asset Management\n");
    printf("  5. Reports Module\n");
    printf("  6. Technical Utility / String Tools\n");
    printf("  7. Exit System\n");
    printf("===================================================\n");
}

void runMenuSystem(void) {
    int choice = 0;

    do {
        displayMainMenu();
        choice = getValidInt("Enter choice (1-7): ", 1, 7);

        switch (choice) {
            case 1:
                printf("\n--- Routing to Employee Management ---\n");
                // TODO: Call Lead 1 function: employeeMenu();
                break;
            case 2:
                printf("\n--- Routing to Budget Management ---\n");
                // TODO: Call Lead 2 function: budgetMenu();
                break;
            case 3:
                printf("\n--- Routing to Supplier Management ---\n");
                // TODO: Call Lead 3 function: supplierMenu();
                break;
            case 4:
                printf("\n--- Routing to Asset Management ---\n");
                // TODO: Call Lead 4 function: assetMenu();
                break;
            case 5:
                printf("\n--- Routing to Reports Module ---\n");
                // TODO: Call Lead 3/4 function: reportsMenu();
                break;
            case 6:
                printf("\n--- Routing to Technical Utility Tools ---\n");
                // TODO: Call Lead 6 function: stringUtilsMenu();
                break;
            case 7:
                printf("\nExiting Municipal Financial Management System. Goodbye!\n");
                break;
            default:
                printf("Error: Unhandled menu option.\n");
                break;
        }
    } while (choice != 7);
}