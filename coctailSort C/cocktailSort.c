
#include  <stdio.h>


void swap(int *x, int *y) {
    if(x == y)
        return;
    *x ^= *y;
    *y ^= *x;
    *x ^= *y;
}
void cocktailsort(int *a, size_t n) {
    while(1) {
        // junta dos loops similares en una
        char flag;
        int it, i;
        size_t start[2] = {1, n - 1},
               end[2] = {n, 0},
               inc[2] = {1, -1};
        for(it = 0; it < 2; ++it) {
            flag = 1;
            for(i = start[it]; i != end[it]; i += inc[it])
                if(a[i - 1] > a[i]) {
                    swap(a + i - 1, a + i);
                    flag = 0;
                }
            if(flag)
                return;
        }
    }
}
 
int main(void) {
    int a[] = { 6, -3, 141, -4, 2, 0, 9, 5, 3, 2 };
    int i;
    size_t n = sizeof(a)/sizeof(a[0]);
    printf("Array Original:\n");
    for (i = 0; i < n; i++)
    printf("%d%s", a[i], i == n - 1 ? "\n" : " ");
    printf("\nArray Ordenado:\n");
    cocktailsort(a, n);
    for ( i = 0; i < n; ++i)
        printf("%d ", a[i]);
    return 0;
}
