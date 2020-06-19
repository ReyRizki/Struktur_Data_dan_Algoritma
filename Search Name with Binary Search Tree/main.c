#include "binstree.h"

int main()
{
    BinTree tree = NULL;
    
    InsSearchTree(&tree, "Endah");
    InsSearchTree(&tree, "Charly");
    InsSearchTree(&tree, "Badu");
    InsSearchTree(&tree, "Abdul");
    InsSearchTree(&tree, "Ade");
    InsSearchTree(&tree, "Baihaqi");
    InsSearchTree(&tree, "Fatimah");
    InsSearchTree(&tree, "Gagah");
    InsSearchTree(&tree, "Wildan");
    InsSearchTree(&tree, "Cucu");
    InsSearchTree(&tree, "Dudi");
    InsSearchTree(&tree, "Dudy");
    InsSearchTree(&tree, "Fajar");
    InsSearchTree(&tree, "Desi");
    InsSearchTree(&tree, "Fatman");
    InsSearchTree(&tree, "Fairuz");
    InsSearchTree(&tree, "Bahrum");
    InsSearchTree(&tree, "Badu");
    InsSearchTree(&tree, "Abah");
    InsSearchTree(&tree, "Cantika");
    
    // Inorder(tree);
    // printf("\n");

    printf((Search2(tree, "Abah") != NULL) ? "Found\n" : "Not found\n");
    printf((Search2(tree, "Fulan") != NULL) ? "Found\n" : "Not found\n");
}