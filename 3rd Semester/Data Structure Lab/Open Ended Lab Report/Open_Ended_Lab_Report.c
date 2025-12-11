#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 9
#define NAME_LEN 32
#define ROUTE_LEN 64
#define BUF_LEN 256

char blocks[MAX][NAME_LEN];
char pathName[MAX][MAX][ROUTE_LEN];

int queue_arr[MAX];
int front_q, rear_q;

void trim(char *s) {
    int n = strlen(s);
    while (n > 0 && (s[n-1]=='\n' || s[n-1]=='\r' || s[n-1]==' ' || s[n-1]=='\t')) {
        s[n-1]='\0';
        n--;
    }
}

int getIndex(const char *name) {
    for (int i = 0; i < MAX; i++) {
        if (strlen(blocks[i])==0) continue;
        if (strcmp(blocks[i], name)==0) return i;
    }
    return -1;
}

int enqueue(int v) {
    if (rear_q >= MAX) return -1;
    queue_arr[rear_q++] = v;
    return 0;
}

int dequeue(int *out) {
    if (front_q >= rear_q) return -1;
    *out = queue_arr[front_q++];
    return 0;
}

int insertRoute(const char *b1, const char *b2, const char *rname) {
    int x = getIndex(b1);
    int y = getIndex(b2);
    if (x==-1 || y==-1) return -1;
    strncpy(pathName[x][y], rname, ROUTE_LEN-1);
    pathName[x][y][ROUTE_LEN-1]='\0';
    strncpy(pathName[y][x], rname, ROUTE_LEN-1);
    pathName[y][x][ROUTE_LEN-1]='\0';
    return 0;
}

int deleteRoute(const char *b1, const char *b2) {
    int x = getIndex(b1);
    int y = getIndex(b2);
    if (x==-1 || y==-1) return -1;
    pathName[x][y][0]='\0';
    pathName[y][x][0]='\0';
    return 0;
}

void initEmptyGraph() {
    for (int i = 0; i < MAX; i++) {
        blocks[i][0]='\0';
        for (int j = 0; j < MAX; j++) pathName[i][j][0]='\0';
    }
}

void showAdjacency() {
    printf("Current routes between blocks:\n");
    for (int i = 0; i < MAX; i++) {
        if (strlen(blocks[i])==0) continue;
        for (int j = 0; j < MAX; j++) {
            if (strlen(pathName[i][j])!=0) {
                printf("%s <-> %s : %s\n", blocks[i], blocks[j], pathName[i][j]);
            }
        }
    }
}

int bfs(int src, int dest, int parent[], int visited[]) {
    for (int i = 0; i < MAX; i++) {
        visited[i]=0;
        parent[i]=-1;
    }
    front_q = rear_q = 0;

    enqueue(src);
    visited[src]=1;

    while (front_q < rear_q) {
        int curr;
        dequeue(&curr);
        if (curr == dest) return 1;
        for (int next = 0; next < MAX; next++) {
            if (strlen(pathName[curr][next])!=0 && !visited[next]) {
                visited[next]=1;
                parent[next]=curr;
                enqueue(next);
            }
        }
    }
    return visited[dest];
}

void printPath(int parent[], int src, int dest) {
    if (src == dest) {
        printf("Start and destination are same: %s\n", blocks[src]);
        return;
    }
    int path[MAX], len=0;
    int cur = dest;
    while (cur != -1) {
        path[len++] = cur;
        cur = parent[cur];
    }
    if (strcmp(blocks[path[len-1]], blocks[src])!=0) {
        printf("No path found.\n");
        return;
    }
    printf("Route from %s to %s:\n", blocks[src], blocks[dest]);
    for (int i = len-1; i > 0; i--) {
        int a = path[i];
        int b = path[i-1];
        printf("Take %s from %s to %s\n", pathName[a][b], blocks[a], blocks[b]);
    }
    printf("Arrived at %s.\n", blocks[dest]);
}

int main() {
    char line[BUF_LEN];
    initEmptyGraph();

    printf("=== City Navigation Program ===\n");
    printf("Choose input method:\n");
    printf("1) Manual input of blocks and routes\n");
    printf("2) Use default map\n> ");
    fgets(line,sizeof(line),stdin);
    int choice = atoi(line);

    if(choice == 2) {
        const char *def[MAX] = {"A","B","C","D","E","F","G","H","I"};
        for(int i=0;i<MAX;i++) strncpy(blocks[i],def[i],NAME_LEN-1);

        insertRoute("A","B","Street 1");
        insertRoute("B","C","Street 1");
        insertRoute("D","E","Street 2");
        insertRoute("E","F","Street 2");
        insertRoute("G","H","Street 3");
        insertRoute("H","I","Street 3");
        insertRoute("A","D","Road 1");
        insertRoute("D","G","Road 1");
        insertRoute("B","E","Road 2");
        insertRoute("E","H","Road 2");
        insertRoute("C","F","Road 3");
        insertRoute("F","I","Road 3");
        printf("Default map loaded.\n");
    } else {
        printf("Enter 9 block names separated by spaces (example: A B C D E F G H I): ");
        fgets(line,sizeof(line),stdin);
        trim(line);
        char *tok=strtok(line," ");
        int i=0;
        while (tok && i<MAX) {
            strncpy(blocks[i],tok,NAME_LEN-1);
            tok=strtok(NULL," ");
            i++;
        }
        if (i!=MAX) { printf("Invalid number of blocks.\n"); return 1; }

        printf("Enter number of connections between blocks (example: 5): ");
        fgets(line,sizeof(line),stdin);
        int edges=atoi(line);

        for (int e=0;e<edges;e++) {
            printf("Enter connection %d (format: Block1 Block2 RouteName): ", e+1);
            fgets(line,sizeof(line),stdin);
            trim(line);
            char b1[NAME_LEN], b2[NAME_LEN], r[ROUTE_LEN];
            if (sscanf(line,"%s %s %[^\n]",b1,b2,r)<3) { e--; continue; }
            if (insertRoute(b1,b2,r)!=0) { e--; continue; }
        }
    }

    while (1) {
        printf("\nMenu:\n");
        printf("1) Show all routes\n");
        printf("2) Find route between two blocks\n");
        printf("3) Insert a new route\n");
        printf("4) Delete an existing route\n");
        printf("5) Exit program\n> ");
        fgets(line,sizeof(line),stdin);
        int cmd=atoi(line);

        if (cmd==1) {
            showAdjacency();

        } else if (cmd==2) {
            char s[NAME_LEN], d[NAME_LEN];
            printf("Enter source block name: ");
            fgets(line,sizeof(line),stdin); trim(line); strncpy(s,line,NAME_LEN-1);

            printf("Enter destination block name: ");
            fgets(line,sizeof(line),stdin); trim(line); strncpy(d,line,NAME_LEN-1);

            int src=getIndex(s), dest=getIndex(d);
            if (src==-1 || dest==-1) { printf("Invalid block name.\n"); continue; }

            int parent[MAX], visited[MAX];
            if (!bfs(src,dest,parent,visited)) printf("No path found.\n");
            else printPath(parent,src,dest);

        } else if (cmd==3) {
            printf("Enter route to insert (format: Block1 Block2 RouteName): ");
            char b1[NAME_LEN], b2[NAME_LEN], r[ROUTE_LEN];
            fgets(line,sizeof(line),stdin);
            if (sscanf(line,"%s %s %[^\n]",b1,b2,r)<3) { printf("Invalid format.\n"); continue; }
            insertRoute(b1,b2,r);
            printf("Route inserted successfully.\n");

        } else if (cmd==4) {
            printf("Enter route to delete (format: Block1 Block2): ");
            char b1[NAME_LEN], b2[NAME_LEN];
            fgets(line,sizeof(line),stdin);
            if (sscanf(line,"%s %s",b1,b2)<2) { printf("Invalid format.\n"); continue; }
            deleteRoute(b1,b2);
            printf("Route deleted successfully.\n");

        } else if (cmd==5) {
            printf("Exiting program. Goodbye!\n");
            break;
        } else {
            printf("Invalid menu choice. Please enter 1-5.\n");
        }
    }

    return 0;
}
