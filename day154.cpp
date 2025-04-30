#include <bits/stdc++.h>
using namespace std;

// Construct adjacency list
vector<vector<vector<int>>> constructadj(int V, 
                             vector<vector<int>>& edges) {
                                 
    vector<vector<vector<int>>> adj(V);
    for (auto& edge : edges) {
        int u = edge[0], v = edge[1], w = edge[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    return adj;
}

// find sortest path between src and dest.
int shortestPath(int V, vector<vector<vector<int>>>& adj, int src, int dest){
    
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // priority queue
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        pair<int, int> top = pq.top(); 
        pq.pop();
        int d = top.first, u = top.second;

        if (d > dist[u]) continue;

        for (auto& neighbor : adj[u]) {
            int v = neighbor[0];
            int w = neighbor[1];

            // Skip the ignored edge
            if ((u == src && v == dest) || (u == dest && v == src)) continue;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist[dest];
}

// Function to find the minimum weight cycle in the graph
int findMinCycle(int V, vector<vector<int>>& edges) {
    vector<vector<vector<int>>> adj = constructadj(V, edges);
    int minCycle = INT_MAX;

    for (const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        int dist = shortestPath(V, adj, u, v);

        if (dist != INT_MAX) {
            minCycle = min(minCycle, dist + w);
        }
    }

    return minCycle;
}

// Driver code
int main() {
    int V = 5;

    vector<vector<int>> edges = {
         {0, 1, 2}, {1, 2, 2}, {1, 3, 1}, 
         {1, 4, 1}, {0, 4, 3}, {2, 3, 4}
    };

    cout << findMinCycle(V, edges) << endl;

    return 0;
}