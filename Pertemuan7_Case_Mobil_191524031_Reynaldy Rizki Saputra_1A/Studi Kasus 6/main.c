#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"
#include "car.h"
#include "Time.h"

#define REP(i, a, b) for (i = (a); i < (b); i++)
#define REPR(i, a, b) for (i = (a-1); i >= (b); i--)

typedef struct {
    bool washing;
    Car *current;
} WashPlace;

int main()
{
    Car *car, next;
    queue carQueue;
    WashPlace washer[2];
    int N, i, cooldown = 0;
    TIME time;

    CreateTIME(&time, 7, 0, 0);

    scanf("%d", &N);
    
    car = (Car *) malloc(N * sizeof(Car));

    Initial(&carQueue);

    REP(i, 0, N)
    {
        carInput(car + i);
        Insert(&carQueue, car + i);
    }

    REP(i, 0, 2)
        washer[i].washing = false;

    while (!IsEmpty(carQueue))
    {
        REP(i, 0, 2)
        {
            next = frontQueue(carQueue);
            if (!washer[i].washing)
            {
                if (JLT(next.arrivalTime, time) || JEQ(next.arrivalTime, time))
                {
                    Delete(&carQueue, &washer[i].current);
                    carWash(washer[i].current, time, 65 + i, cooldown);
                    washer[i].washing = true;
                }
            }
            else if (washer[i].washing)
            {
                if (JEQ((*washer[i].current).finish, time))
                {
                    washer[i].washing = false;
                    cooldown = (*washer[i].current).cooldown;
                }
            }
        }
        SetMinute(&time, GetMinute(time) + 1);
    }
    
    REP(i, 0, N)
        carPrint(*(car + i));

    return 0;
}