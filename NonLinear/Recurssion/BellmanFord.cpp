#include <iostream>
#include <climits>
using namespace std;

int main() {
    int V = 4, E = 5;

    int u[] = {0, 0, 1, 1, 2};
    int v[] = {1, 2, 2, 3, 3};
    int w[] = {1, 4, 2, 6, 3};

    int dist[V];

    // initialize
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[0] = 0; // source

    // relax edges V-1 times
    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < E; j++) {
            if (dist[u[j]] != INT_MAX &&
                dist[u[j]] + w[j] < dist[v[j]]) {
                dist[v[j]] = dist[u[j]] + w[j];
            }
        }
    }

    // print result
    for (int i = 0; i < V; i++)
        cout << i << " -> " << dist[i] << endl;
}