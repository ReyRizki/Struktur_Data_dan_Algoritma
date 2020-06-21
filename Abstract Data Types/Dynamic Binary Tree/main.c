// Program		: main.c
// Author		: Rey Rizki
// Description	: Main driver for Tree ADT
// Date			: Tuesday, 12 May 2020
// Version		: V 1.0
// Compiler		: gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04)

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
    Tree tree = createTree();

    insertNode(&tree, &tree.root, 0, 0, 'A');
    insertNode(&tree, &tree.root, 'A', 0, 'B');
    insertNode(&tree, &tree.root, 0, 0, 'D');
    insertNode(&tree, &tree.root, 'D', 1, 'C');
    insertNode(&tree, &tree.root->child[right], 'C', 0, 'X');
    insertNode(&tree, &tree.root, 'C', 1, 'E');
    insertNode(&tree, &tree.root, 'X', 1, 'Y');

    printf("%c\n", getNodeParent(tree.root, searchNode(tree.root, 'A'), NULL)->data);

    printf("%d\n", isNodeRoot(tree, searchNode(tree.root, 'D')));
    printf("%d\n", isNodeRoot(tree, searchNode(tree.root, 'B')));

    printf("%d\n", nodeLevel(tree, searchNode(tree.root, 'X')));

    printf("%d\n", nodeOrder(searchNode(tree.root, 'C')));
    printf("%d\n", treeDepth(tree));
    printf("%u\n", nodeDegree(searchNode(tree.root, 'B')));
    printf("%d\n", treeDegree(tree));

    preorder(tree.root);
    printf("\n");
    inorder(tree.root);
    printf("\n");
    postorder(tree.root);
    printf("\n");
    levelorder(tree.root);
    printf("\n");

    address target = searchNode(tree.root, 'Y');
    deleteNode(&tree, &target);
    
    preorder(tree.root);
    printf("\n");

    target = tree.root;
    deleteTree(&tree, &target);

    preorder(tree.root);
    printf("\n");
    printf(isTreeEmpty(tree) ? "Y\n" : "N\n");

    return 0;
}