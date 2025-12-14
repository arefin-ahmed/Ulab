#include <stdio.h>

#define MAX 20

int adj[MAX][MAX];
int visited[MAX];
int queue[MAX];
int stack[MAX];
int n;

void createGraph(int directed)
{
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            adj[i][j] = 0;

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
            if (!directed)
                adj[j][i] = adj[i][j];
        }
    }
}

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

void DFS_Recursive(int start)
{
    int i;

    printf("%d ", start);
    visited[start] = 1;

    for (i = 0; i < n; i++)
    {
        if (adj[start][i] == 1 && visited[i] == 0)
            DFS_Recursive(i);
    }
}

void DFS_Iterative(int start)
{
    int top = -1;
    int i;

    for (i = 0; i < n; i++)
        visited[i] = 0;

    stack[++top] = start;

    printf("DFS Traversal (Without Recursion): ");

    while (top != -1)
    {
        int current = stack[top--];

        if (visited[current] == 0)
        {
            printf("%d ", current);
            visited[current] = 1;
        }

        for (i = n - 1; i >= 0; i--)
        {
            if (adj[current][i] == 1 && visited[i] == 0)
                stack[++top] = i;
        }
    }
    printf("\n");
}

int main()
{
    int choice, start, i;

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

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("DFS Traversal (With Recursion): ");
    DFS_Recursive(start);
    printf("\n");

    DFS_Iterative(start);

    return 0;
}
