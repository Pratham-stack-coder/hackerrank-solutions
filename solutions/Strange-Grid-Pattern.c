#include <stdio.h>

int main() {
    long long r, c;
    scanf("%lld %lld", &r, &c);

    long long ans = 10 * ((r - 1) / 2) + 2 * (c - 1) + (r % 2 == 0);

    printf("%lld\n", ans);
    return 0;
}
