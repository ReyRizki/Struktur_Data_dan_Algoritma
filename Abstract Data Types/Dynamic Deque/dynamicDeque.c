#include "dynamicDeque.h"

Deque createDeque()
{
    return createList();
}

bool isDequeEmpty(Deque deque)
{
    return isListEmpty(deque);
}

void insertFront(Deque *deque, dataType n)
{
    insertAtHead(deque, n);
}

void insertRear(Deque *deque, dataType n)
{
    insertAtTail(deque, n);
}

dataType deleteFront(Deque *deque)
{
    deleteAtHead(deque);
    return getFront(*deque);
}

dataType deleteRear(Deque *deque)
{
    deleteAtTail(deque);
    return getRear(*deque);
}

dataType getFront(Deque deque)
{
    return dataOfHead(deque);
}

dataType getRear(Deque deque)
{
    return dataOfTail(deque);
}

void printDeque(Deque deque)
{
    printList(deque);
}

u int dequeSize(Deque deque)
{
    return listSize(deque);
}