#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Queue structure for BFS
#define MAXN 1000001

int queue[MAXN];
int visited[MAXN];
int dist[MAXN];

int main() {
    int q;
    scanf("%d", &q);

    while (q--) {
        int n;
        scanf("%d", &n);

        for (int i = 0; i <= n; i++) {
            visited[i] = 0;
            dist[i] = 0;
        }

        // BFS
        int front = 0, rear = 0;
        queue[rear++] = n;
        visited[n] = 1;

        while (front < rear) {
            int x = queue[front++];
            if (x == 0) {
                printf("%d\n", dist[x]);
                break;
            }

            // Option 1: x - 1
            if (!visited[x - 1]) {
                queue[rear++] = x - 1;
                visited[x - 1] = 1;
                dist[x - 1] = dist[x] + 1;
            }

            // Option 2: factorization moves
            for (int i = 2; i <= sqrt(x); i++) {
                if (x % i == 0) {
                    int next = x / i; // max(i, x/i) = x/i since >= i
                    if (!visited[next]) {
                        queue[rear++] = next;
                        visited[next] = 1;
                        dist[next] = dist[x] + 1;
                    }
                }
            }
        }
    }

    return 0;
}
