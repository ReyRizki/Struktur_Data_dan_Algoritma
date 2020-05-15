// Program		: letter.h
// Author		: Rey Rizki
// Description	: Letter ADT header file
// Date			: Friday, 03 April 2020
// Version		: V 1.0
// Compiler		: gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04)

#ifndef LETTER_H_
#define LETTER_H_

#include "linkedList.h"

typedef struct 
{
    char letterType;
    u int count;
    List positions;
} Letter;

typedef struct
{
    Letter *letter;
    u int size;
} LetterArr;

// CONSTRUCTOR

// Description		: Function to create a Letter struct
// Input			: A char to be inserted to letterType
// Output			: Letter struct
Letter createLetter(char c);

// Description		: Function to create a LetterArr struct
// Input			: -
// Output			: LetterArr struct
LetterArr createLetterArr();

// ACCESSOR

// Description		: Procedure to print a Letter struct
// Initial State	: Letter is not printed yet
// Final State		: Letter is printed
void printLetter(Letter letter);

// Description		: Procedure to print a LetterArr
// Initial State	: LetterArr is not printed yet
// Final State		: LetterArr is printed
void printLetterArr(LetterArr letterArr);

// Description		: Recursive function to search a letter in a LetterArr
// Input			: LetterArr, char to be searched, pos = 0
// Output			: Position of the target (-1 if not found)
u int searchLetter(LetterArr letterArr, char target, u int pos);

// MUTATOR

// Description		: Procedure to update count and position of a Letter in LetterArr
// Initial State	: Letter is not updated yet
// Final State		: Letter is updated
void addExist(Letter *address, u int pos);

// Description		: Procedure to insert a new Letter in LetterArr
// Initial State	: New Letter is not inserted yet
// Final State		: New Letter is inserted
void insertLetter(LetterArr *letterArr, char newLetter, u int pos);

#endif