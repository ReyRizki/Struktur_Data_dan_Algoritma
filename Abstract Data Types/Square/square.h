#ifndef SQUARE_H_
#define SQUARE_H_

#include "line.h"

enum direction{top, right, bottom, left};

typedef struct
{
    LINE s[4];
} SQUARE;

void makeSquare(SQUARE *S, LINE s[]);
SQUARE createSquare(LINE s[]);

LINE getALine(SQUARE S, int index);

void setALine(SQUARE *S, LINE L, int index);

void readSquare(SQUARE *S);
void printSquare(SQUARE S);

boolean isSquare(SQUARE S);

int squareArea(SQUARE S);
int squareCircumference(SQUARE S);
#endif