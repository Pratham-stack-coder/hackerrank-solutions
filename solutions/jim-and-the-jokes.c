#include <stdio.h>
#include <stdlib.h>

#define MAX_EVENTS 100005

long long values[MAX_EVENTS];

int cmpfunc(const void *a, const void *b) {
    long long x = *(long long*)a;
    long long y = *(long long*)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    int m, d;
    int count = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &m, &d);

        if (m < 2) continue;

        int valid = 1, temp = d;
        while (temp > 0) {
            int digit = temp % 10;
            if (digit >= m) {
                valid = 0;
                break;
            }
            temp /= 10;
        }
        if (!valid) continue;

        long long val = 0, power = 1;
        temp = d;
        while (temp > 0) {
            int digit = temp % 10;
            val += digit * power;
            power *= m;
            temp /= 10;
        }

        values[count++] = val;
    }

    qsort(values, count, sizeof(long long), cmpfunc);

    long long jokes = 0;
    for (int i = 0; i < count;) {
        int j = i;
        while (j < count && values[j] == values[i]) j++;
        long long freq = j - i;
        jokes += (freq * (freq - 1)) / 2;
        i = j;
    }

    printf("%lld\n", jokes);
    return 0;
}
