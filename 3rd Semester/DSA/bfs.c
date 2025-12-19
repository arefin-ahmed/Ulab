#include <stdio.h>

#define MAX 20

int graph[MAX][MAX], visited[MAX];
int queue[MAX], front = -1, rear = -1;
int n;

// Queue operations
void enqueue(int v) {
    queue[++rear] = v;
}

int dequeue() {
    return queue[++front];
}

// BFS Traversal
void bfs(int start) {
    enqueue(start);
    visited[start] = 1;

    while (front != rear) {
        int v = dequeue();
        printf("%d ", v);

        for (int i = 0; i < n; i++) {
            if (graph[v][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("BFS Traversal: ");
    bfs(start);

    return 0;
}
