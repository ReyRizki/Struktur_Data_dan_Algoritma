#include <stdio.h>
#include "car.h"

void carInput(Car *c)
{
    scanf("%s", (*c).name);
    scanf("%s", (*c).code);
    ReadTIME(&((*c).arrivalTime));
    (*c).timeSize = carTimeSize(*c);
    (*c).cooldown = 1;
}

void carPrint(Car c)
{
    printf("%s %s %d ", c.name, c.code, c.timeSize);
    PrintTIME(c.arrivalTime);
    printf(" %c ", c.place);
    PrintTIME(c.services);
    printf(" ");
    PrintTIME(c.finish);
    printf(" ");
    printf("%d\n", c.cooldown);
}

void carWash(Car *c, TIME time, char place, int cooldown)
{
    c->services = (JGT((*c).arrivalTime, time)) ? (*c).arrivalTime : time;
    // SetMinute(&(c->services), GetMinute(c->services) + cooldown);
    c->finish = c->services;
    SetMinute(&(c->finish), GetMinute(c->services) + c->timeSize);
    c->place = place;
}

void washDelay(TIME *time, int cooldown)
{
    SetMinute(time, GetMinute(*time) + cooldown);
}

int carTimeSize(Car c)
{
    switch (c.code[2])
    {
    case '1':
        return 20;
    case '2':
        return 30;
    case '3':
        return 45;
    case '4':
        return 60;
    case '5':
        return 80;
    case '6':
        return 100;
    case '7':
        return 120;
    case '8':
        return 125;
    default:
        return -1;
    }
}

int carCooldown(Car c)
{
    switch (c.code[2])
    {
    case '1':
        return 1;
    case '2':
        return 2;
    case '3':
        return 4;
    case '4':
        return 5;
    case '5':
        return 6;
    case '6':
        return 8;
    case '7':
        return 9;
    case '8':
        return 10;
    default:
        return -1;
    }
}