#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m, s;
        scanf("%d %d %d", &n, &m, &s);
        int result = (m + s - 1) % n;
        if (result == 0) {
            result = n;
        }
        printf("%d\n", result);
    }
    return 0;
}   
