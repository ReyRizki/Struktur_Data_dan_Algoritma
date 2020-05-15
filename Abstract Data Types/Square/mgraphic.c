#include <ncurses.h>
#include <stdlib.h>
#include <math.h>
#include "graphic.h"

int main()
{
    SQUARE S;

    readSquare(&S);

    showSquare(S);
}