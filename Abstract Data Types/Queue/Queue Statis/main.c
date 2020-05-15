#include <stdio.h>
#include "queue.h"

int main()
{
    queue Q;
    int counter;

    Initial(&Q, &counter);
    printf("%d\n", counter);
    Insert(&Q, 5, &counter);
    Insert(&Q, 7, &counter);
    Insert(&Q, 10, &counter);
    Insert(&Q, 2, &counter);
    Insert(&Q, 3, &counter);
    Insert(&Q, 3, &counter);
    Delete(&Q, &counter);
    Tampil(Q);

    return 0;
}