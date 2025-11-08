#include <stdio.h>
#define MAX 100

void dfs(int graph[MAX][MAX], int n, int node, int visited[])
{
    printf("%d ", node);
    visited[node] = 1;

    for (int i = 0; i < n; i++)
    {
        if (graph[node][i] == 1 && visited[i] == 0)
        {
            dfs(graph, n, i, visited);
        }
    }
}


int main()
{
    int n = 5; // number of vertices

    // Same graph as BFS
    int graph[MAX][MAX] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 0, 1},
        {0, 1, 0, 0, 0},
        {0, 1, 1, 0, 0}
    };

    int visited[MAX] = {0};
    int start = 3; // start DFS from vertex 0

    printf("DFS Traversal: ");
    dfs(graph, n, start, visited);

    printf("\n");
    return 0;
}
