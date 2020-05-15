#include <stdio.h>
#include <stdlib.h>

struct Node *createNode()
{
    // membuat 1 node baru kemudian mengalokasikan di memori
    struct Node *new = NULL;
    new = (struct Node *)malloc(sizeof(struct Node));

    return new;
}

void assignNode(struct Node *list, int n)
{
    // mengisi data dengan n kemudian mengisi next dnegan NULL karena belum disambungkan
    list->data = n;
    list->next = NULL;
}

void initializeList(struct Node **list, int n)
{
    *list = createNode();
    assignNode(*list, n);
    (*list)->next = NULL;
}

void pushFront(struct Node **list, int n)
{
    // pembuatan node baru
    struct Node *p = NULL;

    p = createNode();
    assignNode(p, n);

    // penyambungan node baru dengan linked list
    p->next = (*list);
    (*list) = p;
}

void pushBack(struct Node *list, int n)
{
    // pembuatan node baru
    struct Node *p;
    struct Node *tail;

    p = createNode();
    assignNode(p, n);

    if (sizeof(list) == 0)
    {
        list = p;
    }
    else
    {
        // penyambungan node baru dengan linked list
        tail = tailAddress(list);
        tail->next = p;
    }
}

void pushAt(struct Node *list, int n, int index)
{
    // pembuatan node baru
    struct Node *p = createNode();
    struct Node *pivot = addressAt(list, index - 1);

    assignNode(p, n);

    // penyambungan node baru dengan linked list
    p->next = pivot->next;
    pivot->next = p;
}

int size(struct Node *list)
{
    int count = 0;
    // ketika list berisi NULL, artinya list sudah mencapai tail
    while (list != NULL)
    {
        count++;
        list = list->next;
    }
    return count;
}

void printList(struct Node *n)
{
    while (n != NULL)
    {
        printf("%d ", n->data);
        n = n->next;
    }
    printf("\n");
}

struct Node *addressAt(struct Node *list, int index)
{
    int count = 0;
    while (count < index)
    {
        count++;
        list = list->next;
    }

    return list;
}

struct Node *tailAddress(struct Node *list)
{
    return addressAt(list, size(list) - 1);
}

int headData(struct Node *list)
{
    return list->data;
}

int tailData(struct Node *list)
{
    struct Node *p = tailAddress(list);
    return p->data;
}

int dataAt(struct Node *list, int index)
{
    struct Node *p = addressAt(list, index);
    return p->data;
}

void popFront(struct Node **list)
{
    struct Node *head = *list;
    *list = addressAt(*list, 1);

    head->next = NULL;
    free(head);
}

void popBack(struct Node *list)
{
    struct Node *newTail = addressAt(list, size(list) - 2);
    struct Node *tail = tailAddress(list);

    newTail->next = NULL;
    free(tail);
}

void popAt(struct Node *list, int index)
{
    struct Node *pivot = addressAt(list, index);
    struct Node *pivotPrev = addressAt(list, index - 1);

    pivotPrev->next = pivot->next;
    pivot->next = NULL;
    free(pivot);
}