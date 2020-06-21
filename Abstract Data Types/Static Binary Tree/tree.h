// Program		: tree.h
// Author		: Rey Rizki
// Description	: Static Binary Tree ADT header file
// Date			: Sunday, 21 June 2020
// Version		: V 1.0
// Compiler		: gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04)

#ifndef TREE_H_
#define TREE_H_

#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#ifndef MACROS
#define MACROS

#define u unsigned
#define s short
#define ll long long
#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define REPR(i, a, b) for (i = (a-1); i >= (b); i--)

#endif

#define MAXLEVEL 2

enum child { left, right };

typedef char dataType;

typedef struct binaryTree
{
    u int capacity;
    dataType *node;
} Tree;

// =============
//  CONSTRUCTOR 
// =============

// Description		: Function to construct an empty tree
// Input			: -
// Output			: An empty tree
Tree createTree();

// =========
//  MUTATOR 
// =========

// Description		: Procedure to insert a node to a node's child in a tree. If the tree is empty, then the node inserted to the root
// Initial State	: Tree is exist
// Final State		: A node is inserted to a node's child
void insertNode(Tree *tree, int index, bool child, dataType data);

// ===========
//  ACCESSORS  
// ===========

// Description		: Function to get the capacity field of a tree
// Input			: A tree
// Output			: Capacity of a tree
u int getCapacity(Tree tree);

// Description		: Function to get parent of a node in a tree
// Input			: Tree with specific index
// Output			: Parent of the node
int getNodeParent(Tree tree, int index);

// Description		: Function to get a left child or right child of a node
// Input			: Tree with specific index and left or right child
// Output			: Left or right child of the node
int getNodeChild(Tree tree, int index, bool child);

// ============
//  VALIDATORS 
// ============

// Description		: Function to check if a node is exist or not
// Input			: Tree with specific index (node)
// Output			: 1 if exist, 0 if not
bool isNodeExist(Tree tree, int index);

// Description		: Functio to check if a node is empty or not
// Input			: Tree with specific index(node)
// Output			: 1 if empty, 0 if not
bool isNodeEmpty(Tree tree, int index);

// Description		: Function to check if a tree is empty or not
// Input			: A tree
// Output			: 1 if the tree is empty, 0 if not
bool isTreeEmpty(Tree tree);

// Description		: Function to check if a tree is full or not
// Input			: A tree
// Output			: 1 if the tree is full, 0 if not
bool isTreeFull(Tree tree);

#endif