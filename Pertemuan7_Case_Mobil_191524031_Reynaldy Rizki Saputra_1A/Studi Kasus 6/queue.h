/* Program	:ADT queue statis
	Compiler	:Turbo C++*/

#ifndef queue_H
#define queue_H

#include <stdio.h>
#include "car.h"

#define MAX 5

typedef struct 
{
    Car *data[MAX];
    int front;
    int rear;
}queue;

int IsFull(queue Q);
int IsEmpty(queue Q);
void SetFront(queue *Q, int idx);
void SetRear(queue *Q, int idx);
void Delete(queue *Q, Car **vdata);
void Initial(queue *Q);
void Insert(queue *Q, Car *vdata);
void Tampil(queue Q);
void ResetQueue(queue *Q);
int queueSize(queue Q);
Car frontQueue(queue Q);

#endif