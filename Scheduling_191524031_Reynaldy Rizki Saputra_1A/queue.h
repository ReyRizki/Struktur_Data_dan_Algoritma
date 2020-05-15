// Program		: queue.h
// Author		: Rey Rizki
// Description	: Static queue ADT header file (calibrated for process ADT)
// Date			: Monday, 30 March 2020
// Version		: V 1.2
// Compiler		: gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04)

#ifndef queue_H
#define queue_H

#include "process.h"

typedef struct 
{
    Process *data;
    u int capacity;
    int front;
    int rear;
} queue;

int IsFull(queue Q);
int IsEmpty(queue Q);
void SetFront(queue *Q, int idx);
void SetRear(queue *Q, int idx);
void Delete(queue *Q, Process *vdata);
void Initial(queue *Q, int N);
void Insert(queue *Q, Process vdata);
void Tampil(queue Q);
void ResetQueue(queue *Q);
int queueSize(queue Q);

#endif