// Program		: letter.c
// Author		: Rey Rizki
// Description	: Letter ADT body implementation file
// Date			: Friday, 03 April 2020
// Version		: V 1.0
// Compiler		: gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04)

#include "letter.h"

Letter createLetter(char c)
{
    Letter letter;

    letter.letterType = c;
    letter.count = 0;
    letter.positions = createList();

    return letter;
}

LetterArr createLetterArr()
{
    LetterArr letterArr;

    letterArr.letter = NULL;
    letterArr.size = 0;

    return letterArr;
}

void printLetter(Letter letter)
{
    printf("letterType\t: %c\ncount\t\t: %u\npositions\t: ", letter.letterType, letter.count);
    printList(letter.positions);
}

void printLetterArr(LetterArr letterArr)
{
    u int i;
    REP(i, 0, letterArr.size)
    {
        printf("index\t\t: %u\n", i);
        printLetter(*(letterArr.letter + i));
        
        if (i < letterArr.size - 1)
            printf("\n");
    }
}

u int searchLetter(LetterArr letterArr, char target, u int pos)
{
    return (pos < letterArr.size) ? ((target == (letterArr.letter + pos)->letterType) ? pos : searchLetter(letterArr, target, pos + 1)) : -1;
}

void addExist(Letter *address, u int pos)
{
    address->count++;
    // printf("%p\n", address);
    insertAtTail(&(address->positions), pos);
}

void insertLetter(LetterArr *letterArr, char newLetter, u int pos)
{
    // printf("%p\n", letterArr);
    letterArr->letter = (letterArr->letter == NULL) ? (Letter *)malloc(1 * sizeof(Letter)) : (Letter *) realloc(letterArr->letter, (letterArr->size + 1) * sizeof(Letter));
    letterArr->size++;
    // printf("%p\n", letterArr->letter);
    // printf("%p\n", letterArr->letter + (letterArr->size - 1));
    
    *(letterArr->letter + letterArr->size - 1) = createLetter(newLetter);
    addExist(letterArr->letter + letterArr->size - 1, pos);
}