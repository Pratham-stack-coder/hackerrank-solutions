#include <stdio.h>

int pylons(int n, int k, int arr[]) {
    int count = 0;       // Number of plants built
    int i = 0;

    while (i < n) {
        int loc = -1;

        // Look for the farthest possible city (within range) to place a plant
        int j = (i + k - 1 < n) ? i + k - 1 : n - 1;
        for (; j >= i - (k - 1) && j >= 0; j--) {
            if (arr[j] == 1) {
                loc = j;
                break;
            }
        }

        if (loc == -1) {
            return -1;   // Cannot place a plant to cover this segment
        }

        count++;
        i = loc + k;     // Jump to the next uncovered city
    }

    return count;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = pylons(n, k, arr);
    printf("%d\n", result);

    return 0;
}
