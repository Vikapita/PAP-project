#ifndef MENU_H
#define MENU_H

#include "employees.h"
#include "suppliers.h"
#include "assets.h"

void displayMainMenu(void);

void runMenuSystem(
    Employee employees[],
    int *numEmployees,
    Supplier suppliers[],
    int *numSuppliers,
    Asset assets[],
    int *numAssets
);

#endif