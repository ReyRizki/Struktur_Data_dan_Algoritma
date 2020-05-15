#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "line.h"
#include "boolean.h"

void CreateLine(LINE *L, POINT P1, POINT P2)
{
    L->startPoint = P1;
    L->endPoint = P2;
}

POINT getStartPoint(LINE L)
{
    return L.startPoint;
}

POINT getEndPoint(LINE L)
{
    return L.endPoint;
}

void setStartPoint(LINE *L, POINT newStartPoint)
{
    L->startPoint = newStartPoint;
}

void setEndPoint(LINE *L, POINT newEndPoint)
{
    L->endPoint = newEndPoint;
}

void readLine(LINE *L)
{
    POINT P1, P2;
    scanf("%d %d %d %d", &P1.x, &P1.y, &P2.x, &P2.y);
    CreateLine(&(*L), P1, P2);
}

void printLine(LINE L)
{
    printf("((%d, %d), (%d, %d))\n", L.startPoint.x, L.startPoint.y, L.endPoint.x, L.endPoint.y);
}

boolean EQ(LINE L1, LINE L2)
{
    return PointEQ(L1.startPoint, L2.startPoint) && PointEQ(L1.endPoint, L2.endPoint);
}

boolean NEQ(LINE L1, LINE L2)
{
    return !EQ(L1, L2);
}

boolean isOnSbX(LINE L)
{
    return IsOnSumbuX(L.startPoint) && IsOnSumbuX(L.endPoint);
}

boolean isOnSbY(LINE L)
{
    return IsOnSumbuY(L.startPoint) && IsOnSumbuY(L.endPoint);
}

int getKuadran(LINE L)
{
    return Kuadran(L.startPoint) == Kuadran(L.endPoint) ? Kuadran(L.startPoint) : -1;
}

boolean isTegakLurus(LINE L1, LINE L2)
{
    float m1, m2;

    m1 = (float) (L1.endPoint.y - L1.startPoint.y) / (L1.endPoint.x - L1.startPoint.x);
    m2 = (float) (L2.endPoint.y - L2.startPoint.y) / (L2.endPoint.x - L2.startPoint.x);

    return m1 * m2 == -1;
}

boolean isSejajar(LINE L1, LINE L2)
{
    float m1, m2;

    m1 = (float) (L1.endPoint.y - L1.startPoint.y) / (L1.endPoint.x - L1.startPoint.x);
    m2 = (float) (L2.endPoint.y - L2.startPoint.y) / (L2.endPoint.x - L2.startPoint.x);

    return m1 == m2;
}

void moveLine(LINE *L, int deltaX, int deltaY)
{
    CreateLine(L, CreatePoint((*L).startPoint.x + deltaX, (*L).startPoint.y + deltaY), CreatePoint((*L).endPoint.x + deltaX, (*L).endPoint.y + deltaY));
}

void mirror(LINE *L, boolean sbX, boolean sbY)
{
    CreateLine(L, CreatePoint((sbX ? -(*L).startPoint.x : (*L).startPoint.x), (sbY ? -(*L).startPoint.y : (*L).startPoint.y)), CreatePoint((sbX ? -(*L).endPoint.x : (*L).endPoint.x), (sbY ? -(*L).endPoint.y : (*L).endPoint.y)));
}

int calculatePanjang(LINE L)
{
    return sqrt(pow(L.endPoint.x-L.startPoint.x, 2) + pow(L.endPoint.y-L.startPoint.y, 2));
}

void lineCopy(LINE *L1, LINE L2)
{
    CreateLine(L1, L2.startPoint, L2.endPoint);
}

boolean isLineConnected(LINE L1, LINE L2)
{
    return PointEQ(L1.endPoint, L2.startPoint);
}