#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Pair {
public:
    int node, weight;
    Pair(int n, int w) {
        node = n;
        weight = w;
    }
};

int prims(int V, vector<vector<Pair>>& adj) {

    vector<bool> visited(V, false);

    // min heap → based on weight
    priority_queue<Pair, vector<Pair>, 
        function<bool(Pair, Pair)>> pq(
        [](Pair a, Pair b) {
            return a.weight > b.weight;
        }
    );

    pq.push(Pair(0, 0));

    int mstWeight = 0;

    while (!pq.empty()) {

        Pair curr = pq.top();
        pq.pop();

        int node = curr.node;
        int wt = curr.weight;

        if (visited[node]) continue;

        visited[node] = true;
        mstWeight += wt;

        for (auto neighbor : adj[node]) {
            int adjNode = neighbor.node;
            int edgeWeight = neighbor.weight;

            if (!visited[adjNode]) {
                pq.push(Pair(adjNode, edgeWeight));
            }
        }
    }

    return mstWeight;
}

int main() {

    int V = 4;
    vector<vector<Pair>> adj(V);

    adj[0].push_back(Pair(1, 2));
    adj[1].push_back(Pair(0, 2));

    adj[0].push_back(Pair(2, 6));
    adj[2].push_back(Pair(0, 6));

    adj[0].push_back(Pair(3, 3));
    adj[3].push_back(Pair(0, 3));

    adj[1].push_back(Pair(3, 8));
    adj[3].push_back(Pair(1, 8));

    adj[2].push_back(Pair(3, 5));
    adj[3].push_back(Pair(2, 5));

    int result = prims(V, adj);

    cout << "Weight of MST: " << result;
}