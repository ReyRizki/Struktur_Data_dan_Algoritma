#include "binstree.h"

int main()
{
    BinTree tree = NULL;

    InsSearchTree(&tree, 'B');
    InsSearchTree(&tree, 'A');
    InsSearchTree(&tree, 'C');

    // PrintTree(tree);

    Inorder(tree);
    printf("\n");
}