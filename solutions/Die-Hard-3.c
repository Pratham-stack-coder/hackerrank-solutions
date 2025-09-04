#include <stdio.h>

// Euclidean algorithm to find gcd
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        int g = gcd(a, b);

        if (c <= (a > b ? a : b) && c % g == 0)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
