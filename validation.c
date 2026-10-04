#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validation.h"

void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int getValidInt(const char *prompt, int min, int max) {
    int value;
    int result;
    while (1) {
        printf("%s", prompt);
        result = scanf("%d", &value);
        if (result == 1 && value >= min && value <= max) {
            clearInputBuffer();
            return value;
        }
        printf("Error: Invalid entry. Please enter an integer between %d and %d.\n", min, max);
        clearInputBuffer();
    }
}

float getValidFloat(const char *prompt, float min) {
    float value;
    int result;
    while (1) {
        printf("%s", prompt);
        result = scanf("%f", &value);
        if (result == 1 && value >= min) {
            clearInputBuffer();
            return value;
        }
        printf("Error: Invalid entry. Value must be a number >= %.2f.\n", min);
        clearInputBuffer();
    }
}

double getValidDouble(const char *prompt, double min) {
    double value;
    int result;
    while (1) {
        printf("%s", prompt);
        result = scanf("%lf", &value);
        if (result == 1 && value >= min) {
            clearInputBuffer();
            return value;
        }
        printf("Error: Invalid entry. Value must be a number >= %.2lf.\n", min);
        clearInputBuffer();
    }
}

void getValidString(const char *prompt, char *buffer, int size) {
    while (1) {
        printf("%s", prompt);
        if (fgets(buffer, size, stdin) != NULL) {
            // Remove newline character if present
            buffer[strcspn(buffer, "\n")] = '\0';
            
            if (strlen(buffer) > 0) {
                return;
            }
        }
        printf("Error: Input cannot be empty. Please try again.\n");
    }
}

int getValidYesNo(const char *prompt) {
    char response[10];
    while (1) {
        printf("%s (1=Yes, 0=No): ", prompt);
        if (fgets(response, sizeof(response), stdin) != NULL) {
            if (response[0] == '1') return 1;
            if (response[0] == '0') return 0;
        }
        printf("Error: Invalid input. Enter 1 for Yes or 0 for No.\n");
    }
}