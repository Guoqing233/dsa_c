#include <stdio.h>
#include <stdlib.h>
#define CUTOFF (9)
typedef int Rank;
typedef int ElementType;
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t)) 
static inline void swap(ElementType *a, ElementType* b) {
    ElementType t = *a;
    *a = *b;
    *b = t;
}

static inline void Median3(ElementType *a, Rank lo, Rank hi) {
    ElementType mi = (lo + hi) >> 1;
    if(a[hi] < a[mi])
        Swap(&a[hi], &a[lo]);
    if(a[hi] < a[lo])
        Swap(&a[hi], &a[lo]);
    if(a[lo] < a[mi])
        Swap(&a[mi], &a[lo]);
}

/*
 * sort a[lo, hi)
 */
void InsertionSort(ElementType *a, Rank lo, Rank hi) {
   ElementType tmp;
   int i, j;
   for(i = lo + 1; i < hi; ++i) {
       tmp = a[i];
       for(j = i; lo < j && tmp < a[j - 1]; --j) {
           a[j] = a[j - 1];
       }
       a[j] = tmp;
   }
}

//sort a[lo, hi)
void QuickSort(ElementType *a, Rank lo, Rank hi) {
    if(CUTOFF < hi - lo) {   //if too short, go to Insertionsort
    	ElementType pivot, tmp;
		Rank i, mi;
        Median3(a, lo, hi - 1);    //chose pivot and hide it in a[lo]
    	pivot = a[lo];
        
		for(mi = lo, i = lo + 1; i < hi - 1; ++i) {
            if(a[i] < pivot) {
                ++mi;
                SWAP(a[mi], a[i], tmp);
            }
        }
        SWAP(a[lo], a[mi], tmp);    //let pivot at right  position
        QuickSort(a, lo, mi);
        QuickSort(a, mi + 1, hi);
    } else
        InsertionSort(a, lo, hi);
}

int main()
{
    ElementType a[] = {69, 131, 93, 6363, 551, 145, 214, 512, 1949, 1026,
	422, 797, 654, 321, 583, 189, 1317, 7015,163, 126, 2110, 33158, 434, 99,
		       36, 88, 24, 7, /* 167, 43, 216, 9, 60, 20, 1, 15,330, 66, 19, 199, 619, 225, 2114, 5812, 360, 702, 1996, 1125, 2215, 3021, 9805, 5110, 3300, */
		       /* 5858, 1999, 82086, 6060, 100120, */
	10, 31, 414, 44, 0, 5566, 957, 100, 26, 62, 81, 352, 2431, 201, 526,
	119, 491, 927, 270, 765, 656, 603, 349, 694, 247, 943, 216, 739, 794,
    631, 444, 322, 614, 431, 139, 839, 271, 590, 689, 154, 511, 515, 465,
    104, 458, 101, 1024, 685, 148, 480, 150, 156, 452, 299, 705, 497, 705,
    898, 860, 116, 953, 904, 355, 436, 655, 730, 250, 926, 509, 135, 384, 131,};
    size_t len =  sizeof(a) / sizeof(a[0]);
    size_t i;
    QuickSort(a, 0, len);
    for(i = 0; i < len; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
