#include "tree.h"

#ifndef MACROS
#define MACROS

#define u unsigned
#define s short
#define ll long long
#define REP(i, a, b) for (i = (a); i < (b); i++)
#define REPR(i, a, b) for (i = (a - 1); i >= (b); i--)

#endif

// ==============
//  CONSTRUCTORS
// ==============

// Description		: Function to construct a tree
// Input			: Capacity of a tree
// Output			: Tree with given capacity
Tree createTree(u int capacity)
{
    Tree tree;

    tree.capacity = capacity;
    tree.nodes = (Node *)malloc(tree.capacity * sizeof(Node));
    setTreeSize(&tree, 0);

    return tree;
}

// Description		: Function to create a node
// Input			: Data of the node, parent of the node (-1 if the node is root)
// Output			: The node with given parameters
Node createNode(dataType data, int parent)
{
    Node node;

    setNode(&node, data, -1, -1, parent);

    return node;
}

// ===========
//  ACCESSORS
// ===========

// Description		: Function to get the capacity field of a tree
// Input			: Tree
// Output			: Tree's capacity
u int getTreeCapacity(Tree tree)
{
    return tree.capacity;
}

// Description		: Function to get the size field of a tree
// Input			: Tree
// Output			: Tree's size
u int getTreeSize(Tree tree)
{
    return tree.size;
}

// Description		: Function to get the nodes of the tree
// Input			: Tree
// Output			: Tree's nodes
Node *getTreeNodes(Tree tree)
{
    return tree.nodes;
}

// Description		: Function to get a node of a tree by given index
// Input			: Tree, index
// Output			: The node
Node getNode(Tree tree, u int index)
{
    return index >= tree.size ? createNode(0, -1) : *(tree.nodes + index);
}

// Description		: Function to get an address of a node in a tree by given index (index is in the range of 0 <= x < size)
// Input			: Tree, index
// Output			: The node's address
Node *getNodeAddress(Tree tree, u int index)
{
    return tree.nodes + index;
}

// Description		: Function to get the data field of a node
// Input			: Node
// Output			: Data
dataType getNodeData(Node node)
{
    return node.data;
}

// Description		: Function to get the index of a node's first child
// Input			: Node
// Output			: Index of node's first child
int getNodeFirstChild(Node node)
{
    return node.firstChild;
}

// Description		: Function to get the index of a node's next sibling
// Input			: Node
// Output			: Index of node's next sibling
int getNodeNextSibling(Node node)
{
    return node.nextSibling;
}

// Description		: Function to get the index of a node's parent
// Input			: Node
// Output			: Index of node's parent
int getNodeParent(Node node)
{
    return node.parent;
}

// Description		: Function to get the root index of a tree
// Input			: Tree
// Output			: Root index of the tree
u int treeRoot(Tree tree)
{
    u int i, size = getTreeSize(tree);

    REP(i, 0, size)
        if (isNodeRoot(getNode(tree, i)))
            return i;
}

// Description		: Function to get the last child index of a node
// Input			: Tree, index of a parent
// Output			: Index of the last child of the node (-1 if doesn't have any)
int lastChild(Tree tree, u int index)
{
    int current = getNodeFirstChild(getNode(tree, index));

    while (getNode(tree, current).nextSibling != -1)
        current = getNode(tree, current).nextSibling;

    return current;
}

// Description		: Function to get level of a node in tree
// Input			: Tree, index of the node
// Output			: Level of the given index
u int nodeLevel(Tree tree, u int index)
{
    return isNodeRoot(getNode(tree, index)) ? 0 : 1 + nodeLevel(tree, getNodeParent(getNode(tree, index)));
}

// Description		: Function to get order of a node in tree
// Input			: Tree, index of the node
// Output			: Order of given index
u int nodeOrder(Tree tree, u int index)
{
    int current, max, currentOrder;

    if (isNodeLeaf(getNode(tree, index)))
        return 0;
    else
    {
        current = getNodeFirstChild(getNode(tree, index));
        max = nodeOrder(tree, current);

        while ((current = getNodeNextSibling(getNode(tree, current))) != -1)
            if ((currentOrder = nodeOrder(tree, current)) > max)
                max = currentOrder;
        
        return max + 1;
    }
}

// Description		: Function to get the depth of a tree (Order of the root)
// Input			: Tree
// Output			: Depth of the tree
u int treeDepth(Tree tree)
{
    return nodeOrder(tree, treeRoot(tree));
}

// Description		: Procedure to visit a node (In this code, the visiting is printing the node's data)
// Initial State	: The tree isn't visited yet
// Final State		: The tree is visited
void visitNode(Node node)
{
    printf("%c ", getNodeData(node));
}

// Description		: Procedure to visit a node using breadth first search
// Initial State	: The node isn't visited yet
// Final State		: The node is visited
void bfsVisitNode(Tree tree, int index, u int level)
{
    int current;

    if (isNodeExist(getNode(tree, index)))
    {
        if (level == 0)
            visitNode(getNode(tree, index));
        else
        {
            current = getNodeFirstChild(getNode(tree, index));

            bfsVisitNode(tree, current, level - 1);

            while ((current = getNodeNextSibling(getNode(tree, current))) != -1)
                bfsVisitNode(tree, current, level - 1);
        }
    }
}

// Description		: Function to do preorder traversing for a tree recursively
// Initial State	: The tree hasn't traversed yet
// Final State		: The tree has been traversed
void preorder(Tree tree, int index)
{
    int current;

    if (isNodeLeaf(getNode(tree, index)))
        visitNode(getNode(tree, index));
    else
    {
        visitNode(getNode(tree, index));
        current = getNodeFirstChild(getNode(tree, index));
        preorder(tree, current);

        while((current = getNodeNextSibling(getNode(tree, current))) != -1)
            preorder(tree, current);
    }
}

// Description		: Function to traverse a tree by inorder recursively
// Initial State	: The tree hasn't traversed yet
// Final State		: The tree has been traversed
void inorder(Tree tree, int index)
{
    int current;

    if (isNodeLeaf(getNode(tree, index)))
        visitNode(getNode(tree, index));
    else
    {
        current = getNodeFirstChild(getNode(tree, index));
        inorder(tree, current);
        visitNode(getNode(tree, index));

        while((current = getNodeNextSibling(getNode(tree, current))) != -1)
            inorder(tree, current);
    }
}

// Description		: Function to traverse a tree by postorder recursively
// Initial State	: The tree hasn't traversed yet
// Final State		: The tree has been traversed
void postorder(Tree tree, int index)
{
    int current;

    if (isNodeLeaf(getNode(tree, index)))
        visitNode(getNode(tree, index));
    else
    {
        current = getNodeFirstChild(getNode(tree, index));
        postorder(tree, current);

        while ((current = getNodeNextSibling(getNode(tree, current))) != -1)
            postorder(tree, current);

        visitNode(getNode(tree, index));
    }
}

// Description		: Procedure to traverse a tree by levelorder
// Initial State	: The tree hasn't traversed yet
// Final State		: The tree has been traversed
void levelorder(Tree tree, int index)
{
    u int i;

    REP(i, 0, treeDepth(tree) + 1)
        bfsVisitNode(tree, treeRoot(tree), i);
}

// Description		: Function to convert unsigned integer to integer
// Input			: Integer
// Output			: Unsigned integer
int uToInt(u int i)
{
    return i;
}

// ==========
//  MUTATORS
// ==========

// Description		: Procedure to set the size of the tree
// Initial State	: Size is not setted yet
// Final State		: Size is setted
void setTreeSize(Tree *tree, u int size)
{
    tree->size = size;
}

// Description		: Procedure to set a node of a tree
// Initial State	: Node is not setted yet
// Final State		: Node is setted
void setNode(Node *node, dataType data, int firstChild, int nextSibling, int parent)
{
    setNodeData(node, data);
    setNodeFirstChild(node, firstChild);
    setNodeNextSibling(node, nextSibling);
    setNodeParent(node, parent);
}

// Description		: Procedure to set data field of a node
// Initial State	: Data field of node is not setted yet
// Final State		: Data field of node is setted
void setNodeData(Node *node, dataType data)
{
    node->data = data;
}

// Description		: Procedure to set first child field of a node
// Initial State	: First child field is not setted yet
// Final State		: First child is setted
void setNodeFirstChild(Node *node, int firstChild)
{
    node->firstChild = firstChild;
}

// Description		: Procedure to set next sibling field of a node
// Initial State	: Next sibling field is not setted yet
// Final State		: Next sibling is setted
void setNodeNextSibling(Node *node, int nextSibling)
{
    node->nextSibling = nextSibling;
}

// Description		: Procedure to set parent field of a node
// Initial State	: Parent field is not setted yet
// Final State		: Parent is setted
void setNodeParent(Node *node, int parent)
{
    node->parent = parent;
}

// Description		: Procedure to insert a node
// Initial State	: New node is not inserted yet
// Final State		: New node is inserted
void insertNode(Tree *tree, dataType data, int parent)
{
    int last;
    Node *prevRoot;

    if (isTreeEmpty(*tree))
    {
        *(getNodeAddress(*tree, getTreeSize(*tree))) = createNode(data, -1);
        setTreeSize(tree, getTreeSize(*tree) + 1);
    }
    else if (isTreeFull(*tree))
        printf("Overflow\n");
    else if (parent >= uToInt(getTreeSize(*tree)) or parent <= -2)
        printf("Index out of range\n");
    else if (parent == -1)
    {
        *(getNodeAddress(*tree, getTreeSize(*tree))) = createNode(data, parent);
        prevRoot = getNodeAddress(*tree, treeRoot(*tree));
        setNodeFirstChild(getNodeAddress(*tree, getTreeSize(*tree)), treeRoot(*tree));
        setNodeParent(prevRoot, getTreeSize(*tree));
        setTreeSize(tree, getTreeSize(*tree) + 1);
    }
    else
    {
        *(getNodeAddress(*tree, getTreeSize(*tree))) = createNode(data, parent);

        if (isNodeLeaf(getNode(*tree, parent)))
            getNodeAddress(*tree, parent)->firstChild = getTreeSize(*tree);
        else
        {
            last = lastChild(*tree, parent);
            getNodeAddress(*tree, last)->nextSibling = getTreeSize(*tree);
        }

        setTreeSize(tree, getTreeSize(*tree) + 1);
    }
}

// ============
//  VALIDATORS
// ============

// Description		: Function to check if a tree is empty or not
// Input			: Tree
// Output			: 1 if empty, 0 if not
bool isTreeEmpty(Tree tree)
{
    return tree.size == 0;
}

// Description		: Function to check if a tree if full or not
// Input			: Tree
// Output			: 1 if full, 0 if not
bool isTreeFull(Tree tree)
{
    return tree.size == tree.capacity;
}

// Description		: Function to check if a node is a root or not
// Input			: Node
// Output			: 1 if root, 0 if not
bool isNodeRoot(Node node)
{
    return node.parent == -1 and node.nextSibling == -1;
}

// Description		: Function to check if a node is a leaf or not
// Input			: Node
// Output			: 1 if leaf, 0 if not
bool isNodeLeaf(Node node)
{
    return node.firstChild == -1;
}

// Description		: Function to check if a node is exist or not
// Input			: Node
// Output			: 1 if exist, 0 if not
bool isNodeExist(Node node)
{
    return getNodeData(node) != 0;
}

// ============
//  DESTRUCTOR
// ============

// Description		: Procedure to delete a tree
// Initial State	: Tree isn't deleted yet
// Final State		: Tree is deleted
void deleteTree(Tree *tree)
{
    free(tree->nodes);
    tree->capacity = 0;
    setTreeSize(tree, 0);
}
