#ifndef REPORTS_H
#define REPORTS_H

#include "employees.h"
#include "suppliers.h"
#include "assets.h"
#include "budget.h"

void displayEmployeeReport(Employee employees[], int numEmployees);
void displayBudgetReport(void);
void displaySupplierReport(Supplier suppliers[], int numSuppliers);
void displayAssetReport(Asset assets[], int numAssets);

void reportsMenu(
    Employee employees[],
    int numEmployees,
    Supplier suppliers[],
    int numSuppliers,
    Asset assets[],
    int numAssets
);

#endif