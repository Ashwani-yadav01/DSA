#include <stdio.h>
#define MAX 100

void dfsUsingStack(int graph[MAX][MAX], int n, int start)
{
    int visited[MAX] = {0};
    int stack[MAX];
    int top = -1;

    // Push starting node
    stack[++top] = start;

    printf("DFS Traversal (using stack): ");

    while (top != -1)
    {
        int node = stack[top--]; // pop

        if (!visited[node])
        {
            printf("%d ", node);
            visited[node] = 1;
        }

        // Push unvisited adjacent nodes onto the stack
        // (loop in reverse order to match recursive DFS order)
        for (int i = n - 1; i >= 0; i--)
        {
            if (graph[node][i] == 1 && !visited[i])
            {
                stack[++top] = i;
            }
        }
    }

    printf("\n");
}

int main()
{
    int n = 5; // number of vertices

    // same graph as before
    int graph[MAX][MAX] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 0, 1},
        {0, 1, 0, 0, 0},
        {0, 1, 1, 0, 0}
    };

    int start = 3;
    dfs(graph, n, start);

    return 0;
}
