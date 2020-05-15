#include <stdio.h>
#include "car.h"

void carInput(Car *c)
{
    scanf("%s", (*c).name);
    scanf("%s", (*c).code);
    scanf("%d", &((*c).arrivalTime));
    (*c).timeSize = carTimeSize(*c);
}

void carPrint(Car c)
{
    printf("%s %s %d %d %d %d\n", c.name, c.code, c.timeSize, c.arrivalTime, c.services, c.finish);
}

void carWash(Car *c, int *time)
{
    if ((*c).arrivalTime > *time)
        c->services = (*c).arrivalTime;
    else
        c->services = *time;

    c->finish = c->services + (*c).timeSize;
    *time = c->finish;
}

void washDelay(int *time)
{
    *time += 1;
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