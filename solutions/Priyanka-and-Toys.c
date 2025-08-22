#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    int x = *(const int*)a, y = *(const int*)b;
    return (x > y) - (x < y);
}

int toys(int *w, int n) {
    qsort(w, n, sizeof(int), cmp);
    int containers = 0, i = 0;
    while (i < n) {
        int start = w[i];
        containers++;
        i++;
        while (i < n && w[i] <= start + 4) i++;
    }
    return containers;
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int *w = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &w[i]);
    printf("%d\n", toys(w, n));
    free(w);
    return 0;
}
