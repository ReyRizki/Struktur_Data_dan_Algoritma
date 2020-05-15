/* Program	:ADT queue statis
	Compiler	:Turbo C++*/

#ifndef queue_H
#define queue_H

#include <stdio.h>
#define MAX 5

typedef struct 
{
    int data[MAX];
    int front;
    int rear;
}queue;

int IsFull(int counter);
int IsEmpty(int counter);
void SetFront(queue *Q, int idx);
void SetRear(queue *Q, int idx);
void Delete(queue *Q, int *counter);
void Initial(queue *Q, int *counter);
void Insert(queue *Q, int vdata, int *counter);
void Tampil(queue Q);

#endif