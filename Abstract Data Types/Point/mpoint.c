#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "point.h"

#define origin 0
#define absis 1
#define ordinat 2

char zero(POINT P);

int main()
{
    POINT coordinate;
    int N;

    scanf("%d %d", &coordinate.x, &coordinate.y);

    if ((Kuadran(coordinate) == 1) || (Kuadran(coordinate) == 2))
    {
        PrintPoint(coordinate);
        if (Kuadran(coordinate) == 1)
            NextX(&coordinate);
        else
            PrevX(&coordinate);

        PrintPoint(coordinate);
    }
    else if ((Kuadran(coordinate) == 3) || (Kuadran(coordinate) == 4))
    {
        scanf("%d", &N);
        PrintPoint(coordinate);

        if (Kuadran(coordinate) == 3)
            PrevX_N(&coordinate, N);
        else
            NextX_N(&coordinate, N);

        PrintPoint(coordinate);
    }
    else
    {
        PrintPoint(coordinate);
        switch(zero(coordinate))
        {
        case origin:
            printf("Titik Origin");
            break;

        case absis:
            printf("Titik berada pada sumbu X");
            break;

        case ordinat:
            printf("Titik berada pada sumbu Y");
            break;
        }
        printf("\n");
    }
}

char zero(POINT P)
{
    return IsOrigin(P) ? origin : (IsOnSumbuX(P) ? absis : ordinat);
}