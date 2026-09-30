#include <stdio.h>
#include <string.h>
#include "suppliers.h"

static void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        
    }
}


void addSupplier(Supplier suppliers[], int *numSuppliers)
{
    Supplier *supplier;

    if (*numSuppliers >= MAX_SUPPLIERS)
    {
        printf("\nSupplier limit reached.\n");
        return;
    }

    supplier = &suppliers[*numSuppliers];

    printf("\n========== ADD SUPPLIER ===========\n");

    
    do
    {
        printf("Enter Supplier ID: ");
        if (scanf("%d", &supplier->supplierID) != 1)
        {
            supplier->supplierID = 0;
        }
        clearInputBuffer();

        if (supplier->supplierID <= 0)
        {
            printf("Supplier ID must be greater than 0.\n");
        }
    } while (supplier->supplierID <= 0);

    
    do
    {
        printf("Enter Supplier Name: ");
        fgets(supplier->name, sizeof(supplier->name), stdin);
        supplier->name[strcspn(supplier->name, "\n")] = '\0';

        if (strlen(supplier->name) == 0)
        {
            printf("Supplier name cannot be empty.\n");
        }
    } while (strlen(supplier->name) == 0);

    
    do
    {
        printf("Enter Supplier Email: ");
        fgets(supplier->email, sizeof(supplier->email), stdin);
        supplier->email[strcspn(supplier->email, "\n")] = '\0';

        if (strlen(supplier->email) == 0)
        {
            printf("Email cannot be empty.\n");
        }
    } while (strlen(supplier->email) == 0);

    
    do
    {
        printf("Enter Telephone Number: ");
        fgets(supplier->phone, sizeof(supplier->phone), stdin);
        supplier->phone[strcspn(supplier->phone, "\n")] = '\0';

        if (strlen(supplier->phone) == 0)
        {
            printf("Telephone number cannot be empty.\n");
        }
    } while (strlen(supplier->phone) == 0);

    
    do
    {
        printf("Enter Town/Location: ");
        fgets(supplier->location, sizeof(supplier->location), stdin);
        supplier->location[strcspn(supplier->location, "\n")] = '\0';

        if (strlen(supplier->location) == 0)
        {
            printf("Town/Location cannot be empty.\n");
        }
    } while (strlen(supplier->location) == 0);

    (*numSuppliers)++;
    printf("\nSupplier added successfully!\n");
}


void displaySuppliers(Supplier suppliers[], int numSuppliers)
{
    int i;

    if (numSuppliers == 0)
    {
        printf("\nNo suppliers registered.\n");
        return;
    }

    printf("\n========== SUPPLIER LIST ===========\n");
    for (i = 0; i < numSuppliers; i++)
    {
        printf("\nSupplier %d:\n", i + 1);
        printf("------------------------------------\n");
        printf("Supplier ID: %d\n", suppliers[i].supplierID);
        printf("Name: %s\n", suppliers[i].name);
        printf("Email: %s\n", suppliers[i].email);
        printf("Telephone: %s\n", suppliers[i].phone);
        printf("Location: %s\n", suppliers[i].location);
    }
}


void searchSupplier(Supplier suppliers[], int numSuppliers, int supplierID)
{
    int i;
    int found = 0;

    for (i = 0; i < numSuppliers; i++)
    {
        if (suppliers[i].supplierID == supplierID)
        {
            printf("\n========== SUPPLIER FOUND ===========\n");
            printf("Supplier ID: %d\n", suppliers[i].supplierID);
            printf("Name: %s\n", suppliers[i].name);
            printf("Email: %s\n", suppliers[i].email);
            printf("Telephone: %s\n", suppliers[i].phone);
            printf("Location: %s\n", suppliers[i].location);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nSupplier with ID %d not found.\n", supplierID);
    }
}


void compareSuppliersByLocation(Supplier suppliers[], int numSuppliers, const char *location)
{
    int i;
    int count = 0;

    printf("\n=== SUPPLIERS IN LOCATION: %s ===\n", location);

    for (i = 0; i < numSuppliers; i++)
    {
        if (strcmp(suppliers[i].location, location) == 0)
        {
            printf("\nSupplier ID: %d\n", suppliers[i].supplierID);
            printf("Name: %s\n", suppliers[i].name);
            printf("Email: %s\n", suppliers[i].email);
            printf("Telephone: %s\n", suppliers[i].phone);
            count++;
        }
    }

    if (count == 0)
    {
        printf("No suppliers found in location: %s\n", location);
    }
}


void supplierMenu(Supplier suppliers[], int *numSuppliers)
{
    int choice;
    int searchID;
    char searchLocation[50];

    do
    {
        printf("\n====================================\n");
        printf("       SUPPLIER MANAGEMENT          \n");
        printf("====================================\n");
        printf("1. Add Supplier\n");
        printf("2. Display All Suppliers\n");
        printf("3. Search Supplier by ID\n");
        printf("4. Filter Suppliers by Location\n");
        printf("5. Return to Main Menu\n");
        printf("====================================\n");

        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1)
        {
            choice = 0;
        }
        clearInputBuffer();

        switch (choice)
        {
            case 1:
                addSupplier(suppliers, numSuppliers);
                break;

            case 2:
                displaySuppliers(suppliers, *numSuppliers);
                break;

            case 3:
                if (*numSuppliers == 0)
                {
                    printf("\nNo suppliers registered.\n");
                }
                else
                {
                    printf("\nEnter Supplier ID to search: ");
                    scanf("%d", &searchID);
                    clearInputBuffer();
                    searchSupplier(suppliers, *numSuppliers, searchID);
                }
                break;

            case 4:
                if (*numSuppliers == 0)
                {
                    printf("\nNo suppliers registered.\n");
                }
                else
                {
                    printf("\nEnter Town/Location to search: ");
                    fgets(searchLocation, sizeof(searchLocation), stdin);
                    searchLocation[strcspn(searchLocation, "\n")] = '\0';
                    compareSuppliersByLocation(suppliers, *numSuppliers, searchLocation);
                }
                break;

            case 5:
                printf("\nReturning to Main Menu...\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 5);
}