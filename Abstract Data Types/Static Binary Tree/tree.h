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

// ==========
//  MUTATORS 
// ==========

// Description		: Procedure to insert a node to a node's child in a tree. If the tree is empty, then the node inserted to the root
// Initial State	: Tree is exist
// Final State		: A node is inserted to a node's child
void insertNode(Tree *tree, int index, bool child, dataType data);

// Description		: Procedure to empty a node of a tree
// Initial State	: Node is not empty
// Final State		: Node is empty
void emptyNode(Tree *tree, int index);

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

// Description		: Function to get a node data
// Input			: Tree with specific index
// Output			: Data of the node
dataType getNodeData(Tree tree, int index);

// Description		: Function to get level of a node
// Input			: Tree with specific index
// Output			: Level of the node
int nodeLevel(Tree tree, int index);

// Description		: Function to get order of a node
// Input			: Tree with specific index
// Output			: Order of the node
int nodeOrder(Tree tree, int index);

// Description		: Function to get depth of a tree
// Input			: A tree
// Output			: Depth of a tree
int treeDepth(Tree tree);

// Description		: Function to get degree of a node
// Input			: Tree with specific index
// Output			: Degree of a node
u char nodeDegree(Tree tree, int index);

// Description		: Function to get degree of a tree
// Input			: A tree
// Output			: Degree of a tree
u char treeDegree(Tree tree);

// Description		: Procedure to visit a node (utility for traversal)
// Initial State	: Tree is exist
// Final State		: Node is printed
void visitNode(Tree tree, int index);

// Description		: Procedure to traverse a tree with preorder
// Initial State	: Tree is exist
// Final State		: Tree is printed
void preorder(Tree tree, int index);

// Description		: Procedure to traverse a tree with inorder
// Initial State	: Tree is exist
// Final State		: Tree is printed
void inorder(Tree tree, int index);

// Description		: Procedure to traverse a tree with postorder
// Initial State	: Tree is exist
// Final State		: Tree is printed
void postorder(Tree tree, int index);

// Description		: Procedure to print nodes of a tree with levelorder traversal
// Initial State	: Tree is exist
// Final State		: Tree is printed
void levelorder(Tree tree);

// Description		: Function to search a data in a tree
// Input			: Tree with a key
// Output			: Index of the node with the key
int searchNode(Tree tree, dataType key);

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

// Description		: Function to check if a node is empty or not
// Input			: A tree with specific index
// Output			: 1 if the node is leaf, 0 if not
bool isNodeLeaf(Tree tree, int index);

// Description		: Function to find a node in a tree
// Input			: Tree with a given key
// Output			: 1 if found, 0 if not found
bool findNode(Tree tree, dataType key);

// ============
//  DESTRUCTOR 
// ============

// Description		: Procedure to delete a tree
// Initial State	: Tree is exist
// Final State		: Tree is not exist
void deleteTree(Tree *tree);

// =========
//  UTILITY 
// =========

// Description		: Function to get max value of two value
// Input			: 2 values
// Output			: Maximum value
int max(int a, int b);

#endif