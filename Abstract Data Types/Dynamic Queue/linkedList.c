// Program		: linkedList.c
// Author		: Rey Rizki
// Description	: Linked List ADT body implementation file
// Date			: Monday, 30 March 2020
// Version		: V 2.0
// Compiler		: gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04)

#include "linkedList.h"

List createList()
{
    List list;
    list.head = NULL;
    return list;
}

Node *createNode()
{
    Node *node = (Node *)malloc(sizeof(Node));
    return node;
}

void assignNode(Node *node, dataType n)
{
    node->data = n;
    node->next = NULL;
}

void deleteNode(Node *node)
{
    node->next = NULL;
    free(node);
}

bool isListEmpty(List list)
{
    return list.head == NULL;
}

void insertAtHead(List *list, dataType n)
{
    Node *node = createNode();
    assignNode(node, n);

    if (node != NULL)
    {
        node->next = list->head;
        list->head = node;
    }
}

void insertAt(List *list, dataType n, u int index)
{
    Node *node = createNode();
    assignNode(node, n);

    address pivot = addressAt(*list, index - 1);

    if (isListEmpty(*list) || index == 0)
        insertAtHead(list, n);
    else if (index == listSize(*list) - 1)
        insertAtTail(list, n);
    else if (pivot == NULL)
        printf("Index is greater than size of list");
    else
    {
        node->next = pivot->next;
        pivot->next = node;
    }
}

void insertAtTail(List *list, dataType n)
{
    Node *node = createNode();
    assignNode(node, n);

    if (isListEmpty(*list))
        insertAtHead(list, n);
    else
        addressOfTail(*list)->next = node;
}

void deleteAtHead(List *list)
{
    address head = list->head;
    list->head = addressAt(*list, 1);
    deleteNode(head);
}

void deleteAt(List *list, u int index)
{
    address pivot = addressAt(*list, index);
    address pivotPrev = addressAt(*list, index - 1);

    if (pivot == NULL || pivotPrev == NULL)
        printf("Index is greater than size of list");
    else
    {
        pivotPrev->next = pivot->next;
        deleteNode(pivot);
    }
}

void deleteAtTail(List *list)
{
    address newTail = addressAt(*list, listSize(*list) - 2);
    address tail = addressOfTail(*list);
    newTail->next = NULL;
    deleteNode(tail);
}

void printList(List list)
{
    address trans = list.head;
    while (trans != NULL)
    {
        printf("%d", trans->data);
        (trans->next != NULL) ? printf(" ") : printf("\n");
        trans = trans->next;
    }
}

u int listSize(List list)
{
    address trans = list.head;
    u int count = 0;
    while (trans != NULL)
    {
        count++;
        trans = trans->next;
    }

    return count;
}

address addressAt(List list, u int index)
{
    address trans = list.head;
    u int count = 0;

    if (index >= listSize(list))
        return NULL;

    while (count < index)
    {
        count++;
        trans = trans->next;
    }
    return trans;
}

address addressOfTail(List list)
{
    return addressAt(list, listSize(list) - 1);
}

dataType dataOfHead(List list)
{
    return list.head->data;
}

dataType dataAt(List list, u int index)
{
    return (index >= listSize(list)) ? -1 : addressAt(list, index)->data;
}

dataType dataOfTail(List list)
{
    return addressOfTail(list)->data;
}