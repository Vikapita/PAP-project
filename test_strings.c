#include <stdio.h>
#include "string_utils.h"

int main()
{
    char name[50];
    char copy[50];
    char result[100];

    printf("Enter a name: ");
    fgets(name, sizeof(name), stdin);

    removeNewline(name);

    if (isEmptyString(name))
    {
        printf("Name cannot be empty.\n");
        return 0;
    }

    printf("You entered: %s\n", name);

    copyString(copy, name);
    printf("Copied name: %s\n", copy);

    joinStrings(result, "Hello ", name);
    printf("%s\n", result);

    if (stringsEqual(name, "Matilde"))
    {
        printf("The name matches Matilde.\n");
    }
    else
    {
        printf("The name does not match Matilde.\n");
    }

    return 0;
}