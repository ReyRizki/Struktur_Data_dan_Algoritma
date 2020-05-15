// Program		: tree.c
// Author		: Rey Rizki
// Description	: Dynamic Binary Tree ADT body implementation file
// Date			: Thursday, 30 April 2020
// Version		: V 1.0
// Compiler		: gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04)

#include "tree.h"
#include <ctype.h>

#ifndef MACROS
#define MACROS

#define u unsigned
#define s short
#define ll long long
#define REP(i, a, b) for (i = (a); i < (b); i++)
#define REPR(i, a, b) for (i = (a-1); i >= (b); i--)

#endif

// ============= 
//  CONSTRUCTOR
// =============

// Description		: Function to create an empty tree
// Input			: -
// Output			: An empty tree
Tree createTree()
{
    Tree tree;

    tree.root = NULL;

    return tree;
}

// Description		: Function to create a new node
// Input			: A data for the new node
// Output			: A new node
TreeNodeAddress createTreeNode(dataType data)
{
    TreeNodeAddress node = (TreeNode *) malloc(sizeof(TreeNode));

    node->data = data;
    node->child[left] = NULL;
    node->child[right] = NULL;
    node->parent = NULL;

    return node;
}

// ==========
//  MUTATORS 
// ==========

// Description		: Procedure to insert a child to a subtree
// Initial State	: Child is not inserted yet
// Final State		: Child is inserted
void insertTreeNode(TreeNodeAddress *node, char index, dataType data)
{
    if (*node == NULL)
        *node = createTreeNode(data);
    else
    {
        (*node)->child[index] = createTreeNode(data);
        (*node)->child[index]->parent = *node;
    }
}

// ===========
//  ACCESSORS 
// ===========

// Description		: Procedure to visit a node in a tree (In this, program it will print the data of the node)
// Initial State	: The node hasn't visited yet
// Final State		: The node has been visited
void visitTreeNode(TreeNode node)
{
    printf((node.data == 0 ? "none " : (node.data == ' ' ? "space " : "%c ")), node.data);
    // printf("%c ", node.data);
}

// Description		: Procedure to traverse a tree by inorder
// Initial State	: The tree isn't traversed yet
// Final State		: All nodes has been visited
void inorder(TreeNodeAddress node)
{
    if (node != NULL)
    {
        inorder(node->child[left]);
        visitTreeNode(*node);
        inorder(node->child[right]);
    }
}

// Description		: Function to search a data in a tree
// Input			: Tree root, data to be searched
// Output			: Address of the data (NULL if data isn't exist)
TreeNodeAddress searchNode(TreeNodeAddress node, dataType data)
{
    if (node == NULL or node->data == toupper(data))
        return node;

    TreeNodeAddress result = searchNode(node->child[left], data);
    
    if (result != NULL)
        return result;

    result = searchNode(node->child[right], data);
    return result;
}

// ============
//  VALIDATORS 
// ============

// Description		: Function to check wether a tree is emtpy or not
// Input			: A tree
// Output			: 1 if emtpy, 0 if not empty
bool isTreeEmpty(Tree tree)
{
    return tree.root == NULL;
}

// Description		: Function to chek wether a node is a root or not
// Input			: A node of a tree
// Output			: 1 if root, 0 if not
bool isNodeRoot(TreeNode node)
{
    return node.parent == NULL;
}

// ===============
//  MORSE MODULES
// ===============

// Description		: Procedure to generate a morse tree
// Initial State	: The tree is empty
// Final State		: Morse Tree is generated
void generateMorseTree(Tree *tree)
{
    // level 0
    insertTreeNode(&(tree->root), left, 0);
    
    // level 1
    insertTreeNode(&(tree->root), left, 'E');
    insertTreeNode(&(tree->root), right, 'T');

    // level 2
    insertTreeNode(&(tree->root->child[left]), left, 'I');
    insertTreeNode(&(tree->root->child[left]), right, 'A');

    insertTreeNode(&(tree->root->child[right]), left, 'N');
    insertTreeNode(&(tree->root->child[right]), right, 'M');

    // level 3
    insertTreeNode(&(tree->root->child[left]->child[left]), left, 'S');
    insertTreeNode(&(tree->root->child[left]->child[left]), right, 'U');

    insertTreeNode(&(tree->root->child[left]->child[right]), left, 'R');
    insertTreeNode(&(tree->root->child[left]->child[right]), right, 'W');

    insertTreeNode(&(tree->root->child[right]->child[left]), left, 'D');
    insertTreeNode(&(tree->root->child[right]->child[left]), right, 'K');

    insertTreeNode(&(tree->root->child[right]->child[right]), left, 'G');
    insertTreeNode(&(tree->root->child[right]->child[right]), right, 'O');

    // level 4
    insertTreeNode(&(tree->root->child[left]->child[left]->child[left]), left, 'H');
    insertTreeNode(&(tree->root->child[left]->child[left]->child[left]), right, 'V');

    insertTreeNode(&(tree->root->child[left]->child[left]->child[right]), left, 'F');
    insertTreeNode(&(tree->root->child[left]->child[left]->child[right]), right, 0);

    insertTreeNode(&(tree->root->child[left]->child[right]->child[left]), left, 'L');
    insertTreeNode(&(tree->root->child[left]->child[right]->child[left]), right, 0);

    insertTreeNode(&(tree->root->child[left]->child[right]->child[right]), left, 'P');
    insertTreeNode(&(tree->root->child[left]->child[right]->child[right]), right, 'J');

    insertTreeNode(&(tree->root->child[right]->child[left]->child[left]), left, 'B');
    insertTreeNode(&(tree->root->child[right]->child[left]->child[left]), right, 'X');

    insertTreeNode(&(tree->root->child[right]->child[left]->child[right]), left, 'C');
    insertTreeNode(&(tree->root->child[right]->child[left]->child[right]), right, 'Y');

    insertTreeNode(&(tree->root->child[right]->child[right]->child[left]), left, 'Z');
    insertTreeNode(&(tree->root->child[right]->child[right]->child[left]), right, 'Q');

    insertTreeNode(&(tree->root->child[right]->child[right]->child[right]), left, '0');
    insertTreeNode(&(tree->root->child[right]->child[right]->child[right]), right, 0);

    // level 5
    insertTreeNode(&(tree->root->child[left]->child[left]->child[left]->child[left]), left, '5');
    insertTreeNode(&(tree->root->child[left]->child[left]->child[left]->child[left]), right, '4');

    insertTreeNode(&(tree->root->child[left]->child[left]->child[left]->child[right]), right, '3');

    insertTreeNode(&(tree->root->child[left]->child[left]->child[right]->child[right]), right, '2');    

    insertTreeNode(&(tree->root->child[left]->child[right]->child[left]->child[right]), left, ' ');

    insertTreeNode(&(tree->root->child[left]->child[right]->child[right]->child[right]), right, '1');

    insertTreeNode(&(tree->root->child[right]->child[left]->child[left]->child[left]), left, '6');

    insertTreeNode(&(tree->root->child[right]->child[right]->child[left]->child[left]), left, '7');

    insertTreeNode(&(tree->root->child[right]->child[right]->child[right]->child[left]), left, '8');

    insertTreeNode(&(tree->root->child[right]->child[right]->child[right]->child[right]), left, '9');
}

// Description		: Function to generate a stack of a given node address (reverse it)
// Input			: Node address
// Output			: A stack of morse code
Stack generateCode(TreeNodeAddress node)
{
    Stack stack = createStack();
    TreeNodeAddress trav = node;

    while (not isNodeRoot(*trav))
    {
        if (trav == trav->parent->child[left])
            push(&stack, '.');
        else if (trav == trav->parent->child[right])
            push(&stack, '_');

        trav = trav->parent;
    }

    return stack;
}

// Description		: Function to encode a character to a morse code
// Input			: A morse tree, a data to be encoded
// Output			: A morse code
String encodeChar(Tree tree, char data)
{
    String result = createString();

    Stack stack = generateCode(searchNode(tree.root, data));
    while (not isStackEmpty(stack))
        insertChar(&result, pop(&stack));

    // printf("%u\n", result.size);
    return result;
}

// Description		: Function to encode a string to a morse code
// Input			: A morse tree, a string to be encoded
// Output			: A morse code
String encodeString(Tree tree, char *string)
{
    String result = createString();
    u int len = strlen(string);
    String morseChar = createString();

    REP(i, 0, len)
    {
        // printString(encodeChar(tree, *(string + i)));

        morseChar = encodeChar(tree, string[i]);
        // printString(morseChar);

        concatenateString(&result, morseChar);

        if (i < len - 1)
            appendString(&result, "  ");

        deleteString(&morseChar);
    }

    return result;
}

// Description		: Function to decode a morse code to a string
// Input			: A morse tree and morse code
// Output			: A string
String decode(Tree tree, char *code)
{
    u int len = strlen(code);
    TreeNodeAddress trav = tree.root;
    String result = createString();

    REP(i, 0, len)
    {
        trav = (code[i] == '.' ? trav->child[left] : (code[i] == '_' ? trav->child[right] : trav));

        if (code[i] == ' ' or i == len - 1)
        {
            if (trav->data != 0)
                insertChar(&result, trav->data);

            trav = tree.root;
        }
    }

    return result;
}

// Description		: Procedure to encode a text file to morse code and put it in a text file
// Initial State	: The input file is filled with text
// Final State		: The output file is filled with morse code from input file
void encodeFile(Tree tree, char *input, char *output)
{
    FILE *inputPointer = fopen(input, "r"), *outputPointer = fopen(output, "w");
    char data;

    if (inputPointer == NULL or outputPointer == NULL)
    {
        printf("Can't open the file\n");
    }
    else
    {
        while ((data = getc(inputPointer)) != EOF)
        {
            if ((data >= 'A' and data <= 'Z') or (data >= 'a' and data <= 'z') or (data >= '0' and data <= '9') or (data == ' '))
            {
                String code = encodeChar(tree, data);
                
                REP(i, 0, code.size)
                    fputc(*(code.arr + i), outputPointer);

                fputs("  ", outputPointer);

                deleteString(&code);
            }
        }
        fclose(inputPointer);
        fclose(outputPointer);
    }
}