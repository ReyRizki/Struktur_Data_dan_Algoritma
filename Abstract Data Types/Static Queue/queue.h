// Program		: queue.h
// Author		: Rey Rizki
// Description	: The head of Queue ADT
// Date			: Thursday, 26 March 2020
// Compiler		: gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04)

#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct
{
	int ArrQ[7];
	int front;
	int rear;
	unsigned int capacity;
}Queue;

// Description		: Function to create an empty queue
// Input			: -
// Output			: An empty queue
Queue createQueue();

// Description		: Procedure to make an empty queue
// Initial State	: The queue isn't made yet
// Final State		: The queue is made
void makeQueue(Queue *Q);

// Description		: Procedure to add a value to the queue
// Initial State	: The value hasn't added yet
// Final State		: The value has added
void enqueue(Queue *Q, int in);

// Description		: Function to get the front of the queue and delete it
// Input			: The queue
// Output			: The front value
int dequeue(Queue *Q);

// Description		: Function to check if a queue is empty or not
// Input			: The queue
// Output			: True if empty and false if not empty
bool isEmpty(Queue Q);

// Description		: Function to check if a queue is full or not
// Input			: The queue
// Output			: True if full and false if not full
bool isFull(Queue Q);

// Description		: Procedure to print a queue
// Initial State	: The queue isn't printed yet
// Final State		: The queue is printed
void showQueue(Queue Q);

#endif