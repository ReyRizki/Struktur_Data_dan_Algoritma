// Program		: dynamicQueue.h
// Author		: Rey Rizki
// Description	: Dynamic queue ADT header file
// Date			: Saturday, 18 April 2020
// Version		: V 1.1
// Compiler		: gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04)

#include "linkedList.h"

// struct for queue
typedef struct
{
    List list;
} Queue;

// CONSTRUCTOR
// ===========

// Description		: Function to create a new queue
// Input			: -
// Output			: Queue
Queue createQueue();

// VALIDATOR
// =========

// Description		: Function to check if a queue is empty or not
// Input			: Queue
// Output			: True if queue is empty, false if not  
bool isQueueEmpty(Queue queue);

// OPERATIONS
// ==========

// Description		: Procedure to add data to queue
// Initial State	: New data is not added yet
// Final State		: New data is added
void enqueue(Queue *queue, dataType n);

// Description		: Function to get front data of the queue and delete it
// Input			: Queue
// Output			: Front data of a queue (Print "underflow" if queue is empty)
dataType dequeue(Queue *queue);

// TRANSVERSAL
// ===========

// Description		: Procedure to print queue
// Initial State	: Queue is not printed yet
// Final State		: Queue is printed
void printQueue(Queue queue);

// Description		: Function to get size of the queue
// Input			: Queue
// Output			: Size of the queue
u int queueSize(Queue queue);

// ACCESSOR
// ========

// Description		: Function to get first data of a queue
// Input			: Queue
// Output			: First data of a queue (-1 if queue is empty)
dataType queueFront(Queue queue);