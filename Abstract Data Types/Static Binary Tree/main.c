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

    insertNode(&tree, 0, right, 'C');
    
    insertNode(&tree, 1, left, 'D');
    insertNode(&tree, 1, right, 'E');
    insertNode(&tree, 2, left, 'F');
    insertNode(&tree, 2, right, 'G');

    printf("%d\n", isTreeFull(tree));
    
    levelorder(tree);
    printf("\n");

    preorder(tree, 0);
    printf("\n");

    inorder(tree, 0);
    printf("\n");

    postorder(tree, 0);
    printf("\n");

    printf("%d\n", searchNode(tree, 'A'));
    printf("%d\n", searchNode(tree, 'X'));

    printf("%d\n", findNode(tree, 'X'));

    printf("%d\n", getNodeChild(tree, 1, left));
    printf("%d\n", nodeDegree(tree, 3));
    printf("%d\n", nodeOrder(tree, 0));
    printf("%d\n", nodeDegree(tree, 1));

    printf("%d\n", nodeLevel(tree, 1));
    printf("%d\n", nodeLevel(tree, 4));

    printf("%d\n", nodeDegree(tree, 3));

    printf("%d\n", treeDepth(tree));
    printf("%d\n", treeDegree(tree));

    emptyNode(&tree, 0);
    emptyNode(&tree, 3);

    deleteTree(&tree);

    return 0;
}