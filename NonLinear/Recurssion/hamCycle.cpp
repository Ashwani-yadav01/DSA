#include <iostream>
using namespace std;

#define V 4

int path[V];

// check if vertex v can be placed at position pos
bool isSafe(int v, int graph[V][V], int pos) {
    // must be adjacent to previous vertex
    if (graph[path[pos - 1]][v] == 0)
        return false;

    // must not be already in path
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

// recursive function
bool solve(int graph[V][V], int pos) {
    // if all vertices included
    if (pos == V) {
        // check last to first connection
        return graph[path[pos - 1]][path[0]] == 1;
    }

    for (int v = 1; v < V; v++) {
        if (isSafe(v, graph, pos)) {
            path[pos] = v;

            if (solve(graph, pos + 1))
                return true;

            path[pos] = -1; // backtrack
        }
    }
    return false;
}

int main() {
    int graph[V][V] = {
        {0,1,1,0},
        {1,0,1,1},
        {1,1,0,1},
        {0,1,1,0}
    };

    for (int i = 0; i < V; i++)
        path[i] = -1;

    path[0] = 0; // start from 0

    if (solve(graph, 1)) {
        for (int i = 0; i < V; i++)
            cout << path[i] << " ";
        cout << path[0]; // complete cycle
    } else {
        cout << "No cycle";
    }
}