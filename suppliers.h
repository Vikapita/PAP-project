#ifndef SUPPLIERS_H
#define SUPPLIERS_H

#define MAX_SUPPLIERS 100

typedef struct
{
    int supplierID;
    char name[100];
    char email[100];
    char phone[20];
    char location[50];
} Supplier;

void addSupplier(Supplier suppliers[], int *numSuppliers);
void displaySuppliers(Supplier suppliers[], int numSuppliers);
void searchSupplier(Supplier suppliers[], int numSuppliers, int supplierID);
void compareSuppliersByLocation(Supplier suppliers[], int numSuppliers, const char *location);
void supplierMenu(Supplier suppliers[], int *numSuppliers);

#endif