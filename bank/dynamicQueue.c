// Program		: dynamicQueue.c
// Author		: Rey Rizki
// Description	: Dynamic Queue ADT body implementation file
// Date			: Saturday, 18 April 2020
// Version		: V 1.1
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
    return isQueueEmpty(queue) ? createCustomer('x', createTime(0, 0, 0), 0) : dataOfHead(queue.list);
}