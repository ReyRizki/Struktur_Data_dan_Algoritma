// Program		: main.c
// Author		: Rey Rizki
// Description	: Main driver to test the dynamic deque ADT
// Date			: Wednesday, 01 April 2020
// Version		: V 1.0
// Compiler		: gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04)

#include "dynamicDeque.h"

int main()
{
    Deque deque = createDeque();

    insertFront(&deque, 20);
    insertRear(&deque, 10);
    insertFront(&deque, 3);

    printDeque(deque);

    return 0;
}