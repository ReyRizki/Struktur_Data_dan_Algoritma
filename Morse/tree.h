// Program		: tree.h
// Author		: Rey Rizki
// Description	: Dynamic Binary Tree ADT header file
// Date			: Thursday, 30 April 2020
// Version		: V 1.0
// Compiler		: gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04)

#ifndef TREE_H_
#define TREE_H_

#include "string.h"
#include <stdbool.h>
#include <iso646.h>
#include "dynamicStack.h"

#ifndef MACROS
#define MACROS

#define u unsigned
#define s short
#define ll long long
#define REP(i, a, b) for (i = (a); i < (b); i++)
#define REPR(i, a, b) for (i = (a-1); i >= (b); i--)

#endif

enum child { left, right };

typedef char dataType;
typedef struct TreeNode *TreeNodeAddress;

typedef struct TreeNode
{
    dataType data;
    TreeNodeAddress child[2], parent;
} TreeNode;

typedef struct
{
    TreeNodeAddress root;
} Tree;

// ============= 
//  CONSTRUCTOR
// =============

// Description		: Function to create an empty tree
// Input			: -
// Output			: An empty tree
Tree createTree();

// Description		: Function to create a new node
// Input			: A data for the new node
// Output			: A new node
TreeNodeAddress createTreeNode(dataType data);

// ==========
//  MUTATORS 
// ==========

// Description		: Procedure to insert a child to a subtree
// Initial State	: Child is not inserted yet
// Final State		: Child is inserted
void insertTreeNode(TreeNodeAddress *node, char index, dataType data);

// ===========
//  ACCESSORS 
// ===========

// Description		: Procedure to visit a node in a tree (In this, program it will print the data of the node)
// Initial State	: The node hasn't visited yet
// Final State		: The node has been visited
void visitTreeNode(TreeNode node);

// Description		: Procedure to traverse a tree by inorder
// Initial State	: The tree isn't traversed yet
// Final State		: All nodes has been visited
void inorder(TreeNodeAddress node);

// Description		: Function to search a data in a tree
// Input			: Tree root, data to be searched
// Output			: Address of the data (NULL if data isn't exist)
TreeNodeAddress searchNode(TreeNodeAddress node, dataType data);

// ============
//  VALIDATORS 
// ============

// Description		: Function to check wether a tree is emtpy or not
// Input			: A tree
// Output			: 1 if emtpy, 0 if not empty
bool isTreeEmpty(Tree tree);

// Description		: Function to check wether a node is a root or not
// Input			: A node of a tree
// Output			: 1 if root, 0 if not
bool isNodeRoot(TreeNode node);

// ===============
//  MORSE MODULES
// ===============

// Description		: Procedure to generate a morse tree
// Initial State	: The tree is empty
// Final State		: Morse Tree is generated
void generateMorseTree(Tree *tree);

// Description		: Function to generate a stack of a given node address (reverse it)
// Input			: Node address
// Output			: A stack of morse code
Stack generateCode(TreeNodeAddress node);

// Description		: Function to encode a character to a morse code
// Input			: A morse tree, a data to be encoded
// Output			: A morse code
String encodeChar(Tree tree, char data);

// Description		: Function to encode a string to a morse code
// Input			: A morse tree, a string to be encoded
// Output			: A morse code
String encodeString(Tree tree, char *string);

// Description		: Function to decode a morse code to a string
// Input			: A morse tree and morse code
// Output			: A string
String decode(Tree tree, char *code);

// Description		: Procedure to encode a text file to morse code and put it in a text file
// Initial State	: The input file is filled with text
// Final State		: The output file is filled with morse code from input file
void encodeFile(Tree tree, char *input, char *output);

#endif