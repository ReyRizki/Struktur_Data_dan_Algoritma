#include "point.h"

typedef struct
{  
    POINT startPoint;
    POINT endPoint;
} LINE;

void CreateLine(LINE *L, POINT P1, POINT P2);

POINT getStartPoint(LINE L);
POINT getEndPoint(LINE L);

void setStartPoint(LINE *L, POINT newStartPoint);
void setEndPoint(LINE *L, POINT newEndPoint);

void readLine(LINE *L);
void printLine(LINE L);

boolean EQ(LINE L1, LINE L2);
boolean NEQ(LINE L1, LINE L2);

boolean isOnSbX(LINE L);
boolean isOnSbY(LINE L);
int getKuadran(LINE L);

boolean isTegakLurus(LINE L1, LINE L2);
boolean isSejajar(LINE L1, LINE L2);

void move(LINE *L, int deltaX, int deltaY);
void mirror(LINE *L, boolean sbX, boolean sbY);
int calculatePanjang(LINE L);