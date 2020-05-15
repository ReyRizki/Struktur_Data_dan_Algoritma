// Program		: dynamicQueue.c
// Author		: Rey Rizki
// Description	: Dynamic Queue ADT body implementation file
// Date			: Monday, 30 March 2020
// Version		: V 1.0
// Compiler		: gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04)

#include "dynamicQueue.h"

Queue createQueue()
{
    Queue queue;
    queue.list = createList();
    return queue;
}

bool isQueueEmpty(Queue queue)
{
    return isListEmpty(queue.list);
}

void enqueue(Queue *queue, dataType n)
{
    insertAtTail(&(queue->list), n);
}

dataType dequeue(Queue *queue)
{
    dataType front = queueFront(*queue);

    if (isQueueEmpty(*queue))
        printf("Underflow\n");
    else
        deleteAtHead(&(queue->list));

    return front;
}

void printQueue(Queue queue)
{
    printList(queue.list);
}

u int queueSize(Queue queue)
{
    return listSize(queue.list);
}

dataType queueFront(Queue queue)
{
    return isQueueEmpty(queue) ? -1 : dataOfHead(queue.list);
}

dataType queueRear(Queue queue)
{
    return isQueueEmpty(queue) ? -1 : dataOfTail(queue.list);
}