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

    insertNode(&root, &root, 0, left, 'A');
    insertNode(&root, &root, 'A', left, 'B');
    insertNode(&root, &root, 'A', right, 'C');

    preorder(root);
    printf("\n");

    deleteTree(&root);

    printf(isTreeEmpty(root) ? "Yes\n" : "No\n");
}