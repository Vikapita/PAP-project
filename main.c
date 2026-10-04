#include <stdio.h>
#include "menu.h"
#include "employees.h"
#include "suppliers.h"
#include "assets.h"

int main(void)
{
    Employee employees[MAX_EMPLOYEES];
    int numEmployees = 0;

    Supplier suppliers[MAX_SUPPLIERS];
    int numSuppliers = 0;

    Asset assets[MAX_ASSETS];
    int numAssets = 0;

    runMenuSystem(
        employees,
        &numEmployees,
        suppliers,
        &numSuppliers,
        assets,
        &numAssets
    );

    return 0;
}