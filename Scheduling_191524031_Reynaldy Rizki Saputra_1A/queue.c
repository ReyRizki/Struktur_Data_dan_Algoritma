// Program		: queue.c
// Author		: Rey Rizki
// Description	: Static queue body implementation file (calibrated for process ADT)
// Date			: Monday, 30 March 2020
// Version		: V 1.2
// Compiler		: gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04)

#include "queue.h"

int IsFull(queue Q)
{
    return Q.rear == (Q.capacity - 1);
}

int IsEmpty(queue Q)
{
    return Q.rear == -1;
}

void SetFront(queue *Q, int idx)
{
    Q->front = idx;
}

void SetRear(queue *Q, int idx)
{
    Q->rear = idx;
}

void Delete(queue *Q, Process *vdata)
{
    u int i = 0;
    if (IsEmpty(*Q))
        printf("Underflow\n");
    else
    {
        *vdata = *(Q->data);

        REP(i, 0, (*Q).rear)
            Q->data[i] = Q->data[i+1];

        (*Q).rear--;
    }
}

void Initial(queue *Q, int N)
{
    Q->data = (Process *) malloc(N * sizeof(Process));
    Q->capacity = N;
    SetFront(Q, 0);
    SetRear(Q, -1);
}

void Insert(queue *Q, Process vdata)
{
    if (IsFull(*Q))
        printf("Overflow\n");
    else
    {
        (*Q).rear++;
        *(Q->data + Q->rear) = vdata;
    }
}

void Tampil(queue Q)
{
    int i;

    if (IsEmpty(Q))
        printf("The queue is empty!\n");
    else
    {
        REP(i, 0, Q.rear + 1)
            processPrint(Q.data[i]);
    }
}

void ResetQueue(queue *Q)
{
    Initial(Q, (*Q).capacity);
}

int queueSize(queue Q)
{
    return Q.rear + 1;
}