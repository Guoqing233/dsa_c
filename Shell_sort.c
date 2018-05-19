#include <stdio.h>
#include <stdlib.h>
#include "shellsort.h"
#define arr_length(a) (sizeof(a) / sizeof(a[0]))
int main()
{
    int len;
    int i;
    int a[] = {158, 434, 99, 36, 88, 24, 7, 167, 43, 218, 4, 5, 14, 2, 45, 2018, 3, \
    144, 6, 16, 9, 60, 20, 1, 15,330, 66, 19, 199, 619, 225, 10, 31, 414, 44,   \
    0, 5566, 957, 100, 26, 62};
    len = arr_length(a);
    ShellSort(a, len);
    for(i = 0; i < len; ++i) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
