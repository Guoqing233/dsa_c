#include <stdio.h>
#include <stdlib.h> 
#define COMPARE(x, y) ((x) < (y) ? -1 : ((x) == (y) ? 0 : 1))
typedef int Rank;
typedef int ElementType;

/*  search for x in a[lo,  hi) */
Rank BinSearch(ElementType a[], ElementType x, Rank lo, Rank hi) {
    Rank mi;
    while (lo < hi) {
        mi = (lo + hi) >> 1;
        switch(COMPARE(x, a[mi])) {
            case -1: 
                hi = mi;
                break;
            default:
                lo = mi + 1;
        }
    }
    return --lo;
}

int main(int argv, const char* argc[]) {
    int a[] = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5, };
    unsigned int t = sizeof(a) / sizeof(a[0]);
    printf("%u\n", BinSearch(a, 4, 0, t));
    return 0;
}








