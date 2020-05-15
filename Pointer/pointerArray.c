#include <stdio.h>

int main()
{
    int my_arr[] = {1, 23, 17, 4, -5, 100};
    int *ptr;

    int i;
    ptr = &my_arr[0];

    for (i = 0; i < 6; i++)
    {
        printf("my_arr[%d] = %d ", i, my_arr[i]);
        printf("ptr + %d = %d\n", i, *(ptr++)); // coba ubah jadi *ptr++ dan *(++ptr)
    }
    return 0;
}