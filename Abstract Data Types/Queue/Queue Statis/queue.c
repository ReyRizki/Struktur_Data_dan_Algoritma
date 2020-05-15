#include <stdio.h>
#include "queue.h"

int IsFull(int counter)
{
    return counter == MAX;
}

int IsEmpty(int counter)
{
    return counter == 0;
}

void SetFront(queue *Q, int idx)
{
    Q->front = idx;
}

void SetRear(queue *Q, int idx)
{
    Q->rear = idx;
}

void Delete(queue *Q, int *counter)
{
    if (IsEmpty(*counter))
        printf("Underflow\n");
    else
    {
        if ((*Q).front == (*Q).rear)
        {
            (*Q).front = -1;
            (*Q).rear = -1;
        }
        else if ((*Q).front == (MAX - 1))
            (*Q).front = 0;
        else
            (*Q).front++;

        (*counter)--;
    }
}

void Initial(queue *Q, int *counter)
{
    *counter = 0;
    SetFront(Q, -1);
    SetRear(Q, -1);
}

void Insert(queue *Q, int vdata, int *counter)
{
    if (IsFull(*counter))
        printf("Overflow\n");
    else
    {
        if (IsEmpty(*counter))
        {
            (*Q).front = 0;
            (*Q).rear = 0;
        }
        else if ((*Q).rear == (MAX - 1))
            (*Q).rear = 0;
        else
            (*Q).rear++;

        (*Q).data[(*Q).rear] = vdata;

        (*counter)++;
    }
}

void Tampil(queue Q)
{
    int i;

    if (Q.front <= Q.rear)
    {
        for (i = Q.front; i <= Q.rear; i++)
        {
            printf("%d ", Q.data[i]);
            if (i == Q.rear)
                printf("\n");
        }
    }
    else
    {
        for (i = Q.front; i < MAX; i++)
            printf("%d ", Q.data[i]);

        for (i = 0; i <= Q.rear; i++)
            printf("%d ", Q.data[i]);

        printf("\n");
    }
}