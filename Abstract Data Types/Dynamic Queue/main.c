// Program		: main.c
// Author		: Rey Rizki
// Description	: Main driver of dynamic queue ADT
// Date			: Monday, 30 March 2020
// Version		: V 1.0
// Compiler		: gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04)

#include "dynamicQueue.h"

int main()
{
    Queue queue = createQueue();
    int value;

    enqueue(&queue, 5);

    value = dequeue(&queue);
    value = dequeue(&queue);

    enqueue(&queue, 3);
    enqueue(&queue, 8);
    enqueue(&queue, 7);

    printQueue(queue);

    value = dequeue(&queue);
    
    enqueue(&queue, 100);
    enqueue(&queue, -24);

    printf("%d %d\n", queueFront(queue), queueRear(queue));

    printQueue(queue);

    return 0;
}