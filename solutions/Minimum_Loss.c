#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef long long ll;

int cmp_desc(const void *a, const void *b) {
    const ll *pa = (const ll*)a;
    const ll *pb = (const ll*)b;
    if (pa[0] < pb[0]) return 1; 
    if (pa[0] > pb[0]) return -1;
    return 0;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    ll (*arr)[2] = malloc(sizeof(ll[2]) * n);
    if (!arr) return 0;

    for (int i = 0; i < n; ++i) {
        ll price;
        scanf("%lld", &price);
        arr[i][0] = price;
        arr[i][1] = i;
    }
    qsort(arr, n, sizeof(arr[0]), cmp_desc);

    ll min_loss = LLONG_MAX;
    for (int i = 0; i + 1 < n; ++i) {
        if (arr[i][1] < arr[i+1][1]) {
            ll diff = arr[i][0] - arr[i+1][0];
            if (diff > 0 && diff < min_loss) min_loss = diff;
        }
    }
    if (min_loss == LLONG_MAX) min_loss = 0;

    printf("%lld\n", min_loss);

    free(arr);
    return 0;
}
