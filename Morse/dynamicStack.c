// Program		: dynamicStack.c
// Author		: Rey Rizki
// Description	: Dynamic Stack ADT body implementation file
// Date			: Wednesday, 01 April 2020
// Version		: V 1.0
// Compiler		: gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04)

#include "dynamicStack.h"

Stack createStack()
{
    Stack stack;
    stack.list = createList();

    return stack;
}

bool isStackEmpty(Stack stack)
{
    return isListEmpty(stack.list);
}

void push(Stack *stack, dataType n)
{
    insertAtHead(&(stack->list), n);
}

dataType pop(Stack *stack)
{   
    dataType result = top(*stack);

    deleteAtHead(&stack->list);
    
    return result;
}

dataType top(Stack stack)
{
    return dataOfHead(stack.list);
}

void printStack(Stack stack)
{
    printList(stack.list);
}

u int stackSize(Stack stack)
{
    return listSize(stack.list);
}