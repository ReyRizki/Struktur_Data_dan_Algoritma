// Program		: main.c
// Author		: Rey Rizki
// Description	: The main driver to check the Queue ADT
// Date			: Thursday, 26 March 2020
// Compiler		: gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04)

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main()
{ 
    Queue Q;

    Q = createQueue();
    printf("%d\n", Q.capacity);

    enqueue(&Q, 5);
    enqueue(&Q, 4);
    enqueue(&Q, 8);
    enqueue(&Q, 10);
    enqueue(&Q, 9);
    enqueue(&Q, 2);
    enqueue(&Q, 100);
    enqueue(&Q, 10);

    printf("%d\n", dequeue(&Q));
    showQueue(Q);

    return 0;
}