#include <stdio.h>
#include <string.h>
#include "string_utils.h"

void removeNewline(char text[])
{
    int length = strlen(text);

    if (length > 0 && text[length - 1] == '\n')
    {
        text[length - 1] = '\0';
    }
}

int isEmptyString(char text[])
{
    if (strlen(text) == 0)
    {
        return 1;
    }

    return 0;
}

int stringsEqual(char first[], char second[])
{
    if (strcmp(first, second) == 0)
    {
        return 1;
    }

    return 0;
}

void copyString(char destination[], char source[])
{
    strcpy(destination, source);
}

void joinStrings(char result[], char first[], char second[])
{
    strcpy(result, first);
    strcat(result, second);
}