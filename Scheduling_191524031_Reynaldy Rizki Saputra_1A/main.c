// Program		: main.c
// Author		: Rey Rizki
// Description	: Main driver to test process queue using round robin + shortest job first
// Date			: Monday, 30 March 2020
// Version		: V 1.0
// Compiler		: gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04)

#include "queue.h"

void roundRobin(Process *process, u int N, u int quantumTime);

int main()
{
    u int quantumTime, N, i;
    scanf("%u %u", &quantumTime, &N);

    Process *process = (Process *)malloc(N * sizeof(Process));

    REP(i, 0, N)
    {
        processScan(process + i);
        (process + i)->id = i;
    }

    qsort((void *)process, N, sizeof(Process), arrivalTimeCompare);
    roundRobin(process, N, quantumTime);

    qsort((void *)process, N, sizeof(Process), idCompare);

    REP(i, 0, N)
        processPrint(*(process + i));

    free(process);

    return 0;
}

void roundRobin(Process *process, u int N, u int quantumTime)
{
    u int time = 0, i = 0;
    queue processQueue;
    Process temp;

    Initial(&processQueue, N);

    while ((i < N) || !IsEmpty(processQueue))
    {
        if (IsEmpty(processQueue) && (i < N))
            time = (*(process + i)).arrivalTime;

        while ((time >= (*(process + i)).arrivalTime) && (i < N))
        {
            Insert(&processQueue, *(process + i));
            i++;
        }

        qsort((void *)processQueue.data, queueSize(processQueue), sizeof(Process), remainingCompare);

        processing(&(processQueue.data[0].remaining), &time, quantumTime);

        if (processQueue.data[0].remaining == 0)
        {
            Delete(&processQueue, &temp);
            temp.completionTime = time;
            *(searchById(process, temp.id)) = temp;
        }
    }
}