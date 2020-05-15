#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void MakePoint(POINT* P, int XX, int YY)
{
    (*P).x = XX;
    (*P).y = YY;
}

POINT CreatePoint(int XX, int YY)
{
    POINT p;
    
    p.x = XX;
    p.y = YY;

    return p;
}

void PrintPoint(POINT P)
{
    printf("%d %d\n", P.x, P.y);
}

int GetX(POINT P)
{
    return P.x;
}

void SetX(POINT *P, int newX)
{
    (*P).x = newX;
}

int GetY(POINT P)
{
    return P.y;
}

void SetY(POINT *P, int newY)
{
    (*P).y = newY;
}

void ReSet(POINT *P)
{
    (*P).x = 0;
    (*P).y = 0;
}

int Kuadran(POINT P)
{
    if ((P.x > 0) && (P.y > 0))
        return 1;
    else if ((P.x < 0) && (P.y > 0))
        return 2;
    else if ((P.x < 0) && (P.y < 0))
        return 3;
    else if ((P.x > 0) && (P.y < 0))
        return 4;
    else 
        return -1;
}
/* menghasilkan kuadran dari POINT P*/
// return -1 jika berada pada origin, sumbu x, dan sumbu y

boolean IsOnSumbuX(POINT P)
{
    return P.y == 0;
}
/* Mengirimkan True jika P ada di sumbu X  */

boolean IsOnSumbuY(POINT P)
{
    return P.x == 0;
}

boolean IsOrigin(POINT P)
{
    return (P.x == 0) && (P.y == 0);
}

void NextX(POINT *PP)
{
    (*PP).x += 1;
}

void NextX_N(POINT *PP, int N)
{
    (*PP).x += N;
}

void PrevX(POINT *P)
{
    (*P).x -= 1;
}

void PrevX_N(POINT *P, int N)
{
    (*P).x -= N;
}

int Jarak (POINT P1, POINT P2)
{
    return sqrt(((P2.x-P1.x) * (P2.x-P1.x)) + ((P2.y-P1.y) * (P2.y-P1.y)));
    // return (int) sqrt(pow(P2.x-P1.x, 2) + pow(P2.y-P1.y, 2)); 
}