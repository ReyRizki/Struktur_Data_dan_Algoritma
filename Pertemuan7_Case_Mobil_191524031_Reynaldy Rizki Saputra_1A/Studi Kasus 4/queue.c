#include <stdio.h>
#include "queue.h"

int IsFull(queue Q)
{
    return ((Q.front == 0) && (Q.rear == (MAX - 1)) || (Q.rear == (Q.front - 1)));
}

int IsEmpty(queue Q)
{
    return (Q.front == -1) && (Q.rear == -1);
}

void SetFront(queue *Q, int idx)
{
    Q->front = idx;
}

void SetRear(queue *Q, int idx)
{
    Q->rear = idx;
}

void Delete(queue *Q, Car **vdata)
{
    if (IsEmpty(*Q))
        printf("Underflow\n");
    else
    {
        *vdata = Q->data[Q->front];
        if ((*Q).front == (*Q).rear)
        {
            (*Q).front = -1;
            (*Q).rear = -1;
        }
        else if ((*Q).front == (MAX - 1))
            (*Q).front = 0;
        else
            (*Q).front++;
    }
}

void Initial(queue *Q)
{
    SetFront(Q, -1);
    SetRear(Q, -1);
}

void Insert(queue *Q, Car *vdata)
{
    if (IsFull(*Q))
        printf("Overflow\n");
    else
    {
        if (IsEmpty(*Q))
        {
            (*Q).front = 0;
            (*Q).rear = 0;
        }
        else if ((*Q).rear == (MAX - 1))
            (*Q).rear = 0;
        else
            (*Q).rear++;

        Q->data[(*Q).rear] = vdata;
    }
}

void Tampil(queue Q)
{
    int i;

    if (IsEmpty(Q))
        printf("The queue is empty!\n");
    else
    {
        if (Q.front <= Q.rear)
        {
            for (i = Q.front; i <= Q.rear; i++)
            {
                carPrint(*(Q.data[i]));
            }
        }
        else
        {
            for (i = Q.front; i < MAX; i++)
                carPrint(*(Q.data[i]));

            for (i = 0; i <= Q.rear; i++)
                carPrint(*(Q.data[i]));
        }
    }
}

int queueSize(queue Q)
{
    return (Q.rear >= Q.front) ? Q.front - Q.rear + 1 : MAX - Q.front + Q.rear + 1;
}
