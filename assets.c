#include <stdio.h>
#include <string.h>
#include "assets.h"

static void clearInputBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        /* clear input */
    }
}

/* Check whether an asset ID already exists in the register */
static int assetIDExists(Asset assets[], int numAssets, int assetID)
{
    int i;

    for (i = 0; i < numAssets; i++)
    {
        if (assets[i].assetID == assetID)
        {
            return 1;
        }
    }

    return 0;
}

/* Add a new asset */
void addAsset(Asset assets[], int *numAssets)
{
    Asset *asset;
    int duplicateID;

    if (*numAssets >= MAX_ASSETS)
    {
        printf("\nAsset limit reached. Cannot add more assets.\n");
        return;
    }

    asset = &assets[*numAssets];

    printf("\n========== ADD ASSET ===========\n");

    /* Asset ID - must be > 0 and unique */
    do
    {
        printf("Enter Asset ID: ");
        if (scanf("%d", &asset->assetID) != 1)
        {
            asset->assetID = 0;
        }
        clearInputBuffer();

        if (asset->assetID <= 0)
        {
            printf("Asset ID must be greater than 0.\n");
            duplicateID = 0;
        }
        else if (assetIDExists(assets, *numAssets, asset->assetID))
        {
            printf("Asset ID %d already exists. Please enter a unique ID.\n",
                   asset->assetID);
            duplicateID = 1;
        }
        else
        {
            duplicateID = 0;
        }
    } while (asset->assetID <= 0 || duplicateID);

    /* Asset name */
    do
    {
        printf("Enter Asset Name: ");
        fgets(asset->name, sizeof(asset->name), stdin);
        asset->name[strcspn(asset->name, "\n")] = '\0';

        if (strlen(asset->name) == 0)
        {
            printf("Asset name cannot be empty.\n");
        }
    } while (strlen(asset->name) == 0);

    /* Asset type */
    do
    {
        printf("Enter Asset Type (Vehicle/Computer/Building/Equipment/Office Furniture): ");
        fgets(asset->type, sizeof(asset->type), stdin);
        asset->type[strcspn(asset->type, "\n")] = '\0';

        if (strlen(asset->type) == 0)
        {
            printf("Asset type cannot be empty.\n");
        }
    } while (strlen(asset->type) == 0);

    /* Purchase value */
    do
    {
        printf("Enter Purchase Value: N$ ");
        if (scanf("%f", &asset->purchaseValue) != 1)
        {
            asset->purchaseValue = -1;
        }
        clearInputBuffer();

        if (asset->purchaseValue < 0)
        {
            printf("Purchase value cannot be negative.\n");
        }
    } while (asset->purchaseValue < 0);

    /* Department */
    do
    {
        printf("Enter Department: ");
        fgets(asset->department, sizeof(asset->department), stdin);
        asset->department[strcspn(asset->department, "\n")] = '\0';

        if (strlen(asset->department) == 0)
        {
            printf("Department cannot be empty.\n");
        }
    } while (strlen(asset->department) == 0);

    /* Condition - restricted to valid values */
    do
    {
        printf("Enter Condition (New/Good/Fair/Poor): ");
        fgets(asset->condition, sizeof(asset->condition), stdin);
        asset->condition[strcspn(asset->condition, "\n")] = '\0';

        if (strcmp(asset->condition, "New") != 0 &&
            strcmp(asset->condition, "Good") != 0 &&
            strcmp(asset->condition, "Fair") != 0 &&
            strcmp(asset->condition, "Poor") != 0)
        {
            printf("Invalid condition. Please enter New, Good, Fair, or Poor.\n");
        }
    } while (strcmp(asset->condition, "New") != 0 &&
             strcmp(asset->condition, "Good") != 0 &&
             strcmp(asset->condition, "Fair") != 0 &&
             strcmp(asset->condition, "Poor") != 0);

    (*numAssets)++;
    printf("\nAsset added successfully!\n");
}

/* Display all assets in the register */
void displayAssets(Asset assets[], int numAssets)
{
    int i;

    if (numAssets == 0)
    {
        printf("\nNo assets registered.\n");
        return;
    }

    printf("\n========== ASSET REGISTER ===========\n");

    for (i = 0; i < numAssets; i++)
    {
        printf("\nAsset %d:\n", i + 1);
        printf("------------------------------------\n");
        printf("Asset ID: %d\n", assets[i].assetID);
        printf("Name: %s\n", assets[i].name);
        printf("Type: %s\n", assets[i].type);
        printf("Purchase Value: N$ %.2f\n", assets[i].purchaseValue);
        printf("Department: %s\n", assets[i].department);
        printf("Condition: %s\n", assets[i].condition);
    }
}

/* Search for an asset by ID */
void searchAsset(Asset assets[], int numAssets, int assetID)
{
    int i;
    int found = 0;

    for (i = 0; i < numAssets; i++)
    {
        if (assets[i].assetID == assetID)
        {
            printf("\n========== ASSET FOUND ===========\n");
            printf("Asset ID: %d\n", assets[i].assetID);
            printf("Name: %s\n", assets[i].name);
            printf("Type: %s\n", assets[i].type);
            printf("Purchase Value: N$ %.2f\n", assets[i].purchaseValue);
            printf("Department: %s\n", assets[i].department);
            printf("Condition: %s\n", assets[i].condition);

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nAsset with ID %d not found.\n", assetID);
    }
}

/* Display all assets belonging to a specific department */
void displayAssetsByDepartment(Asset assets[], int numAssets, const char *department)
{
    int i;
    int count = 0;

    printf("\n=== ASSETS IN DEPARTMENT: %s ===\n", department);

    for (i = 0; i < numAssets; i++)
    {
        if (strcmp(assets[i].department, department) == 0)
        {
            printf("\nAsset ID: %d\n", assets[i].assetID);
            printf("Name: %s\n", assets[i].name);
            printf("Type: %s\n", assets[i].type);
            printf("Purchase Value: N$ %.2f\n", assets[i].purchaseValue);
            printf("Condition: %s\n", assets[i].condition);
            count++;
        }
    }

    if (count == 0)
    {
        printf("No assets found in department: %s\n", department);
    }
}

/* Calculate total value of all registered assets */
float calculateTotalAssetValue(Asset assets[], int numAssets)
{
    int i;
    float total = 0.0;

    for (i = 0; i < numAssets; i++)
    {
        total += assets[i].purchaseValue;
    }

    return total;
}

/* Asset management sub-menu */
void assetMenu(Asset assets[], int *numAssets)
{
    int choice;
    int searchID;
    char searchDepartment[50];

    do
    {
        printf("\n====================================\n");
        printf("         ASSET MANAGEMENT           \n");
        printf("====================================\n");
        printf("1. Add Asset\n");
        printf("2. Display All Assets\n");
        printf("3. Search Asset by ID\n");
        printf("4. Filter Assets by Department\n");
        printf("5. Show Total Asset Value\n");
        printf("6. Return to Main Menu\n");
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
                addAsset(assets, numAssets);
                break;

            case 2:
                displayAssets(assets, *numAssets);
                break;

            case 3:
                if (*numAssets == 0)
                {
                    printf("\nNo assets registered.\n");
                }
                else
                {
                    printf("\nEnter Asset ID to search: ");
                    scanf("%d", &searchID);
                    clearInputBuffer();
                    searchAsset(assets, *numAssets, searchID);
                }
                break;

            case 4:
                if (*numAssets == 0)
                {
                    printf("\nNo assets registered.\n");
                }
                else
                {
                    printf("\nEnter Department to search: ");
                    fgets(searchDepartment, sizeof(searchDepartment), stdin);
                    searchDepartment[strcspn(searchDepartment, "\n")] = '\0';
                    displayAssetsByDepartment(assets, *numAssets, searchDepartment);
                }
                break;

            case 5:
                if (*numAssets == 0)
                {
                    printf("\nNo assets registered.\n");
                }
                else
                {
                    printf("\nTotal Asset Value: N$ %.2f\n",
                           calculateTotalAssetValue(assets, *numAssets));
                }
                break;

            case 6:
                printf("\nReturning to Main Menu...\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 6);
}