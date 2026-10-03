#ifndef STRING_UTILS_H
#define STRING_UTILS_H

void removeNewline(char text[]);
int isEmptyString(char text[]);
int stringsEqual(char first[], char second[]);
void copyString(char destination[], char source[]);
void joinStrings(char result[], char first[], char second[]);

#endif