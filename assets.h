#ifndef ASSETS_H
#define ASSETS_H

#define MAX_ASSETS 100

typedef struct
{
    int assetID;
    char name[100];
    char type[50];
    float purchaseValue;
    char department[50];
    char condition[30];
} Asset;

void addAsset(Asset assets[], int *numAssets);
void displayAssets(Asset assets[], int numAssets);
void searchAsset(Asset assets[], int numAssets, int assetID);
void displayAssetsByDepartment(Asset assets[], int numAssets, const char *department);
float calculateTotalAssetValue(Asset assets[], int numAssets);
void assetMenu(Asset assets[], int *numAssets);

#endif