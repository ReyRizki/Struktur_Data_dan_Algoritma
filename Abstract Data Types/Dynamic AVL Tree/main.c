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
    TreeRoot root = createTree();

    // insertNode(&root, 50);
    // insertNode(&root, 30);
    // insertNode(&root, 70);
    // insertNode(&root, 20);
    // insertNode(&root, 40);
    // insertNode(&root, 60);
    // insertNode(&root, 80);

    // insertNode(&root, 75);
    
    insertNode(&root, 50);
    insertNode(&root, 70);
    insertNode(&root, 80);

    preorder(root);
    printf("\n");

    // leftRotate(&root->child[right]);
    // rightRotate(&root);
    // preorder(root);
    // printf("\n");

    // printf("%d\n", getBalance(searchNode(root, 50)));

    // deleteNode(&root, 20);
    // deleteNode(&root, 80);

    // printf("%d\n", getBalance(searchNode(root, 30)));
    // printf("%d\n", getBalance(searchNode(root, 70)));

    // insertNode(&root, 65);
    // printf("%d\n", getBalance(searchNode(root, 70)));
}