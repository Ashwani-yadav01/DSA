#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

// find (with path compression)
int find(int parent[], int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent, parent[x]);
}

// simple union (no rank)
void unite(int parent[], int x, int y) {
    int px = find(parent, x);
    int py = find(parent, y);

    if (px != py)
        parent[px] = py;
}

// function
int kruskalMST(int V, vector<Edge>& edges) {

    // sort edges by weight
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.w < b.w;
    });

    int parent[V];
    for (int i = 0; i < V; i++)
        parent[i] = i;

    int cost = 0;

    for (auto e : edges) {
        if (find(parent, e.u) != find(parent, e.v)) {
            cost += e.w;
            unite(parent, e.u, e.v);
        }
    }

    return cost;
}