#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main() {
    char buf[10005];
    if (!fgets(buf, sizeof(buf), stdin)) return 0;

    // remove newline if present
    size_t len = strlen(buf);
    if (len > 0 && buf[len-1] == '\n') buf[--len] = '\0';

    // create string without spaces
    char s[10005];
    int n = 0;
    for (size_t i = 0; i < len; ++i) {
        if (!isspace((unsigned char)buf[i])) s[n++] = buf[i];
    }
    s[n] = '\0';

    if (n == 0) {
        printf("\n");
        return 0;
    }

    double sd = sqrt((double)n);
    int rows = (int)floor(sd);
    int cols = (int)ceil(sd);
    if (rows * cols < n) rows++;

    // Print by reading columns
    for (int c = 0; c < cols; ++c) {
        if (c) putchar(' ');
        for (int r = 0; r < rows; ++r) {
            int idx = r * cols + c;
            if (idx < n) putchar(s[idx]);
        }
    }
    putchar('\n');
    return 0;
}
