#include <stdio.h>
#include <string.h>

#define MAX 9
#define INF 9999

char blocks[MAX];                     // USER-DEFINED block names
char pathName[MAX][MAX][20];          // USER-DEFINED street/road names

int queue[MAX], front = 0, rear = 0;

// Get index of a block
int getIndex(char c)
{
    for (int i = 0; i < MAX; i++)
        if (blocks[i] == c)
            return i;
    return -1;
}

// BFS for shortest path
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

// Print instructions
void printPath(int parent[], int src, int dest)
{
    int path[MAX], length = 0, temp = dest;

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
    // GET ALL BLOCK NAMES (dynamic)
    printf("Enter 9 block names (e.g., A B C D E F G H I):\n");
    for (int i = 0; i < MAX; i++)
        scanf(" %c", &blocks[i]);

    // Clear all path names
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            strcpy(pathName[i][j], "");

    printf("\nHow many connections? ");
    int edges;
    scanf("%d", &edges);

    printf("\nEnter connections in this format:\n");
    printf("Block1 Block2 RoadName\n");
    printf("Example: A B Street_1\n\n");

    // USER ENTERS ALL ROAD/STREET CONNECTIONS
    for (int i = 0; i < edges; i++)
    {
        char b1, b2, name[20];
        scanf(" %c %c %s", &b1, &b2, name);

        int x = getIndex(b1);
        int y = getIndex(b2);

        if (x != -1 && y != -1)
        {
            strcpy(pathName[x][y], name);
            strcpy(pathName[y][x], name);
        }
        else
        {
            printf("Invalid block name in connection!\n");
            i--; // retry this connection
        }
    }

    // Input source + destination
    char s, d;
    printf("\nEnter source block: ");
    scanf(" %c", &s);
    printf("Enter destination block: ");
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



