#include <stdio.h>
#include <stdint.h>

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        unsigned long long n;
        scanf("%llu", &n);
        int moves = 0;
        while (n > 1) {
            if (n & (n - 1)) {
                /* n is not a power of 2: subtract largest power of 2 < n */
                int shift = 63 - __builtin_clzll(n);
                unsigned long long highest = 1ULL << shift;
                n -= highest;
            } else {
                /* n is a power of 2: divide by 2 */
                n >>= 1;
            }
            moves++;
        }
        if (moves % 2) printf("Louise\n"); else printf("Richard\n");
    }
    return 0;
}
