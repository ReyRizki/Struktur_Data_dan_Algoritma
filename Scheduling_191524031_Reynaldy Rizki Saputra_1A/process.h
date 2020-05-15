// Program		: process.h
// Author		: Rey Rizki
// Description	: Process ADT heaad
// Date			: Monday, 30 March 2020
// Version		: V 1.0
// Compiler		: gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04)

#ifndef PROCESS_H_
#define PROCESS_H_

#include <stdio.h>
#include <stdlib.h>

#define u unsigned
#define ll long long
#define ull u ll
#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define REPR(i, a, b) for (int i = (a - 1); i >= (b); i--)

typedef struct
{
    u int id;
    u int arrivalTime;
    u int burstTime;
    u int remaining;
    u int completionTime;
} Process;

void processScan(Process *p);
void processPrint(Process p);

u int processGetTurnAroundTime(Process p);
u int processGetWaitingTime(Process p);

void processing(u int *remaining, u int *time, u int quantumTime);

int arrivalTimeCompare(const void *p, const void *q);
int remainingCompare(const void *p, const void *q);
int idCompare(const void *p, const void *q);

Process *searchById(Process *arr, int id);

#endif