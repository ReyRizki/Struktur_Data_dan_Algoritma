#include <stdio.h>

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
    int N, arr[5], i, j;

    scanf("%d", &N);

    REP(i, 0, N)
        scanf("%d", &arr[i]);

    REP(i, 0, N-1)
        REPR(j, N, i)
            if (arr[j] < arr[j-1])
                swap(&arr[j], &arr[j-1]);

    for (i = 0; i < N; i++)
        printf("%d ", arr[i]);

    printf("\n");

    return 0;
}