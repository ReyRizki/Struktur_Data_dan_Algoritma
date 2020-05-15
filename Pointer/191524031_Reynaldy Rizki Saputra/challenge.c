#include <stdio.h>

struct element
{
    char info;
    struct element* next;
};

void printList(struct element *n)
{
    while (n != NULL)
    {
        printf("%c", n -> info);
        n = n -> next;
    }
    printf("\n");
}

int main()
{
    struct element x, y, z, w;
    struct element *p, *q, *r, *s;

    p = &x;
    (*p).info = 'T';
    (*p).next = NULL;

    q = &y;
    (*q).info = 'A';
    (*q).next = NULL;

    r = &z;
    (*r).info = 'H';
    (*r).next = NULL;

    (*p).next = q;
    (*q).next = r;
    printList(p);

    (*r).next = p;
    p = (*p).next;
    (*r).next = NULL;
    printList(p);

    s = &w;
    (*s).info = 'U';
    (*s).next = NULL;

    p = &x;
    (*q).next = r;
    (*r).next = p;
    (*p).next = s;
    printList(q);

    return 0;
}