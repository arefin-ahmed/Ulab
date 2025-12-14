#include <stdio.h> // Standard input-output library
#define MAX 20 // Maximum number of vertices allowed

int adj[MAX][MAX]; // Adjacency matrix to store graph
int visited[MAX];  // Array to track visited vertices
int queue[MAX];    // Queue for BFS
int stack[MAX];    // Stack for DFS without recursion
int n;             // Number of vertices in the graph

/* Function to create adjacency matrix */
void createGraph(int directed)
{
    int i, j; // Loop variables

    // Ask user for number of vertices
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize adjacency matrix with 0 (no edges)
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            adj[i][j] = 0; // No edge between i and j
        }
    }

    // Take adjacency matrix input from user
    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]); // Read edge value
            if (!directed)
                adj[j][i] = adj[i][j]; // Mirror edge for undirected graph
        }
    }
}

/* BFS traversal using queue */
void BFS(int start)
{
    int front = 0; // Front of queue
    int rear = 0;  // Rear of queue
    int i;         // Loop variable

    // Mark all vertices as unvisited
    for (i = 0; i < n; i++)
        visited[i] = 0;

    // Insert starting vertex into queue
    queue[rear++] = start;
    visited[start] = 1; // Mark start vertex as visited

    printf("BFS Traversal: ");

    // Continue until queue becomes empty
    while (front < rear)
    {
        int current = queue[front++]; // Remove element from queue
        printf("%d ", current);       // Print visited vertex

        // Visit all adjacent vertices
        for (i = 0; i < n; i++)
        {
            // If edge exists and vertex not visited
            if (adj[current][i] == 1 && visited[i] == 0)
            {
                queue[rear++] = i; // Add vertex to queue
                visited[i] = 1;    // Mark it visited
            }
        }
    }
    printf("\n");
}

/* DFS using recursion */
void DFS_Recursive(int start)
{
    int i; // Loop variable

    printf("%d ", start); // Print current vertex
    visited[start] = 1;   // Mark it as visited

    // Visit all adjacent vertices recursively
    for (i = 0; i < n; i++)
    {
        // If edge exists and vertex not visited
        if (adj[start][i] == 1 && visited[i] == 0)
        {
            DFS_Recursive(i); // Recursive DFS call
        }
    }
}

/* DFS without recursion using stack */
void DFS_Iterative(int start)
{
    int top = -1; // Initialize stack top
    int i;        // Loop variable

    // Mark all vertices as unvisited
    for (i = 0; i < n; i++)
        visited[i] = 0;

    // Push starting vertex into stack
    stack[++top] = start;

    printf("DFS Traversal (Without Recursion): ");

    // Continue until stack becomes empty
    while (top != -1)
    {
        int current = stack[top--]; // Pop vertex from stack

        // If vertex not visited
        if (visited[current] == 0)
        {
            printf("%d ", current); // Print vertex
            visited[current] = 1;   // Mark it visited
        }

        // Push adjacent vertices in reverse order
        for (i = n - 1; i >= 0; i--)
        {
            // If edge exists and vertex not visited
            if (adj[current][i] == 1 && visited[i] == 0)
            {
                stack[++top] = i; // Push vertex into stack
            }
        }
    }
    printf("\n");
}

int main()
{
    int choice; // Graph type choice
    int start;  // Starting vertex
    int i;      // Loop variable

    // Ask user for graph type
    printf("Graph Type:\n");
    printf("1. Undirected Graph\n");
    printf("2. Directed Graph\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    // Create graph based on user choice
    if (choice == 1)
        createGraph(0); // Undirected graph
    else
        createGraph(1); // Directed graph

    // Ask for starting vertex
    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    // Perform BFS
    BFS(start);

    // Reset visited array for DFS
    for (i = 0; i < n; i++)
        visited[i] = 0;

    // Perform DFS using recursion
    printf("DFS Traversal (With Recursion): ");
    DFS_Recursive(start);
    printf("\n");

    // Perform DFS without recursion
    DFS_Iterative(start);

    return 0; // Program ends successfully
}
