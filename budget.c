#include <stdio.h>
#include <string.h>
#include "budget.h"

Budget budgets[MAX_DEPARTMENTS];
int budgetCount = 0;

void addBudget()
{
    if (budgetCount >= MAX_DEPARTMENTS)
    {
        printf("\nMaximum number of departments reached.\n");
        return;
    }

    printf("\nEnter department name: ");
    scanf(" %[^\n]", budgets[budgetCount].department);

    printf("Enter allocated budget: N$");
    scanf("%f", &budgets[budgetCount].allocatedBudget);

    while (budgets[budgetCount].allocatedBudget < 0)
    {
        printf("Budget cannot be negative.\n");
        printf("Enter allocated budget again: N$");
        scanf("%f", &budgets[budgetCount].allocatedBudget);
    }

    printf("Enter expenditure: N$");
    scanf("%f", &budgets[budgetCount].expenditure);

    while (budgets[budgetCount].expenditure < 0)
    {
        printf("Expenditure cannot be negative.\n");
        printf("Enter expenditure again: N$");
        scanf("%f", &budgets[budgetCount].expenditure);
    }

    budgets[budgetCount].remainingBudget =
        budgets[budgetCount].allocatedBudget -
        budgets[budgetCount].expenditure;

    budgetCount++;

    printf("\nBudget added successfully!\n");
}

void displayBudgets()
{
    int i;

    if (budgetCount == 0)
    {
        printf("\nNo budget information available.\n");
        return;
    }

    printf("\n========== BUDGET INFORMATION ==========\n");

    for (i = 0; i < budgetCount; i++)
    {
        printf("\nDepartment: %s\n",
               budgets[i].department);

        printf("Allocated Budget: N$%.2f\n",
               budgets[i].allocatedBudget);

        printf("Expenditure: N$%.2f\n",
               budgets[i].expenditure);

        printf("Remaining Budget: N$%.2f\n",
               budgets[i].remainingBudget);

        if (budgets[i].expenditure <= budgets[i].allocatedBudget)
        {
            printf("Status: WITHIN BUDGET\n");
        }
        else
        {
            printf("Status: OVER BUDGET\n");
        }
    }
}

void calculateRemainingBudget()
{
    int i;

    if (budgetCount == 0)
    {
        printf("\nNo budget information available.\n");
        return;
    }

    for (i = 0; i < budgetCount; i++)
    {
        budgets[i].remainingBudget =
            budgets[i].allocatedBudget -
            budgets[i].expenditure;
    }

    printf("\nRemaining budgets calculated successfully.\n");
}

void displayExceededBudgets()
{
    int i;
    int found = 0;

    printf("\n====== DEPARTMENTS OVER BUDGET ======\n");

    for (i = 0; i < budgetCount; i++)
    {
        if (budgets[i].expenditure > budgets[i].allocatedBudget)
        {
            printf("\nDepartment: %s\n",
                   budgets[i].department);

            printf("Allocated Budget: N$%.2f\n",
                   budgets[i].allocatedBudget);

            printf("Expenditure: N$%.2f\n",
                   budgets[i].expenditure);

            printf("Amount Over Budget: N$%.2f\n",
                   budgets[i].expenditure -
                   budgets[i].allocatedBudget);

            found = 1;
        }
    }

    if (found == 0)
    {
        printf("\nNo departments have exceeded their budgets.\n");
    }
}

void budgetMenu()
{
    int choice;

    do
    {
        printf("\n====================================\n");
        printf("       BUDGET MANAGEMENT\n");
        printf("====================================\n");
        printf("1. Add Department Budget\n");
        printf("2. Display Budget Information\n");
        printf("3. Calculate Remaining Budget\n");
        printf("4. Display Departments Over Budget\n");
        printf("5. Return to Main Menu\n");
        printf("====================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addBudget();
                break;

            case 2:
                displayBudgets();
                break;

            case 3:
                calculateRemainingBudget();
                break;

            case 4:
                displayExceededBudgets();
                break;

            case 5:
                printf("\nReturning to Main Menu...\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 5);
}