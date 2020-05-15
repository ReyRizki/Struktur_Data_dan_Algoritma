#include "string.h"
#include "tree.h"

#ifndef MACROS
#define MACROS

#define u unsigned
#define s short
#define ll long long
#define REP(i, a, b) for (i = (a); i < (b); i++)
#define REPR(i, a, b) for (i = (a - 1); i >= (b); i--)

#endif

int main()
{
    Tree tree = createTree();
    generateMorseTree(&tree);

    inorder(tree.root);
    printf("\n");

    printString(encodeString(tree, "JTK Politeknik Negeri Bandung"));

    printString(decode(tree, "._  _._  .._ ._._.  _...  ..  ...  ._"));

    encodeFile(tree, "input.txt", "output.txt");

    return 0;
}