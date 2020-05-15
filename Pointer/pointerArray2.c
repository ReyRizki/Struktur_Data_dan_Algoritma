#include <stdio.h>

int main()
{
    int arr[] = {10, 11, 12};

    int *p = arr;

    int i;
    for (i = 0; i < 3; i++)
    {
        printf("%d\n", *p++);
    }

    return 0;
}