// Program		: tree.c
// Author		: Rey Rizki
// Description	: Dynamic Binary Search Tree ADT body implementation file
// Date			: Tuesday, 19 May 2020
// Version		: V 1.0
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
TreeRoot createTree()
{
    return NULL;
}

// Description		: Function to create a new node
// Input			: A data for the new node
// Output			: A new node
address createNode(dataType data)
{
    address node = (Node *)malloc(sizeof(Node));

    node->data = data;
    node->child[left] = node->child[right] = NULL;

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

// Description		: Procedure to set the parent field of a node
// Initial State	: Parent field is not setted yet
// Final State		: Parent field is setted
void setNodeParent(address *node, address parent)
{
    // (*node)->parent = parent;
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
// Reference        : https://www.geeksforgeeks.org/avl-tree-set-1-insertion/
void insertNode(TreeRoot *root, dataType data)
{
    // if (isTreeEmpty(*root))
    //     *root = createNode(data);
    // else if (*root != NULL)
    // {
    //     address current = *root, parent = current->parent;

    //     while (current != NULL and current->data != data)
    //     {
    //         parent = current;

    //         if (data < current->data)
    //             current = current->child[left];
    //         else if (data > current->data)
    //             current = current->child[right];
    //     }

    //     if (current == NULL)
    //     {
    //         current = createNode(data);
    //         current->parent = parent;
    //         parent->child[data > parent->data] = current;

    //         do
    //         {
    //             int balance = getBalance(current);

    //             if (balance > 1)
    //             {
    //                 if (data > current->child[left]->data)
    //                     leftRotate(&current->child[left]);
    //                 rightRotate(&current);
    //             }
    //             else if (balance < -1)
    //             {
    //                 if (data < current->child[right]->data)
    //                     rightRotate(&current->child[right]);
    //                 leftRotate(&current);
    //             }

    //             if (isNodeRoot(*current))
    //                 *root = current;
    //         } while ((current = current->parent) != NULL);
    //     }
    //     else if (data == current->data)
    //         printf("Node with data %d is already exist\n", data);
    // }
}

// Description		: Procedure to rotate a tree using left rotate
// Initial State	: A tree with three nodes is exist
// Final State		: The tree is roteted left
// Reference        : https://www.geeksforgeeks.org/avl-tree-set-1-insertion/
void leftRotate(address *node)
{
    // address x = *node, y = x->child[right], T2 = y->child[left];

    // if (not isNodeRoot(*x))
    //     x->parent->child[x->data > x->parent->data] = y;

    // y->child[left] = x;
    // y->parent = x->parent;
    // x->parent = y;
    
    // x->child[right] = T2;
    // if (T2 != NULL)
    //     T2->parent = x;

    // *node = y;
}

// Description		: Procedure to rotate a tree using right rotate
// Initial State	: A tree with three nodes is exist
// Final State		: The tree is roteted right
// Reference        : https://www.geeksforgeeks.org/avl-tree-set-1-insertion/
void rightRotate(address *node)
{
    // address y = *node, x = y->child[left], T2 = x->child[right];

    // if (not isNodeRoot(*y))
    //     y->parent->child[y->data > y->parent->data] = x;

    // x->child[right] = y;
    // x->parent = y->parent;
    // y->parent = x;

    // y->child[left] = T2;
    // if (T2 != NULL)
    //     T2->parent = y;

    // *node = x;
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

// change later
// Description		: Function to get parent node of a node
// Input			: A node
// Output			: Parent of the node
address getNodeParent(address node)
{
    // return node->parent;
}

// Description		: Function to get child of a node
// Input			: A node, and direction of child (left or right)
// Output			: Left or right child of a node
address getNodeChild(address node, char direction)
{
    return node->child[direction];
}

// change later
// Description		: Function to get level of a node recursively
// Input			: A node
// Output			: Level of the node
u int nodeLevel(address node)
{
    // return isNodeRoot(*node) ? 0 : nodeLevel(node->parent) + 1;
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
int treeDepth(TreeRoot root)
{
    return nodeOrder(root);
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
u int treeDegree(TreeRoot root)
{
    u int result = 0;

    treeDegreeUtil(root, &result);

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
    printf("%d ", node.data);
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
    return (node == NULL or node->data == data) ? node : searchNode(node->child[node->data < data], data);
}

// Description		: Function to get the node with minimum value in the tree
// Input			: Tree root
// Output			: Node with minimum value;
address minValueNode(TreeRoot root)
{
    address current = root;

    while (current and current->child[left] != NULL)
        current = current->child[left];
    
    return current;
}

// Description		: A utility function to get balance of the node, used for AVL tree in insertion and deletion
// Input			: Address of a node
// Output			: Left child order - Right child order
int getBalance(address node)
{
    return nodeOrder(node->child[left]) - nodeOrder(node->child[right]);
}

// ============
//  VALIDATORS
// ============

// Description		: Function to check wether a tree is emtpy or not
// Input			: A tree
// Output			: 1 if empty, 0 if not empty
bool isTreeEmpty(TreeRoot root)
{
    return root == NULL;
}

// change later
// Description		: Function to chek wether a node is a root or not
// Input			: A node of a tree
// Output			: 1 if root, 0 if not
bool isNodeRoot(Node node)
{
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
void deleteTree(TreeRoot *root)
{
    while(not isTreeEmpty(*root))
        deleteNode(root, (*root)->data);
}

// Description		: Procedure to delete a node in Binary Search Tree
// Initial State	: Node is exist
// Final State		: Node is deleted
void deleteNode(TreeRoot *root, dataType data)
{   
    // address node = searchNode(*root, data);

    // if (node != NULL)
    // {
    //     address temp;

    //     if (node->child[left] != NULL and node->child[right] != NULL)
    //     {
    //         temp = minValueNode(node->child[right]);
    //         node->data = temp->data;
    //         deleteNode(&temp, temp->data);
    //     }
    //     else
    //     {
    //         address current = node->parent;

    //         temp = node->child[node->child[left] == NULL];

    //         if (node->parent != NULL)
    //             node->parent->child[node->data > node->parent->data] = temp;

    //         if (temp != NULL)
    //         {
    //             temp->parent = node->parent;
    //             node->child[temp->data == node->child[right]->data] = NULL;
    //         }

    //         if (isNodeLeaf(**root))
    //             *root = NULL;

    //         free(node);
    //         node = NULL;

    //         if (*root != NULL)
    //         {
    //             while (current != NULL)
    //             {
    //                 int balance = getBalance(current);

    //                 if (balance > 1)
    //                 {
    //                     if (getBalance(current->child[left]) < 0)
    //                         leftRotate(&current->child[left]);
    //                     rightRotate(&current);
    //                 }
    //                 else if (balance < -1)
    //                 {
    //                     if (getBalance(current->child[right]) > 0)
    //                         rightRotate(&current->child[right]);
    //                     leftRotate(&current);
    //                 }

    //                 if (isNodeRoot(*current))
    //                     *root = current;

    //                 current = current->parent;
    //             }
    //         }
    //     }
    // }
    // else
    //     printf("Node is not exist\n");
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
