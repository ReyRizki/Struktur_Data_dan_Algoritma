#include "tree.h"

#ifndef MACROS
#define MACROS

#define u unsigned
#define s short
#define ll long long
#define REP(i, a, b) for (i = (a); i < (b); i++)
#define REPR(i, a, b) for (i = (a-1); i >= (b); i--)

#endif

int main()
{
    Tree tree = createTree(11);

    printf(isTreeEmpty(tree) ? "Yes\n" : "No\n");
    printf(isTreeFull(tree) ? "Yes\n" : "No\n");

    insertNode(&tree, 'A', -1);
    insertNode(&tree, 'B', 0);
    insertNode(&tree, 'C', 0);
    insertNode(&tree, 'D', 0);
    insertNode(&tree, 'E', 1);
    insertNode(&tree, 'F', 1);
    insertNode(&tree, 'G', 2);
    insertNode(&tree, 'H', 3);
    insertNode(&tree, 'I', 7);
    insertNode(&tree, 'J', 7);
    insertNode(&tree, 'K', 7);
    insertNode(&tree, 'L', 0);

    /*
                A
              / | \
             /  |  \
            /   |   \
           B    C    D
          / \   |    |
         /   \  |    |
        E     F G    H
                   / | \
                  I  J  K
    */

    printf("%c\n", getNodeData(getNode(tree, 1)));
    printf("%d\n", getNodeFirstChild(getNode(tree, 3)));
    printf("%d\n", getNodeNextSibling(getNode(tree, 2)));
    printf(isNodeLeaf(getNode(tree, 0)) ? "Yes\n" : "No\n");
    printf(isNodeExist(getNode(tree, 12)) ? "Yes\n" : "No\n");

    printf("%u\n", treeRoot(tree));

    printf("%u\n", nodeLevel(tree, 10));
    printf("%u\n", nodeOrder(tree, 1));
    printf("%u\n", treeDepth(tree));

    preorder(tree, treeRoot(tree));
    printf("\n");

    inorder(tree, treeRoot(tree));
    printf("\n");

    postorder(tree, treeRoot(tree));
    printf("\n");
    
    levelorder(tree, treeRoot(tree));
    printf("\n");

    deleteTree(&tree);

    return 0;
}