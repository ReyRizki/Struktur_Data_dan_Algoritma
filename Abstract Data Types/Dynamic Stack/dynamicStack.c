// Program		: dynamicStack.c
// Author		: Rey Rizki
// Description	: Dynamic Stack ADT body implementation file
// Date			: Wednesday, 01 April 2020
// Version		: V 1.0
// Compiler		: gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04)

#include "dynamicStack.h"

Stack createStack()
{
    return createList();
}

bool isStackEmpty(Stack stack)
{
    return isListEmpty(stack);
}

void push(Stack *stack, dataType n)
{
    insertAtHead(stack, n);
}

dataType pop(Stack *stack)
{   
    deleteAtHead(stack);
    
    return top(*stack);
}
dataType top(Stack stack)
{
    return dataOfHead(stack);
}

void printStack(Stack stack)
{
    printList(stack);
}

u int stackSize(Stack stack)
{
    return listSize(stack);
}