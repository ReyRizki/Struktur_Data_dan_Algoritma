// Program		: matrix.h
// Author		: Rey Rizki
// Description	: Matrix ADT header file
// Date			: Friday, 17 April 2020
// Version		: V 1.0 (Point as data type)
// Compiler		: gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04)

#ifndef MATRIX_H_
#define MATRIX_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iso646.h>
#include "point.h"

#define u unsigned
#define s short
#define ll long long
#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define REPR(i, a, b) for (int i = (a-1); i >= (b); i--)

enum directions {left, right, up, down};

typedef POINT dataType;
typedef struct Node *address;

typedef struct Node
{
    dataType data;
    address direction[4];
} Node;

typedef struct
{
    address topLeft;
} Matrix;

Matrix createMatrix();
Node *createNode();

bool isMatrixEmpty(Matrix matrix);

void insertLeftColumn(Matrix *matrix);
void insertRightColumn(Matrix *matrix);
void insertTopRow(Matrix *matrix);
void insertBottomRow(Matrix *matrix);

u int columnCount(Matrix matrix);
u int rowCount(Matrix matrix);

address topRightAddress(Matrix matrix);
address bottomLeftAddress(Matrix matrix);
address addressAt(Matrix matrix, u int row, u int column);

dataType dataAt(Matrix matrix, u int row, u int column);
void assignNode(Matrix *matrix, u int row, u int column, dataType data);

void printMatrix(Matrix matrix);
#endif