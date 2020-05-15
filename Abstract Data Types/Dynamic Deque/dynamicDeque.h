// Program		: dynamicDeque.h
// Author		: Rey Rizki
// Description	: Dynamic deque ADT header file
// Date			: Wednesday, 01 April 2020
// Version		: V 1.0
// Compiler		: gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04)

#ifndef DEQUE_H_
#define DEQUE_H_

#include "linkedList.h"

typedef List Deque;

Deque createDeque();

bool isDequeEmpty(Deque deque);

void insertFront(Deque *deque, dataType n);
void insertRear(Deque *deque, dataType n);

dataType deleteFront(Deque *deque);
dataType deleteRear(Deque *deque);

dataType getFront(Deque deque);
dataType getRear(Deque deque);

void printDeque(Deque deque);
u int dequeSize(Deque deque);

#endif