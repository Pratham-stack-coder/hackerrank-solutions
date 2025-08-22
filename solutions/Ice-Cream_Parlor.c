#include <stdio.h>

void solve() {
    int m, n;
    scanf("%d", &m); // Amount of money
    scanf("%d", &n); // Number of flavors

    int costs[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &costs[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) { // Start inner loop from i+1 to avoid duplicate pairs and same flavor
            if (costs[i] + costs[j] == m) {
                printf("%d %d\n", i + 1, j + 1); // Output 1-based indices
                return; // Solution is unique, so we can return after finding it
            }
        }
    }
}

int main() {
    int t;
    scanf("%d", &t); // Number of trips
    while (t--) {
        solve();
    }
    return 0;
}
