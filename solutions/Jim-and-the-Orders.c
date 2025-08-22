#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int serve;
    int idx;   // customer number (1-based)
} Order;

int cmp(const void *a, const void *b) {
    const Order *x = (const Order *)a;
    const Order *y = (const Order *)b;
    if (x->serve != y->serve) return (x->serve < y->serve) ? -1 : 1;
    return (x->idx < y->idx) ? -1 : (x->idx > y->idx);
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    Order *arr = (Order *)malloc(n * sizeof(Order));
    for (int i = 0; i < n; i++) {
        int orderNum, prep;
        scanf("%d %d", &orderNum, &prep);
        arr[i].serve = orderNum + prep;
        arr[i].idx = i + 1; // customers numbered from 1
    }

    qsort(arr, n, sizeof(Order), cmp);

    for (int i = 0; i < n; i++) {
        if (i) printf(" ");
        printf("%d", arr[i].idx);
    }
    printf("\n");

    free(arr);
    return 0;
}
