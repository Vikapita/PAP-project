#ifndef BUDGET_H
#define BUDGET_H

#define MAX_DEPARTMENTS 20

typedef struct
{
    char department[50];
    float allocatedBudget;
    float expenditure;
    float remainingBudget;
} Budget;


void budgetMenu();
void addBudget();
void displayBudgets();
void calculateRemainingBudget();
void displayExceededBudgets();

#endif