#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10000

// Node structure for queue
typedef struct {
    char str[1050]; // store number as string
    int rem;        // store remainder
} Node;

// Queue for BFS
Node queue[MAX];
int front, rear;

// Enqueue
void enqueue(Node n) {
    queue[rear++] = n;
}

// Dequeue
Node dequeue() {
    return queue[front++];
}

// Check if queue empty
int isEmpty() {
    return front == rear;
}

void findSpecialMultiple(int n) {
    int visited[505] = {0}; // visited remainders
    
    front = rear = 0;
    
    // Start with "9"
    Node start;
    strcpy(start.str, "9");
    start.rem = 9 % n;
    
    enqueue(start);
    visited[start.rem] = 1;
    
    while (!isEmpty()) {
        Node cur = dequeue();
        
        if (cur.rem == 0) {
            printf("%s\n", cur.str);
            return;
        }
        
        // Append '0'
        Node next;
        sprintf(next.str, "%s0", cur.str);
        next.rem = (cur.rem * 10) % n;
        if (!visited[next.rem]) {
            enqueue(next);
            visited[next.rem] = 1;
        }
        
        // Append '9'
        sprintf(next.str, "%s9", cur.str);
        next.rem = (cur.rem * 10 + 9) % n;
        if (!visited[next.rem]) {
            enqueue(next);
            visited[next.rem] = 1;
        }
    }
}

int main() {
    int T, N;
    scanf("%d", &T);
    
    while (T--) {
        scanf("%d", &N);
        findSpecialMultiple(N);
    }
    return 0;
}
