// Program		: main.c
// Author		: Rey Rizki
// Description	: Main diver to test Matrix ADT
// Date			: Friday, 17 April 2020
// Version		: V 1.0
// Compiler		: gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04)

#include "matrix.h"

int main()
{
    Matrix matrix = createMatrix();

    insertTopRow(&matrix);
    insertTopRow(&matrix);
    insertLeftColumn(&matrix);
    insertLeftColumn(&matrix);
    insertLeftColumn(&matrix);
    insertRightColumn(&matrix);
    insertRightColumn(&matrix);
    insertBottomRow(&matrix);

    assignNode(&matrix, 1, 2, CreatePoint(14, 6));
    PrintPoint(dataAt(matrix, 1, 2));
    printf("\n");

    assignNode(&matrix, 2, 3, CreatePoint(2, 15));
    printMatrix(matrix);

    printf(isMatrixEmpty(matrix) ? "Yes" : "No");
    printf("\n");

    printf("%u x %u\n", rowCount(matrix), columnCount(matrix));
    
    return 0;
}