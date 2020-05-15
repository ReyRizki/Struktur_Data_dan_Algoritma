#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "square.h"
#include "graphic.h"

int main()
{
    char c;
    SQUARE sq;

    readSquare(&sq);
    printSquare(sq);

    printf("%d\n", squareArea(sq));
    printf("%d\n", squareCircumference(sq));

    showSquare(sq);
    
    return 0;
}