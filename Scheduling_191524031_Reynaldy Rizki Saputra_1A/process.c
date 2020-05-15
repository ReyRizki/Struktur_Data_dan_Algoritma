// Program		: process.c
// Author		: Rey Rizki
// Description	: Process ADT body implemetation file
// Date			: Monday, 30 March 2020
// Version		: V 1.0
// Compiler		: gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04)

#include "process.h"

void processScan(Process *p)
{
    scanf("%u %u", &(p->arrivalTime), &(p->burstTime));
    p->remaining = p->burstTime;
}

void processPrint(Process p)
{
    printf("%u %u %u %u %u\n", p.arrivalTime, p.burstTime, p.completionTime, processGetTurnAroundTime(p), processGetWaitingTime(p));
}

u int processGetTurnAroundTime(Process p)
{
    return p.completionTime - p.arrivalTime;
}

u int processGetWaitingTime(Process p)
{
    return processGetTurnAroundTime(p) - p.burstTime;
}

void processing(u int *remaining, u int *time, u int quantumTime)
{
    if (*remaining > quantumTime)
    {
        *time += quantumTime;
        *remaining -= quantumTime;
    }
    else
    {
        *time = *time + *remaining;
        *remaining = 0;
    }
}

int arrivalTimeCompare(const void *p, const void *q)
{
    return (((Process *)p)->arrivalTime) - (((Process *)q)->arrivalTime);
}

int idCompare(const void *p, const void *q)
{
    return (((Process *)p)->id) - (((Process *)q)->id);
}

int remainingCompare(const void *p, const void *q)
{
    return (((Process *)p)->remaining) - (((Process *)q)->remaining);
}

Process * searchById(Process *arr, int id)
{
    return ((*(arr)).id == id) ? (arr) : searchById(arr + 1, id);
}