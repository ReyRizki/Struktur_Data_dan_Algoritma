#include "graphic.h"
#include <ncurses.h>
#include <stdlib.h>
#include <math.h>

void printCartesius(POINT max)
{
    int i;

    start_color();
    init_pair(1, COLOR_BLACK, COLOR_WHITE);
    attron(COLOR_PAIR(1));
    for (i = 0; i < max.x; i++)
        mvaddch(max.y / 2, i, ' ');

    for (i = 0; i < max.y; i++)
        mvaddch(i, max.x / 2, ' ');

    move(max.y / 2, max.x / 2);
    attroff(COLOR_PAIR(1));
}

void printPoint(POINT center, POINT target)
{
    start_color();
    init_pair(2, COLOR_BLACK, COLOR_BLUE);
    attron(COLOR_PAIR(2));
    mvaddch(center.y - target.y, center.x + target.x, ' ');
    move(center.y, center.x);
    attroff(COLOR_PAIR(2));
}

void printHorizontalLine(LINE L, POINT center)
{
    POINT cursor;
    int i;

    MakePoint(&cursor, L.startPoint.x, L.startPoint.y);

    while (cursor.x <= L.endPoint.x)
    {
        printPoint(center, cursor);
        SetX(&cursor, GetX(cursor) + 1);
    }
}

void printVerticalLine(LINE L, POINT center)
{
    POINT cursor;
    int i;

    MakePoint(&cursor, L.startPoint.x, L.startPoint.y);

    while (cursor.y <= L.endPoint.y)
    {
        printPoint(center, cursor);
        SetY(&cursor, GetY(cursor) + 1);
    }
}

void printRightLine(LINE L, POINT center)
{
    POINT cursor;
    int i;

    MakePoint(&cursor, L.startPoint.x, L.startPoint.y);

    while (cursor.y >= L.endPoint.y)
    {
        printPoint(center, cursor);
        SetY(&cursor, GetY(cursor) - 1);
    }
}

void printBottomLine(LINE L, POINT center)
{
    POINT cursor;
    int i;

    MakePoint(&cursor, L.startPoint.x, L.startPoint.y);

    while (cursor.x >= L.endPoint.x)
    {
        printPoint(center, cursor);
        SetX(&cursor, GetX(cursor) - 1);
    }
}

void printSquareGraphic(SQUARE S, POINT center)
{
    printHorizontalLine(S.s[top], center);
    printRightLine(S.s[right], center);
    printBottomLine(S.s[bottom], center);
    printVerticalLine(S.s[left], center);
}

void showSquare(SQUARE S)
{
    POINT center, max, target;

    initscr();
    getmaxyx(stdscr, max.y, max.x);
    MakePoint(&center, max.x/2, max.y/2);

    printCartesius(max);
    printSquareGraphic(S, center);

    refresh();
    getch();
    endwin();
}