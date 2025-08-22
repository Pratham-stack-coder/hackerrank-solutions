#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b) {
    int x = *(int *)a;
    int y = *(int *)b;
    return (x > y) - (x < y); 
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), cmp);
    int minDiff = abs(arr[1] - arr[0]);
    for (int i = 1; i < n - 1; i++) {
        int diff = abs(arr[i + 1] - arr[i]);
        if (diff < minDiff) {
            minDiff = diff;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        int diff = abs(arr[i + 1] - arr[i]);
        if (diff == minDiff) {
            printf("%d %d ", arr[i], arr[i + 1]);
        }
    }
    printf("\n");

    return 0;
}
