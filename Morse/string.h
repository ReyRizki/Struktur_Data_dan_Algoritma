// Program		: string.h
// Author		: Rey Rizki
// Description	: String ADT header file
// Date			: Thursday, 30 April 2020
// Version		: V 1.0
// Compiler		: gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04)

#ifndef STRING_H_
#define STRING_H_ 

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef MACROS
#define MACROS

#define u unsigned
#define s short
#define ll long long
#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define REPR(i, a, b) for (int i = (a-1); i >= (b); i--)

#endif

typedef struct
{
    char *arr;
    u int size, capacity;
} String;

// ============= 
//  CONSTRUCTOR
// =============

// Description		: Function to create a string
// Input			: -
// Output			: An empty string
String createString();

// ==========
//  MUTATORS 
// ==========

// Description		: Procedure to insert a char to an existing string
// Initial State	: New char is not inserted yet
// Final State		: New char is inserted
void insertChar(String *string, char newChar);

// Description		: Procedure to append a string to an existing string
// Initial State	: New string is not inserted yet
// Final State		: New string is inserted
void appendString(String *string, char *newString);

// Description		: Procdure to concatenate a string to another string
// Initial State	: String is not concatenated yet
// Final State		: String is concatenated
void concatenateString(String *target, String source);

// ==========
//  ACCESSOR
// ==========

// Description		: Procedure to print a string
// Initial State	: String is not printed yet
// Final State		: String is printed
void printString(String string);

// ============
//  DESTRUCTOR
// ============

// Description		: Procedure to delete a string
// Initial State	: String is still exist
// Final State		: String is deleted
void deleteString(String *string);

#endif