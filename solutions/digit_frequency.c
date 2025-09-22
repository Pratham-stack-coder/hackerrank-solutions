#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    char str[1000];
    int freq[10]={0};
    scanf("%s",str);
    for (int i=0;i<strlen(str);i++) {
        if (isdigit(str[i])){
            freq[str[i]-'0']++; // Convert char digit to int index
        }
    }
    for (int i=0;i<10;i++) {
        printf("%d ",freq[i]);
    }  
    return 0;
}
