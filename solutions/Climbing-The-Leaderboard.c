#include <stdio.h>
#include <stdlib.h>
void climbingLeaderboard(int ranked[], int n, int player[], int m) {
    int *unique = (int *)malloc(n * sizeof(int));
    int uCount = 0;
    unique[uCount++] = ranked[0];
    for (int i = 1; i < n; i++) {
        if (ranked[i] != ranked[i - 1]) {
            unique[uCount++] = ranked[i];
        }
    }
    int idx = uCount - 1;
    for (int i = 0; i < m; i++) {
        int score = player[i];
        while (idx >= 0 && score >= unique[idx]) {
            idx--;
        }
        printf("%d\n", idx + 2);  
    }

    free(unique);
}

int main() {
    int n;
    scanf("%d", &n);
    int ranked[n];
    for (int i = 0; i < n; i++) scanf("%d", &ranked[i]);

    int m;
    scanf("%d", &m);
    int player[m];
    for (int i = 0; i < m; i++) scanf("%d", &player[i]);

    climbingLeaderboard(ranked, n, player, m);
    return 0;
}
