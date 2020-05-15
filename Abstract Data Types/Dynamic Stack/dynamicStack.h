// Program		: dynamicStack.h
// Author		: Rey Rizki
// Description	: Dynamic Stack ADT header file
// Date			: Wednesday, 01 April 2020
// Version		: V 1.0
// Compiler		: gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04)

#ifndef STACK_H_
#define STACK_H_

#include "linkedList.h"

typedef List Stack;

Stack createStack();

bool isStackEmpty(Stack s);

void push(Stack *stack, dataType n);
dataType pop(Stack *stack);
dataType top(Stack stack);

void printStack(Stack stack);
u int stackSize(Stack stack);

#endif