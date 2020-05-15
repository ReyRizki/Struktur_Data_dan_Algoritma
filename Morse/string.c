// Program		: string.c
// Author		: Rey Rizki
// Description	: String ADT body implementation file
// Date			: Thursday, 30 April 2020
// Version		: V 1.0
// Compiler		: gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04)

#include "string.h"

#ifndef MACROS
#define MACROS

#define u unsigned
#define s short
#define ll long long
#define REP(i, a, b) for (i = (a); i < (b); i++)
#define REPR(i, a, b) for (i = (a-1); i >= (b); i--)

#endif

// ============= 
//  CONSTRUCTOR
// =============

// Description		: Function to create a string
// Input			: -
// Output			: An empty string
String createString()
{
    String string;

    string.arr = (char *) malloc(1 * sizeof(char));
    string.size = 0;
    string.capacity = 1;

    return string;
}

// ==========
//  MUTATORS 
// ==========

// Description		: Procedure to append a string to an existing string
// Initial State	: New string is not appended yet
// Final State		: New string is appended
void insertChar(String *string, char newChar)
{
    if (string->size == string->capacity)
    {
        string->capacity *= 2;
        string->arr = (char *) realloc(string->arr, string->capacity * sizeof(char));
    }

    *(string->arr + string->size++) = newChar;
    *(string->arr + string->size + 1) = '\0';
}

// Description		: Procedure to append a string to an existing string
// Initial State	: New string is not inserted yet
// Final State		: New string is inserted
void appendString(String *string, char *newString)
{
    int len = strlen(newString);
    
    REP(i, 0, len)
        insertChar(string, *(newString + i));
}

// Description		: Procdure to concatenate a string to another string
// Initial State	: String is not concatenated yet
// Final State		: String is concatenated
void concatenateString(String *target, String source)
{
    REP(i, 0, source.size)
        insertChar(target, *(source.arr + i));
}

// ==========
//  ACCESSOR
// ==========

// Description		: Procedure to print a string
// Initial State	: String is not printed yet
// Final State		: String is printed
void printString(String string)
{
    // REP(i, 0, string.size)
    //     printf("%c", *(string.arr + i));
    // printf("\n");
    printf("%s\n", string.arr);
}

// ============
//  DESTRUCTOR
// ============

// Description		: Procedure to delete a string
// Initial State	: String is still exist
// Final State		: String is deleted
void deleteString(String *string)
{
    free(string->arr);
    string->arr = NULL;
    string->size = 0;
    string->capacity = 1;
}
