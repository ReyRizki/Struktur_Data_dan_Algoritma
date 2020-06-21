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

// ==========
//  MUTATORS 
// ==========

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

// Description		: Procedure to empty a node of a tree
// Initial State	: Node is not empty
// Final State		: Node is empty
void emptyNode(Tree *tree, int index)
{
    if (not isNodeEmpty(*tree, index))
    {
        if (isNodeLeaf(*tree, index))
            tree->node[index] = '\0';
        else
            printf("Node is not a leaf\n");
    }
    else
        printf("Node is already empty\n");
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
int getNodeParent(Tree tree, int index)
{
    return (not isNodeExist(tree, index) or isNodeEmpty(tree, index) or index == 0) ? -1 : (index - 1) / 2;
}

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

// Description		: Function to get a node data
// Input			: Tree with specific index
// Output			: Data of the node
dataType getNodeData(Tree tree, int index)
{
    return (isNodeExist(tree, index) ? tree.node[index] : '\0');
}

// Description		: Function to get level of a node
// Input			: Tree with specific index
// Output			: Level of the node
int nodeLevel(Tree tree, int index)
{
    return (not isNodeExist(tree, index) or isNodeEmpty(tree, index) ? -1 : nodeLevel(tree, getNodeParent(tree, index)) + 1);
}

// Description		: Function to get order of a node
// Input			: Tree with specific index
// Output			: Order of the node
int nodeOrder(Tree tree, int index)
{
    return (isNodeEmpty(tree, index) ? -1 : (isNodeLeaf(tree, index) ? 0 : max(nodeOrder(tree, getNodeChild(tree, index, left)), nodeOrder(tree, getNodeChild(tree, index, right))) + 1));
}

// Description		: Function to get depth of a tree
// Input			: A tree
// Output			: Depth of a tree
int treeDepth(Tree tree)
{
    return nodeOrder(tree, 0);
}

// Description		: Function to get degree of a node
// Input			: Tree with specific index
// Output			: Degree of a node
u char nodeDegree(Tree tree, int index)
{
    return (not isNodeEmpty(tree, getNodeChild(tree, index, left))) + (not isNodeEmpty(tree, getNodeChild(tree, index, right)));
}

// Description		: Function to get degree of a tree
// Input			: A tree
// Output			: Degree of a tree
u char treeDegree(Tree tree)
{
    u char result = 0;

    REP(i, 0, getCapacity(tree))
        result = max(result, nodeDegree(tree, i));

    return result;
}

// Description		: Procedure to visit a node (utility for traversal)
// Initial State	: Tree is exist
// Final State		: Node is printed
void visitNode(Tree tree, int index)
{
    if (isNodeExist(tree, index) and not isNodeEmpty(tree, index))
        printf("%c ", getNodeData(tree, index));
}

// Description		: Procedure to traverse a tree with preorder
// Initial State	: Tree is exist
// Final State		: Tree is printed
void preorder(Tree tree, int index)
{
    if (not isNodeEmpty(tree, index))
    {
        visitNode(tree, index);
        preorder(tree, getNodeChild(tree, index, left));
        preorder(tree, getNodeChild(tree, index, right));
    }
}

// Description		: Procedure to traverse a tree with inorder
// Initial State	: Tree is exist
// Final State		: Tree is printed
void inorder(Tree tree, int index)
{
    if (not isNodeEmpty(tree, index))
    {
        inorder(tree, getNodeChild(tree, index, left));
        visitNode(tree, index);
        inorder(tree, getNodeChild(tree, index, right));
    }
}

// Description		: Procedure to traverse a tree with postorder
// Initial State	: Tree is exist
// Final State		: Tree is printed
void postorder(Tree tree, int index)
{
    if (not isNodeEmpty(tree, index))
    {
        postorder(tree, getNodeChild(tree, index, left));
        postorder(tree, getNodeChild(tree, index, right));
        visitNode(tree, index);
    }
}

// Description		: Procedure to print nodes of a tree with levelorder traversal
// Initial State	: Tree is exist
// Final State		: Tree is printed
void levelorder(Tree tree)
{
    REP(i, 0, getCapacity(tree))
        visitNode(tree, i);
}

// Description		: Function to search a data in a tree
// Input			: Tree with a key
// Output			: Index of the node with the key
int searchNode(Tree tree, dataType key)
{
    REP(i, 0, getCapacity(tree))
        if (getNodeData(tree, i) == key)
            return i;

    return -1;
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
    return (isNodeExist(tree, index) ? tree.node[index] == 0 : 1);
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

// Description		: Function to check if a node is empty or not
// Input			: A tree with specific index
// Output			: 1 if the node is leaf, 0 if not
bool isNodeLeaf(Tree tree, int index)
{
    return nodeDegree(tree, index) == 0;
}

// Description		: Function to find a node in a tree
// Input			: Tree with a given key
// Output			: 1 if found, 0 if not found
bool findNode(Tree tree, dataType key)
{
    return searchNode(tree, key) != -1;
}

// ============
//  DESTRUCTOR 
// ============

// Description		: Procedure to delete a tree
// Initial State	: Tree is exist
// Final State		: Tree is not exist
void deleteTree(Tree *tree)
{
    tree->capacity = 0;
    free(tree->node);
    tree->node = NULL;
}

// =========
//  UTILITY 
// =========

// Description		: Function to get max value of two value
// Input			: 2 values
// Output			: Maximum value
int max(int a, int b)
{
    return (a >= b ? a : b);
}

#endif