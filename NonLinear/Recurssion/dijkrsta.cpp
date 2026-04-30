#include <vector>
#include <queue>
#include <climits>
using namespace std;

// adj: adjacency list → adj[u] = { {v, weight}, ... }
// src: source vertex
vector<int> dijkstra(int V, vector<pair<int,int>> adj[], int src) {
    
    vector<int> dist(V, INT_MAX);

    // min heap → {distance, node}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        // skip outdated entries (important trick)
        if (d > dist[u]) continue;

        // relax neighbors
        for (auto x : adj[u]) {
            int v = x.first;
            int wt = x.second;

            if (dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}