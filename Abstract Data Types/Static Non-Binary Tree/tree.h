// Program		: tree.h
// Author		: Rey Rizki
// Description	: Static Non-Binary Tree ADT header file
// Date			: Thursday, 23 April 2020
// Version		: V 1.0
// Compiler		: gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04)

#ifndef TREE_H_
#define TREE_H_

#include <stdio.h>
#include <iso646.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef MACROS
#define MACROS

#define u unsigned
#define s short
#define ll long long
#define REP(i, a, b) for (i = (a); i < (b); i++)
#define REPR(i, a, b) for (i = (a - 1); i >= (b); i--)

#endif

typedef char dataType; // change this for the data type

// struct for a node in Tree struct
typedef struct
{
    dataType data;   // data that stored in a node
    int firstChild;  // the first child of the node (-1 if doesn't have, leaf actually)
    int nextSibling; // the next sibling of the node (-1 if doesn't have)
    int parent;      // the parent of the node (-1 if doesn't have, root actually)
} Node;

// the tree struct
typedef struct
{
    Node *nodes;    // array of the nodes
    u int size;     // the number of used indexes in array
    u int capacity; // the number of maximum index (-1)
} Tree;

// ==============
//  CONSTRUCTORS
// ==============

// Description		: Function to construct a tree
// Input			: Capacity of a tree
// Output			: Tree with given capacity
Tree createTree(u int capacity);

// Description		: Function to create a node
// Input			: Data of the node, parent of the node (-1 if the node is root)
// Output			: The node with given parameters
Node createNode(dataType data, int parent);

// ===========
//  ACCESSORS
// ===========

// Description		: Function to get the capacity field of a tree
// Input			: Tree
// Output			: Tree's capacity
u int getTreeCapacity(Tree tree);

// Description		: Function to get the size field of a tree
// Input			: Tree
// Output			: Tree's size
u int getTreeSize(Tree tree);

// Description		: Function to get the nodes of the tree
// Input			: Tree
// Output			: Tree's nodes
Node *getTreeNodes(Tree tree);

// Description		: Function to get a node of a tree by given index
// Input			: Tree, index
// Output			: The node
Node getNode(Tree tree, u int index);

// Description		: Function to get an address of a node in a tree by given index (index is in the range of 0 <= x < size)
// Input			: Tree, index
// Output			: The node's address
Node *getNodeAddress(Tree tree, u int index);

// Description		: Function to get the data field of a node
// Input			: Node
// Output			: Data
dataType getNodeData(Node node);

// Description		: Function to get the index of a node's first child
// Input			: Node
// Output			: Index of node's first child
int getNodeFirstChild(Node node);

// Description		: Function to get the index of a node's next sibling
// Input			: Node
// Output			: Index of node's next sibling
int getNodeNextSibling(Node node);

// Description		: Function to get the index of a node's parent
// Input			: Node
// Output			: Index of node's parent
int getNodeParent(Node node);

// Description		: Function to get the root index of a tree
// Input			: Tree
// Output			: Root index of the tree
u int treeRoot(Tree tree);

// Description		: Function to get the last child index of a node
// Input			: Tree, index of a parent
// Output			: Index of the last child of the node (-1 if doesn't have any)
int lastChild(Tree tree, u int index);

// Description		: Function to get level of a node in tree
// Input			: Tree, index of the node
// Output			: Level of the given index
u int nodeLevel(Tree tree, u int index);

// Description		: Function to get order of a node in tree
// Input			: Tree, index of the node
// Output			: Order of given index
u int nodeOrder(Tree tree, u int index);

// Description		: Function to get the depth of a tree (Order of the root)
// Input			: Tree
// Output			: Depth of the tree
u int treeDepth(Tree tree);

// Description		: Procedure to visit a node (In this code, the visiting is printing the node's data)
// Initial State	: The node isn't visited yet
// Final State		: The node is visited
void visitNode(Node node);

// Description		: Procedure to visit a node using breadth first search
// Initial State	: The node isn't visited yet
// Final State		: The node is visited
void bfsVisitNode(Tree tree, int index, u int level);

// Description		: Procedure to traverse a tree by preorder recursively
// Initial State	: The tree hasn't traversed yet
// Final State		: The tree has been traversed
void preorder(Tree tree, int index);

// Description		: Procedure to traverse a tree by inorder recursively
// Initial State	: The tree hasn't traversed yet
// Final State		: The tree has been traversed
void inorder(Tree tree, int index);

// Description		: Procedure to traverse a tree by postorder recursively
// Initial State	: The tree hasn't traversed yet
// Final State		: The tree has been traversed
void postorder(Tree tree, int index);

// Description		: Procedure to traverse a tree by levelorder
// Initial State	: The tree hasn't traversed yet
// Final State		: The tree has been traversed
void levelorder(Tree tree, int index);

// Description		: Function to convert unsigned integer to integer
// Input			: Integer
// Output			: Unsigned integer
int uToInt(u int i);

// ==========
//  MUTATORS
// ==========

// Description		: Procedure to set the size of the tree
// Initial State	: Size is not setted yet
// Final State		: Size is setted
void setTreeSize(Tree *tree, u int size);

// Description		: Procedure to set a node of a tree
// Initial State	: Node is not setted yet
// Final State		: Node is setted
void setNode(Node *node, dataType data, int firstChild, int nextSibling, int parent);

// Description		: Procedure to set data field of a node
// Initial State	: Data field of node is not setted yet
// Final State		: Data field of node is setted
void setNodeData(Node *node, dataType data);

// Description		: Procedure to set first child field of a node
// Initial State	: First child field is not setted yet
// Final State		: First child is setted
void setNodeFirstChild(Node *node, int firstChild);

// Description		: Procedure to set next sibling field of a node
// Initial State	: Next sibling field is not setted yet
// Final State		: Next sibling is setted
void setNodeNextSibling(Node *node, int nextSibling);

// Description		: Procedure to set parent field of a node
// Initial State	: Parent field is not setted yet
// Final State		: Parent is setted
void setNodeParent(Node *node, int parent);

// Description		: Procedure to insert a node
// Initial State	: New node is not inserted yet
// Final State		: New node is inserted
void insertNode(Tree *tree, dataType data, int parent);

// ============
//  VALIDATORS
// ============

// Description		: Function to check if a tree is empty or not
// Input			: Tree
// Output			: 1 if empty, 0 if not
bool isTreeEmpty(Tree tree);

// Description		: Function to check if a tree is full or not
// Input			: Tree
// Output			: 1 if full, 0 if not
bool isTreeFull(Tree tree);

// Description		: Function to check if a node is a root or not
// Input			: Node
// Output			: 1 if root, 0 if not
bool isNodeRoot(Node node);

// Description		: Function to check if a node is a leaf or not
// Input			: Node
// Output			: 1 if leaf, 0 if not
bool isNodeLeaf(Node node);

// Description		: Function to check if a node is exist or not
// Input			: Node
// Output			: 1 if exist, 0 if not
bool isNodeExist(Node node);

// ============
//  DESTRUCTOR
// ============

// Description		: Procedure to delete a tree
// Initial State	: Tree isn't deleted yet
// Final State		: Tree is deleted
void deleteTree(Tree *tree);

#endif
