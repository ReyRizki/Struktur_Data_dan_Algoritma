// Program		: tree.c
// Author		: Rey Rizki
// Description	: Static Binary Tree ADT body implementation file
// Date			: Sunday, 21 June 2020
// Version		: V 1.0
// Compiler		: gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04)

#include "tree.h"

#ifndef TREE_C_
#define TREE_C_

#include <stdio.h>
#include <stdlib.h>
#include <iso646.h>

#ifndef MACROS
#define MACROS

#define u unsigned
#define s short
#define ll long long
#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define REPR(i, a, b) for (i = (a-1); i >= (b); i--)

#endif

// =============
//  CONSTRUCTOR 
// =============

// Description		: Function to construct an empty tree
// Input			: -
// Output			: An empty tree
Tree createTree()
{
    Tree tree;

    tree.capacity = (u int) pow(2, MAXLEVEL + 1) - 1;
    tree.node = (dataType *) malloc (tree.capacity * sizeof(dataType));

    REP(i, 0, tree.capacity)
        tree.node[i] = '\0';

    return tree;
}

// Description		: Procedure to insert a node to a node's child in a tree. If the tree is empty, then the node inserted to the root
// Initial State	: Tree is exist
// Final State		: A node is inserted to a node's child
void insertNode(Tree *tree, int index, bool child, dataType data)
{
    if (isTreeEmpty(*tree))
        tree->node[0] = data;
    else if (isTreeFull(*tree))
        printf("Tree is full\n");
    else
    {
        int target = getNodeChild(*tree, index, child);

        if (isNodeExist(*tree, target))
        {
            if (isNodeEmpty(*tree, target))
                tree->node[target] = data;
            else
                printf("Node is not empty\n");
        }
        else
            printf("Node is not exist\n");
    }
}

// ===========
//  ACCESSORS 
// ===========

// Description		: Function to get the capacity field of a tree
// Input			: A tree
// Output			: Capacity of a tree
u int getCapacity(Tree tree)
{
    return tree.capacity;
}

// Description		: Function to get parent of a node in a tree
// Input			: Tree with specific index
// Output			: Parent of the node
int getNodeParent(Tree tree, int index);

// Description		: Function to get a left child or right child of a node
// Input			: Tree with specific index and left or right child
// Output			: Left or right child of the node
int getNodeChild(Tree tree, int index, bool child)
{
    if (not isNodeExist(tree, index) and isNodeEmpty(tree, index))
        return -1;

    u int result = 2 * index + 1 + child;
    return (result >= getCapacity(tree)) ? -1 : result;
}

// ============
//  VALIDATORS 
// ============

// Description		: Function to check if a node is exist or not
// Input			: Tree with specific index (node)
// Output			: 1 if exist, 0 if not
bool isNodeExist(Tree tree, int index)
{
    return index > -1 and index < tree.capacity;
}

// Description		: Functio to check if a node is empty or not
// Input			: Tree with specific index(node)
// Output			: 1 if empty, 0 if not
bool isNodeEmpty(Tree tree, int index)
{
    if (not isNodeExist(tree, index))
        return 0;

    return tree.node[index] == '\0';
}

// Description		: Function to check if a tree is empty or not
// Input			: A tree
// Output			: 1 if the tree is empty, 0 if not
bool isTreeEmpty(Tree tree)
{
    return tree.node[0] == '\0';
}

// Description		: Function to check if a tree is full or not
// Input			: A tree
// Output			: 1 if the tree is full, 0 if not
bool isTreeFull(Tree tree)
{
    REP(i, 0, getCapacity(tree))
        if (tree.node[i] == '\0')
            return 0;
    
    return 1;
}

#endif