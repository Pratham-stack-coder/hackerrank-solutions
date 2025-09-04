#include <stdio.h>

int main() {
    int q;
    scanf("%d", &q);

    while (q--) {
        int n;
        scanf("%d", &n);

        long long container[100][100];
        long long rowSum[100] = {0}, colSum[100] = {0};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%lld", &container[i][j]);
                rowSum[i] += container[i][j];  // total balls in container i
                colSum[j] += container[i][j];  // total balls of type j
            }
        }

        // sort rowSum and colSum
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (rowSum[i] > rowSum[j]) {
                    long long tmp = rowSum[i];
                    rowSum[i] = rowSum[j];
                    rowSum[j] = tmp;
                }
                if (colSum[i] > colSum[j]) {
                    long long tmp = colSum[i];
                    colSum[i] = colSum[j];
                    colSum[j] = tmp;
                }
            }
        }

        // compare
        int possible = 1;
        for (int i = 0; i < n; i++) {
            if (rowSum[i] != colSum[i]) {
                possible = 0;
                break;
            }
        }

        if (possible) printf("Possible\n");
        else printf("Impossible\n");
    }

    return 0
}
