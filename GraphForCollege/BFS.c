#include <stdio.h>
#define MAX 100

void bfs(int graph[MAX][MAX], int n, int start)
{
    int visited[MAX] = {0};
    int queue[MAX];
    int front = 0, rear = 0;
    visited[start] = 1;
    queue[rear++] = start;
    printf("BFS Traversal: ");
    while (front < rear)
    {
        int node = queue[front++];
        printf("%d ", node);

        for (int i = 0; i < n; i++)
        {
            if (graph[node][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}


int main()
{
    int n = 5; // number of vertices

    // Adjacency matrix for example graph
    int graph[MAX][MAX] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 0, 1},
        {0, 1, 0, 0, 0},
        {0, 1, 1, 0, 0}
    };

    int start = 1; // start BFS from vertex 0

    bfs(graph, n, start);

    return 0;
}
