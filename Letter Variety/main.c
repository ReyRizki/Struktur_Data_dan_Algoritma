// Program		: main.c
// Author		: Rey Rizki
// Description	: Program to count the variety of letters in a file
// Date			: Friday, 03 April 2020
// Version		: V 1.0
// Compiler		: gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04)

#include "letter.h"
#include <string.h>
#include <ctype.h>

// Description		: Function to check if a character is a letter or not
// Input			: A character
// Output			: True if the character is a letter
bool isLetter(char c);

// Description		: Procedure to generate the variety of a letter
// Initial State	: The variety is not generated yet
// Final State		: The variety is generated
void varietyCount(LetterArr *letterArr, char c, u int currentPos);

int main()
{
    LetterArr letterArr = createLetterArr();
    FILE *fileSource = fopen("text.txt", "r"), *fileTarget = fopen("result.dat", "w");
    char ch;
    u int currentPos = 0, i;

    if (fileSource == NULL)
        printf("Can't open the file\n");
    else
    {
        while ((ch = fgetc(fileSource)) != EOF)
        {
            varietyCount(&letterArr, tolower(ch), currentPos);
            currentPos++;
        }
    }

    printLetterArr(letterArr);

    fwrite(letterArr.letter, 1, sizeof(letterArr.letter), fileTarget);

    fclose(fileSource);
    fclose(fileTarget);

    return 0;
}

bool isLetter(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

void varietyCount(LetterArr *letterArr, char c, u int currentPos)
{
    // printf("%p\n", letterArr);
    u int arrPos = searchLetter(*letterArr, c, 0);
    if (isLetter(c))
    {
        if (arrPos != -1)
        {
            addExist(letterArr->letter + arrPos, currentPos);
        }
        else
        {
            insertLetter(letterArr, c, currentPos);
        }
    }
}