#include <stdio.h>
#include <stdlib.h>

#define REP(i, a, b) for (i = (a); i < (b); i++)
#define REPR(i, a, b) for (i = (a-1); i >= (b); i--)

void swap(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

int main()
{
    int N, i, j;
    int *arr;

    scanf("%d", &N);
    arr = (int *) malloc(N * sizeof(int));

    if (arr == NULL)
    {
        printf("Memory not allocated");
    }
    else
    {
        REP(i, 0, N)
            scanf("%d", &arr[i]);

        REP(i, 0, N-1)
            REPR(j, N, i)
                if (arr[j] < arr[j-1])
                    swap(&arr[j], &arr[j-1]);
        
        REP(i, 0, N)
            printf("%d ", arr[i]);
        
        free(arr);
    }
    printf("\n");

    return 0;
}