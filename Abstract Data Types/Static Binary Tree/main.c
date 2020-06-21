#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef MACROS
#define MACROS

#define u unsigned
#define s short
#define ll long long
#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define REPR(i, a, b) for (i = (a-1); i >= (b); i--)

#endif

int main()
{
    Tree tree = createTree();
    
    printf("%u\n", getCapacity(tree));
    printf("%d\n", isTreeEmpty(tree));

    insertNode(&tree, 0, left, 'A');
    printf("%d\n", isTreeEmpty(tree));
    printf("%d\n", isNodeEmpty(tree, 0));

    insertNode(&tree, 0, left, 'B');
    printf("%d\n", isNodeEmpty(tree, 1));
    printf("%c\n", tree.node[1]);

    levelorder(tree);
    printf("\n");
    // char *arr = (char *) malloc(4 * sizeof(char));
    // char arr[(int) pow(2, 3)];
    // printf("%ld\n", sizeof(arr)/sizeof(char));

    // printf("%d\n", (int) pow(2, 3));

    return 0;
}