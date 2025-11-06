#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char* ltrim(char*);
char* rtrim(char*);
char** split_string(char*);

int parse_int(char*);

/*
 * Complete the 'lilysHomework' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

// Helper structure to store value and its original index
typedef struct {
    int value;
    int index;
} Pair;

// Compare function for qsort
int compare(const void* a, const void* b) {
    return ((Pair*)a)->value - ((Pair*)b)->value;
}

// Function to count swaps to sort
int countSwaps(int* arr, int n, bool ascending) {
    Pair* pairs = malloc(n * sizeof(Pair));
    for (int i = 0; i < n; i++) {
        pairs[i].value = arr[i];
        pairs[i].index = i;
    }

    // Sort pairs based on value
    if (ascending)
        qsort(pairs, n, sizeof(Pair), compare);
    else {
        qsort(pairs, n, sizeof(Pair), compare);
        // Reverse for descending
        for (int i = 0; i < n / 2; i++) {
            Pair temp = pairs[i];
            pairs[i] = pairs[n - i - 1];
            pairs[n - i - 1] = temp;
        }
    }

    // Track visited elements
    bool* visited = calloc(n, sizeof(bool));
    int swaps = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i] || pairs[i].index == i)
            continue;

        int cycle_size = 0;
        int j = i;

        while (!visited[j]) {
            visited[j] = true;
            j = pairs[j].index;
            cycle_size++;
        }

        if (cycle_size > 0)
            swaps += cycle_size - 1;
    }

    free(pairs);
    free(visited);
    return swaps;
}

int lilysHomework(int arr_count, int* arr) {
    int asc_swaps = countSwaps(arr, arr_count, true);
    int desc_swaps = countSwaps(arr, arr_count, false);
    return asc_swaps < desc_swaps ? asc_swaps : desc_swaps;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int n = parse_int(ltrim(rtrim(readline())));

    char** arr_temp = split_string(rtrim(readline()));

    int* arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        int arr_item = parse_int(*(arr_temp + i));
        *(arr + i) = arr_item;
    }

    int result = lilysHomework(n, arr);

    fprintf(fptr, "%d\n", result);

    fclose(fptr);
    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);
        if (!line) break;
        data_length += strlen(cursor);
        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') break;
        alloc_length <<= 1;
        data = realloc(data, alloc_length);
        if (!data) return '\0';
    }

    if (data[data_length - 1] == '\n') data[data_length - 1] = '\0';
    return data;
}

char* ltrim(char* str) {
    if (!str) return '\0';
    while (*str != '\0' && isspace(*str)) str++;
    return str;
}

char* rtrim(char* str) {
    if (!str) return '\0';
    char* end = str + strlen(str) - 1;
    while (end >= str && isspace(*end)) end--;
    *(end + 1) = '\0';
    return str;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");
    int spaces = 0;
    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);
        if (!splits) return splits;
        splits[spaces - 1] = token;
        token = strtok(NULL, " ");
    }
    return splits;
}

int parse_int(char* str) {
    char* endptr;
    int value = strtol(str, &endptr, 10);
    if (endptr == str || *endptr != '\0') exit(EXIT_FAILURE);
    return value;
}
