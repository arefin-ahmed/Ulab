#include <stdio.h>
#include <string.h>

#define MAX 9
#define INF 9999

// Block names in index order
char blocks[MAX] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};

// Road/Street names adjacency matrix
// pathName[i][j] = name of connection from block i to j
char pathName[MAX][MAX][20];

// Queue for BFS
int queue[MAX], front = 0, rear = 0;

// Function to map block letter to index
int getIndex(char c)
{
    for (int i = 0; i < MAX; i++)
        if (blocks[i] == c)
            return i;
    return -1;
}

// BFS function to find shortest path
void bfs(int src, int parent[])
{
    int visited[MAX] = {0};

    front = rear = 0;
    queue[rear++] = src;
    visited[src] = 1;
    parent[src] = -1;

    while (front != rear)
    {
        int curr = queue[front++];

        for (int next = 0; next < MAX; next++)
        {
            if (strlen(pathName[curr][next]) != 0 && !visited[next])
            {
                visited[next] = 1;
                parent[next] = curr;
                queue[rear++] = next;
            }
        }
    }
}

// Print travel instructions
void printPath(int parent[], int src, int dest)
{
    int path[MAX], length = 0;
    int temp = dest;

    while (temp != -1)
    {
        path[length++] = temp;
        temp = parent[temp];
    }

    printf("Start at Block %c\n", blocks[src]);

    for (int i = length - 1; i > 0; i--)
    {
        int a = path[i];
        int b = path[i - 1];
        printf("Take %s\n", pathName[a][b]);
    }

    printf("Arrive at Block %c.\n", blocks[dest]);
}

int main()
{

    // Initialize all pathNames to empty
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            strcpy(pathName[i][j], "");

    // Insert bidirectional connections
    // Street 1: A-B, B-C
    strcpy(pathName[getIndex('A')][getIndex('B')], "Street 1");
    strcpy(pathName[getIndex('B')][getIndex('A')], "Street 1");
    strcpy(pathName[getIndex('B')][getIndex('C')], "Street 1");
    strcpy(pathName[getIndex('C')][getIndex('B')], "Street 1");

    // Street 2: D-E, E-F
    strcpy(pathName[getIndex('D')][getIndex('E')], "Street 2");
    strcpy(pathName[getIndex('E')][getIndex('D')], "Street 2");
    strcpy(pathName[getIndex('E')][getIndex('F')], "Street 2");
    strcpy(pathName[getIndex('F')][getIndex('E')], "Street 2");

    // Street 3: G-H, H-I
    strcpy(pathName[getIndex('G')][getIndex('H')], "Street 3");
    strcpy(pathName[getIndex('H')][getIndex('G')], "Street 3");
    strcpy(pathName[getIndex('H')][getIndex('I')], "Street 3");
    strcpy(pathName[getIndex('I')][getIndex('H')], "Street 3");

    // Road 1: A-D, D-G
    strcpy(pathName[getIndex('A')][getIndex('D')], "Road 1");
    strcpy(pathName[getIndex('D')][getIndex('A')], "Road 1");
    strcpy(pathName[getIndex('D')][getIndex('G')], "Road 1");
    strcpy(pathName[getIndex('G')][getIndex('D')], "Road 1");

    // Road 2: B-E, E-H
    strcpy(pathName[getIndex('B')][getIndex('E')], "Road 2");
    strcpy(pathName[getIndex('E')][getIndex('B')], "Road 2");
    strcpy(pathName[getIndex('E')][getIndex('H')], "Road 2");
    strcpy(pathName[getIndex('H')][getIndex('E')], "Road 2");

    // Road 3: C-F, F-I
    strcpy(pathName[getIndex('C')][getIndex('F')], "Road 3");
    strcpy(pathName[getIndex('F')][getIndex('C')], "Road 3");
    strcpy(pathName[getIndex('F')][getIndex('I')], "Road 3");
    strcpy(pathName[getIndex('I')][getIndex('F')], "Road 3");

    // Input
    char s, d;
    printf("Enter source block (A-I): ");
    scanf(" %c", &s);
    printf("Enter destination block (A-I): ");
    scanf(" %c", &d);

    int src = getIndex(s);
    int dest = getIndex(d);

    if (src == -1 || dest == -1)
    {
        printf("Invalid block input!\n");
        return 0;
    }

    int parent[MAX];
    bfs(src, parent);

    printf("\n--- Route ---\n");
    printPath(parent, src, dest);

    return 0;
}