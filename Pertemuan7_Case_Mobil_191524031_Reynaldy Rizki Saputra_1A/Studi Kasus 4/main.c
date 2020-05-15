#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "car.h"

#define REP(i, a, b) for (i = (a); i < (b); i++)
#define REPR(i, a, b) for (i = (a-1); i >= (b); i--)

int main()
{
    Car *car, *current;
    queue carQueue;
    int N, i;
    int time = 0;

    scanf("%d", &N);
    
    car = (Car *) malloc(N * sizeof(Car));

    Initial(&carQueue);

    REP(i, 0, N)
    {
        carInput(car + i);
        Insert(&carQueue, car + i);
    }

    while (!IsEmpty(carQueue))
    {
        Delete(&carQueue, &current);
        carWash(current, &time);
        washDelay(&time, (*current).cooldown);
    }
    
    REP(i, 0, N)
        carPrint(*(car + i));

    return 0;
}