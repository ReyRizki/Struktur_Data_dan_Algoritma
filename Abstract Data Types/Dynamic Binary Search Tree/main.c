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

    root = insertNode(root, root, 50);
    root = insertNode(root, root, 30);
    root = insertNode(root, root, 70);
    root = insertNode(root, root, 20);
    root = insertNode(root, root, 40);
    root = insertNode(root, root, 60);
    root = insertNode(root, root, 80);

    // root = deleteNode(root, 20);
    
    // printf("%d\n", searchNode(root, 70)->data);
    // printf("%d\n", minValueNode(root)->data);

    // insertNode(&root, &root, 0, left, 1);
    // insertNode(&root, &root, 1, left, 2);
    // insertNode(&root, &root, 1, right, 3);

    preorder(root);
    printf("\n");

    root = deleteNode(root, 20);
    preorder(root);
    printf("\n");

    root = deleteNode(root, 30);
    preorder(root);
    printf("\n");

    root = deleteNode(root, 50);
    preorder(root);
    printf("\n");

    // inorder(root);
    // printf("\n");

    // deleteTree(&root);

    printf(isTreeEmpty(root) ? "Yes\n" : "No\n");
}