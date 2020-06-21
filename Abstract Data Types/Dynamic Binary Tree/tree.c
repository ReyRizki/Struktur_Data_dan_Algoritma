// Program		: tree.c
// Author		: Rey Rizki
// Description	: Dynamic Binary Tree ADT body implementation file
// Date			: Tuesday, 12 May 2020
// Version		: V 2.0
// Compiler		: gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04)

#include "tree.h"
#include <ctype.h>

#ifndef MACROS
#define MACROS

#define u unsigned
#define s short
#define ll long long
#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define REPR(i, a, b) for (int i = (a - 1); i >= (b); i--)

#endif

// ==============
//  CONSTRUCTORS
// ==============

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
address createNode(dataType data)
{
    address node = (Node *)malloc(sizeof(Node));

    node->data = data;
    node->child[left] = NULL;
    node->child[right] = NULL;

    return node;
}

// ==========
//  MUTATORS
// ==========

// Description		: Procedure to set the data field of a node
// Initial State	: Data field is not setted yet
// Final State		: Data field is setted
void setNodeData(address *node, dataType data)
{
    (*node)->data = data;
}

// Description		: Procedure to set the child field of a node with given direction (left or right)
// Initial State	: Child field is not setted yet
// Final State		: Child field is setted
void setNodeChild(address *node, char direction, address child)
{
    (*node)->child[direction] = child;
}

// Description		: Procedure to insert a child to a subtree
// Initial State	: Child is not inserted yet
// Final State		: Child is inserted
void insertNode(Tree *tree, address *node, dataType parentData, char index, dataType data)
{
    address parentNode = searchNode(*node, parentData);

    if (isTreeEmpty(*tree))
        tree->root = createNode(data);
    else if (not isTreeEmpty(*tree) and parentData == 0 and not findNode(tree->root, data))
    {
        address newRoot = createNode(data);
        newRoot->child[index] = tree->root;
        tree->root = newRoot;
    }
    else if (parentNode == NULL)
        printf("Node with data %c isn't exist\n", parentData);
    else if (parentNode->child[index] != NULL)
        printf("Node is already exist\n");
    else if (findNode(*node, data))
        printf("Node with data %c is already exist\n", data);
    else
        parentNode->child[index] = createNode(data);
}

// ===========
//  ACCESSORS
// ===========

// Description		: Function to get data field of a node
// Input			: A node
// Output			: Data of the node
dataType getNodeData(address node)
{
    return node->data;
}

// Description		: Function to get parent node of a node
// Input			: A node
// Output			: Parent of the node
address getNodeParent(address node, address key, address parent)
{
    if (node == NULL)
        return NULL;
    else if (node == key)
        return parent;
    else
    {
        address result = getNodeParent(node->child[left], key, node);
        if (result != NULL)
            return result;

        return getNodeParent(node->child[right], key, node);
    }
}

// Description		: Function to get child of a node
// Input			: A node, and direction of child (left or right)
// Output			: Left or right child of a node
address getNodeChild(address node, char direction)
{
    return node->child[direction];
}

// Description		: Function to get level of a node recursively
// Input			: A node
// Output			: Level of the node
u int nodeLevel(Tree tree, address node)
{
    return isNodeRoot(tree, node) ? 0 : nodeLevel(tree, getNodeParent(tree.root, node, NULL)) + 1;
}

// Description		: Function to get an order of a node recursively
// Input			: A node
// Output			: Order of the node
int nodeOrder(address node)
{
    return node == NULL ? -1 : max(nodeOrder(node->child[left]), nodeOrder(node->child[right])) + 1;
}

// Description		: Function to get the depth of a tree (by calling nodeOrder and tree.root as the parameter)
// Input			: A tree
// Output			: Depth of the tree
int treeDepth(Tree tree)
{
    return nodeOrder(tree.root);
}

// Description		: Function to get degree of a node (number of childs)
// Input			: A node
// Output			: Degree of the node
u int nodeDegree(address node)
{
    return (getNodeChild(node, left) != NULL) + (getNodeChild(node, right) != NULL);
}

// Description		: Function to get degree of a tree (maximum numbers of childs in a tree)
// Input			: A tree
// Output			: Degree of a tree
u int treeDegree(Tree tree)
{
    u int result = 0;

    treeDegreeUtil(tree.root, &result);

    return result;
}

// Description		: Utility procedure for treeDegree()
// Initial State	: Node is root, result = 0
// Final State		: Result is filled with tree's degree
void treeDegreeUtil(address node, u int *result)
{
    if (node != NULL)
    {
        *result = max(*result, nodeDegree(node));
        treeDegreeUtil(node->child[left], result);
        treeDegreeUtil(node->child[right], result);
    }
}

// Description		: Procedure to visit a node in a tree (In this, program it will print the data of the node)
// Initial State	: The node hasn't visited yet
// Final State		: The node has been visited
void visitNode(Node node)
{
    // if (node.data != 0)
        printf("%c ", node.data);
}

// Description		: Procedure to traverse a tree by preorder
// Initial State	: The tree isn't traversed yet
// Final State		: All nodes has been visited
void preorder(address node)
{
    if (node != NULL)
    {
        visitNode(*node);
        preorder(node->child[left]);
        preorder(node->child[right]);
    }
}

// Description		: Procedure to traverse a tree by inorder
// Initial State	: The tree isn't traversed yet
// Final State		: All nodes has been visited
void inorder(address node)
{
    if (node != NULL)
    {
        inorder(node->child[left]);
        visitNode(*node);
        inorder(node->child[right]);
    }
}

// Description		: Procedure to traverse a tree by postorder
// Initial State	: The tree isn't traversed yet
// Final State		: All nodes has been visited
void postorder(address node)
{
    if (node != NULL)
    {
        postorder(node->child[left]);
        postorder(node->child[right]);
        visitNode(*node);
    }
}

// Description		: Procedure to traverse a tree by levelorder
// Initial State	: Tree tree isn't traversed yet
// Final State		: All nodes has been visited
void levelorder(address node)
{
    u int depth = nodeOrder(node);

    REP(i, 0, depth + 1)
        levelorderUtil(node, i);
}

// Description		: Utility procedure for levelorder by visiting each nod in given level
// Initial State	: The given level hasn't been visited yet
// Final State		: The given level has been visited
void levelorderUtil(address node, u int level)
{
    if (node == NULL)
        return;

    if (level == 0)
        visitNode(*node);
    else if (level > 0)
    {
        levelorderUtil(node->child[left], level - 1);
        levelorderUtil(node->child[right], level - 1);
    }
}

// Description		: Function to search a data in a tree
// Input			: Tree root, data to be searched
// Output			: Address of the data (NULL if data isn't exist)
address searchNode(address node, dataType data)
{
    if (node == NULL or node->data == data)
        return node;

    address result = searchNode(node->child[left], data);
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
// Output			: 1 if empty, 0 if not empty
bool isTreeEmpty(Tree tree)
{
    return tree.root == NULL;
}

// Description		: Function to chek wether a node is a root or not
// Input			: A node of a tree
// Output			: 1 if root, 0 if not
bool isNodeRoot(Tree tree, address node)
{
    return getNodeParent(tree.root, node, NULL) == NULL;
    // return node.parent == NULL;
}

// Description		: Function to check whether a node is a leaf of not
// Input			: A node of a tree
// Output			: 1 if leaf, 0 if not
bool isNodeLeaf(Node node)
{
    return node.child[left] == NULL and node.child[right] == NULL;
}

// Description		: Function to find a node in a tree with the given data
// Input			: Tree root, data
// Output			: 1 if found, 0 if not
bool findNode(address node, dataType data)
{
    return searchNode(node, data) != NULL;
}

// =============
//  DESTRUCTORS 
// =============

// Description		: Procedure to delete a tree (using postorder traversal)
// Initial State	: Tree is not empty
// Final State		: Tree is empty
void deleteTree(Tree *tree, address *node)
{
    if (*node != NULL and not isTreeEmpty(*tree))
    {
        if (isNodeLeaf(**node))
            deleteNode(tree, node);
        else
        {
            deleteTree(tree, &((*node)->child[left]));
            deleteTree(tree, &((*node)->child[right]));
            deleteNode(tree, node);
        }
    }
}

// Description		: Procedure to delete a node if the node is a leaf
// Initial State	: Node isn't NULL
// Final State		: Node is NULL and dealocated
void deleteNode(Tree *tree, address *node)
{
    if (isNodeLeaf(**node))
    {
        if (isNodeRoot(*tree, *node))
            tree->root = NULL;
        else
        {
            address parent = getNodeParent(tree->root, *node, NULL);
            parent->child[parent->child[right] == *node] = NULL;
        }

        free(*node);
        *node = NULL;
    }
    else
        printf("The node isn't a leaf\n");
}

// =======
//  OTHER 
// =======

// Description		: Function to get maximum value of two integers
// Input			: 2 integers
// Output			: Maximum value of those integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}
