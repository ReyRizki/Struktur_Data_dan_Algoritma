#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "line.h"

int main()
{
    LINE L1, L2;

    readLine(&L1);
    printLine(L1);

    readLine(&L2);
    printLine(L2);

    setStartPoint(&L2, CreatePoint(6, 9));
    PrintPoint(getStartPoint(L2));

    move(&L1, 5, 100);
    printLine(L1);

    printf("%d\n", NEQ(L1, L2));
    printf("%d\n", isTegakLurus(L1, L2));
    printf("%d\n", isSejajar(L1, L2));

    printf("%d\n", getKuadran(L1));
    printf("%d\n", calculatePanjang(L2));

    mirror(&L1, true, false);
    printLine(L1);
}