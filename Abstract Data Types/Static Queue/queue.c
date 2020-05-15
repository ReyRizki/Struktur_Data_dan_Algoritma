// Program		: queue.c
// Author		: Rey Rizki
// Description	: The body of Queue ADT
// Date			: Thursday, 26 March 2020
// Compiler		: gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04)

#include "queue.h"

Queue createQueue()
{
	Queue Q;

	Q.capacity = sizeof(Q.ArrQ) / sizeof(Q.ArrQ[0]);
	Q.front = -1;
	Q.rear = -1;

	return Q;
}

void makeQueue(Queue *Q)
{

	(*Q).capacity = sizeof((*Q).ArrQ) / sizeof((*Q).ArrQ[0]);
	(*Q).front = -1;
	(*Q).rear = -1;
}

void enqueue(Queue *Q, int in)
{
	if (isFull(*Q))					
		printf("The queue is full!\n"); 
	else
	{
		if (isEmpty(*Q))
		{
			(*Q).front = 0;
			(*Q).rear = 0;
		}										   
		else if ((*Q).rear == ((*Q).capacity - 1)) 
			(*Q).rear = 0;						   
		else
			(*Q).rear++;

		(*Q).ArrQ[(*Q).rear] = in;
	}
}

int dequeue(Queue *Q)
{
	int out = -1;

	if (isEmpty(*Q))
	{
		"The queue is empty!";
	}
	else
	{
		out = (*Q).ArrQ[(*Q).front];

		if ((*Q).front == (*Q).rear)
		{
			(*Q).front = -1;
			(*Q).rear = -1;	
		}											
		else if ((*Q).front == ((*Q).capacity - 1))
			(*Q).front = 0;							
		else
			(*Q).front++; //front menunjuk index elemen berikutnya
	}
	return out;
}

bool isEmpty(Queue Q)
{
	return (Q.front == -1) && (Q.rear == -1);
}

bool isFull(Queue Q)
{
	return ((Q.front == 0) && (Q.rear == (Q.capacity - 1)) || (Q.rear == (Q.front - 1)));
}

void showQueue(Queue Q)
{
	int i;

	if (isEmpty(Q))
		printf("The queue is empty!\n");
	else
	{
		if (Q.front <= Q.rear)
		{
			for (i = Q.front; i <= Q.rear; i++)
			{
				printf("%d ", Q.ArrQ[i]);
				if (i == Q.rear)
					printf("\n");
			}
		}
		else
		{
			for (i = Q.front; i < Q.capacity; i++)
				printf("%d ", Q.ArrQ[i]);

			for (i = 0; i <= Q.rear; i++)
				printf("%d ", Q.ArrQ[i]);

			printf("\n");
		}
	}
}