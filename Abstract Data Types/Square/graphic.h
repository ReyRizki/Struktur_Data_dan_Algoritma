#ifndef GRAPHIC_H_
#define GRAPHIC_H_

#include "square.h"

void printCartesius(POINT max);
void printPoint(POINT center, POINT target);
void printHorizontalLine(LINE L, POINT center);
void printVerticalLine(LINE L, POINT center);
void printRightLine(LINE L, POINT center);
void printBottomLine(LINE L, POINT center);
void printSquareGraphic(SQUARE S, POINT center);
void showSquare(SQUARE S);

#endif