#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "square.h"

#define REP(i, a, b) for (i = (a); i < (b); i++)

void makeSquare(SQUARE *S, LINE s[])
{
    int i;
    REP(i, 0, 4)
        lineCopy(&S->s[i], s[i]);
}

SQUARE createSquare(LINE s[])
{
    SQUARE S;
    int i;

    REP(i, 0, 4)
        lineCopy(&S.s[i], s[i]);

    return S;
}

LINE getALine(SQUARE S, int index)
{
    return S.s[index];
}

void setALine(SQUARE *S, LINE L, int index)
{
    lineCopy(&S->s[index], L);
}

void readSquare(SQUARE *S)
{
    int i;
    LINE L;
    do
    {
        REP(i, 0, 4)
        {
            readLine(&L);
            setALine(S, L, i);
        }
    } while (!isSquare(*S));
}

void printSquare(SQUARE S)
{
    int i;
    REP(i, 0, 4)
        printLine(S.s[i]);
}

boolean isSquare(SQUARE S)
{
    int width = calculatePanjang(S.s[0]), i;

    REP(i, 1, 4)
        if (width != calculatePanjang(S.s[i]))
            return false;

    REP(i, 0, 3)
        return isLineConnected(S.s[i], S.s[i+1]);

    return isLineConnected(S.s[left], S.s[top]);
}

int squareArea(SQUARE S)
{
    return isSquare(S) ? pow(calculatePanjang(S.s[top]), 2) : -1;
}

int squareCircumference(SQUARE S)
{
    return isSquare(S) ? 4 * calculatePanjang(S.s[top]) : -1;
}