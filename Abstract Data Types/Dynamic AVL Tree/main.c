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
    
    // insertNode(&root, 50);
    // insertNode(&root, 70);
    // insertNode(&root, 80);

    // preorder(root);
    // printf("\n");

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

    // insertNode(&root, 30);
    // insertNode(&root, 5);
    // insertNode(&root, 35);
    // insertNode(&root, 32);
    // insertNode(&root, 40);

    // preorder(root);
    // printf("\n");
    
    // insertNode(&root, 45);
    // preorder(root);
    // printf("\n");

    // insertNode(&root, 13);
    // insertNode(&root, 10);
    // insertNode(&root, 15);
    // insertNode(&root, 16);
    // insertNode(&root, 11);
    // insertNode(&root, 5);
    // insertNode(&root, 4);
    // insertNode(&root, 6);

    // preorder(root);
    // printf("\n");

    // insertNode(&root, 7);
    // preorder(root);
    // printf("\n");

    // insertNode(&root, 5);
    // insertNode(&root, 2);
    // insertNode(&root, 7);
    // insertNode(&root, 1);
    // insertNode(&root, 4);
    // insertNode(&root, 6);
    // insertNode(&root, 9);
    // insertNode(&root, 3);
    // insertNode(&root, 16);
    
    // preorder(root);
    // printf("\n");

    // insertNode(&root, 15);
    // preorder(root);
    // printf("\n");

    // insertNode(&root, 44);
    // insertNode(&root, 17);
    // insertNode(&root, 62);
    // insertNode(&root, 32);
    // insertNode(&root, 50);
    // insertNode(&root, 78);
    // insertNode(&root, 48);
    // insertNode(&root, 54);
    // insertNode(&root, 88);

    // preorder(root);
    // printf("\n");

    // deleteNode(&root, 32);
    // preorder(root);
    // printf("\n");
    
    root = insertNode(root, 9);
    insertNode(root, 5);
    insertNode(root, 10);
    insertNode(root, 0);
    insertNode(root, 6);
    insertNode(root, 11);
    insertNode(root, -1);
    insertNode(root, 1);
    insertNode(root, 2);

    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");

    // deleteNode(&root, 10);
    // preorder(root);
    // printf("\n");
    
}