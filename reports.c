#include <stdio.h>
#include <string.h>
#include "reports.h"


void displaySupplierReport(Supplier suppliers[], int numSuppliers)
{
    int i;

    printf("\n==========================================");
    printf("\n         MUNICIPAL SUPPLIER REPORT        ");
    printf("\n==========================================");
    printf("\nTotal Suppliers Registered: %d\n", numSuppliers);
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