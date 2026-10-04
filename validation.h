#ifndef VALIDATION_H
#define VALIDATION_H

// Clears leftover input from standard input buffer (e.g. after scanf)
void clearInputBuffer(void);

// Gets a validated integer input within a specified range [min, max]
int getValidInt(const char *prompt, int min, int max);

// Gets a validated floating-point input (greater than or equal to min)
float getValidFloat(const char *prompt, float min);

// Gets a validated double-precision input (greater than or equal to min)
double getValidDouble(const char *prompt, double min);

// Reads a non-empty string and strips trailing newline characters
void getValidString(const char *prompt, char *buffer, int size);

// Asks a Yes/No question and returns 1 for Yes, 0 for No
int getValidYesNo(const char *prompt);

#endif