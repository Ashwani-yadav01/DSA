#include <iostream>
#include <climits>
using namespace std;

#define N 8   // number of nodes

int main() {
    // adjacency matrix (0 means no edge)
    int graph[N][N] = {
        {0,1,2,5,0,0,0,0},
        {0,0,0,0,4,11,0,0},
        {0,0,0,0,9,5,16,0},
        {0,0,0,0,0,0,2,0},
        {0,0,0,0,0,0,0,18},
        {0,0,0,0,0,0,0,13},
        {0,0,0,0,0,0,0,2},
        {0,0,0,0,0,0,0,0}
    };

    int cost[N];
    int d[N]; // to store path

    cost[N-1] = 0; // destination cost = 0

    // compute from back
    for (int i = N-2; i >= 0; i--) {
        cost[i] = INT_MAX;

        for (int j = i+1; j < N; j++) {
            if (graph[i][j] != 0) {
                if (graph[i][j] + cost[j] < cost[i]) {
                    cost[i] = graph[i][j] + cost[j];
                    d[i] = j;
                }
            }
        }
    }

    // print minimum cost
    cout << "Minimum cost: " << cost[0] << endl;

    // print path
    cout << "Path: ";
    int i = 0;
    while (i != N-1) {
        cout << i << " -> ";
        i = d[i];
    }
    cout << N-1;
}