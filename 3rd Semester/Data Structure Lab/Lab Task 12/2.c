#include <stdio.h>

#define MAX 20

int adj[MAX][MAX];
int visited[MAX];
int queue[MAX];
int n; // number of vertices

// Function to create adjacency matrix
void createGraph(int directed)
{
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize matrix with 0
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            adj[i][j] = 0;
        }
    }

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
            if (!directed)
            {
                adj[j][i] = adj[i][j];
            }
        }
    }
}

// BFS Traversal
void BFS(int start)
{
    int front = 0, rear = 0;
    int i;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    queue[rear++] = start;
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (front < rear)
    {
        int current = queue[front++];
        printf("%d ", current);

        for (i = 0; i < n; i++)
        {
            if (adj[current][i] == 1 && visited[i] == 0)
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

// DFS Traversal
void DFS(int start)
{
    int i;
    printf("%d ", start);
    visited[start] = 1;

    for (i = 0; i < n; i++)
    {
        if (adj[start][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}

int main()
{
    int choice, start;

    printf("Graph Type:\n");
    printf("1. Undirected Graph\n");
    printf("2. Directed Graph\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice == 1)
        createGraph(0);
    else
        createGraph(1);

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    BFS(start);

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("DFS Traversal: ");
    DFS(start);
    printf("\n");

    return 0;
}
