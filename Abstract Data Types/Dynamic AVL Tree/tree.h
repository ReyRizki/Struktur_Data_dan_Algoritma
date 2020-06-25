// Program		: tree.h
// Author		: Rey Rizki
// Description	: Dynamic Binary Search Tree header file
// Date			: Tuesday, 19 May 2020
// Version		: V 1.0
// Compiler		: gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04)

#ifndef TREE_H_
#define TREE_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <iso646.h>

#ifndef MACROS
#define MACROS

#define u unsigned
#define s short
#define ll long long
#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define REPR(i, a, b) for (int i = (a-1); i >= (b); i--)

#endif

enum child { left, right };

typedef int dataType;
typedef struct Node *address;

typedef struct Node
{
    dataType data;
    address child[2];
    int height;
} Node;

typedef address TreeRoot;

// ==============
//  CONSTRUCTORS 
// ==============

// Description		: Function to create an empty tree
// Input			: -
// Output			: An empty tree
TreeRoot createTree();

// Description		: Function to create a new node
// Input			: A data for the new node
// Output			: A new node
address createNode(dataType data);

// ==========
//  MUTATORS 
// ==========

// Description		: Procedure to set the data field of a node
// Initial State	: Data field is not setted yet
// Final State		: Data field is setted
void setNodeData(address *node, dataType data);

// Description		: Procedure to set the child field of a node with given direction (left or right)
// Initial State	: Child field is not setted yet
// Final State		: Child field is setted
void setNodeChild(address *node, char direction, address child);

// Description		: Procedure to insert a child to a subtree
// Initial State	: Child is not inserted yet
// Final State		: Child is inserted
address insertNode(TreeRoot root, dataType data);

// Description		: Procedure to rotate a tree using left rotate
// Initial State	: A tree with three nodes is exist
// Final State		: The tree is roteted left
// Reference        : https://www.geeksforgeeks.org/avl-tree-set-1-insertion/
address leftRotate(address x);

// Description		: Procedure to rotate a tree using right rotate
// Initial State	: A tree with three nodes is exist
// Final State		: The tree is roteted right
// Reference        : https://www.geeksforgeeks.org/avl-tree-set-1-insertion/
address rightRotate(address y);

// ===========
//  ACCESSORS 
// ===========

// Description		: Function to get data field of a node
// Input			: A node
// Output			: Data of the node
dataType getNodeData(address node);

// Description		: Function to get parent node of a node
// Input			: A node
// Output			: Parent of the node
address getNodeParent(address node);

// Description		: Function to get child of a node
// Input			: A node, and direction of child (left or right)
// Output			: Left or right child of a node
address getNodeChild(address node, char direction);

// Description		: Function to get level of a node recursively
// Input			: A node
// Output			: Level of the node
u int nodeLevel(address node);

// Description		: Function to get an order of a node recursively
// Input			: A node
// Output			: Order of the node
int nodeOrder(address node);

// Description		: Function to get the depth of a tree (by calling nodeOrder and tree.root as the parameter)
// Input			: A tree
// Output			: Depth of the tree
int treeDepth(TreeRoot root);

// Description		: Function to get degree of a node (number of childs)
// Input			: A node
// Output			: Degree of the node
u int nodeDegree(address node);

// Description		: Function to get degree of a tree (maximum numbers of childs in a tree)
// Input			: A tree
// Output			: Degree of a tree
u int treeDegree(TreeRoot root);

// Description		: Utility procedure for treeDegree()
// Initial State	: Node is root, result = 0
// Final State		: Result is filled with tree's degree
void treeDegreeUtil(address node, u int *result);

// Description		: Procedure to visit a node in a tree (In this, program it will print the data of the node)
// Initial State	: The node hasn't visited yet
// Final State		: The node has been visited
void visitNode(Node node);

// Description		: Procedure to traverse a tree by preorder
// Initial State	: The tree isn't traversed yet
// Final State		: All nodes has been visited
void preorder(address node);

// Description		: Procedure to traverse a tree by inorder
// Initial State	: The tree isn't traversed yet
// Final State		: All nodes has been visited
void inorder(address node);

// Description		: Procedure to traverse a tree by postorder
// Initial State	: The tree isn't traversed yet
// Final State		: All nodes has been visited
void postorder(address node);

// Description		: Procedure to traverse a tree by levelorder
// Initial State	: Tree tree isn't traversed yet
// Final State		: All nodes has been visited
void levelorder(address node);

// Description		: Utility procedure for levelorder by visiting each nod in given level
// Initial State	: The given level hasn't been visited yet
// Final State		: The given level has been visited
void levelorderUtil(address node, u int level);

// Description		: Function to search a data in a tree
// Input			: Tree root, data to be searched
// Output			: address of the data (NULL if data isn't exist)
address searchNode(address node, dataType data);

// Description		: Function to get the node with minimum value in the tree
// Input			: Tree root
// Output			: Node with minimum value
address minValueNode(TreeRoot root);

// Description		: A utility function to get balance of the node, used for AVL tree in insertion and deletion
// Input			: Address of a node
// Output			: Left child order - Right child order
// Reference        : https://www.geeksforgeeks.org/avl-tree-set-1-insertion/
int getBalance(address node);

// ============
//  VALIDATORS 
// ============

// Description		: Function to check wether a tree is emtpy or not
// Input			: A tree
// Output			: 1 if emtpy, 0 if not empty
bool isTreeEmpty(TreeRoot root);

// Description		: Function to check wether a node is a root or not
// Input			: A node of a tree
// Output			: 1 if root, 0 if not
bool isNodeRoot(Node node);

// Description		: Function to check whether a node is a leaf of not
// Input			: A node of a tree
// Output			: 1 if leaf, 0 if not
bool isNodeLeaf(Node node);

// Description		: Function to find a node in a tree with the given data
// Input			: Tree root, data
// Output			: 1 if found, 0 if not
bool findNode(address node, dataType data);

// =============
//  DESTRUCTORS 
// =============

// Description		: Procedure to delete a tree (using postorder traversal)
// Initial State	: Tree is not empty
// Final State		: Tree is empty
void deleteTree(TreeRoot *root);

// Description		: Procedure to delete a node in Binary Search Tree
// Initial State	: Node is exist
// Final State		: Node is deleted
address deleteNode(TreeRoot root, dataType data);

// =======
//  OTHER 
// =======

// Description		: Function to get maximum value of two integers
// Input			: 2 integers
// Output			: Maximum value of those integers
int max(int a, int b);

#endif