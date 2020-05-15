#include <stdio.h>
#include "car.h"

void carInput(Car *c)
{
    scanf("%s", (*c).name);
    scanf("%d", &((*c).arrivalTime));
    (*c).timeSize = 20;
}

void carPrint(Car c)
{
    printf("%s %d %d %d %d\n", c.name, c.timeSize, c.arrivalTime, c.services, c.finish);
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