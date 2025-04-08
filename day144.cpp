#include <bits/stdc++.h>
using namespace std;

// Function to construct adjacency list from the given edges
vector<vector<int>> constructAdj(int V, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(V);
    for (auto &edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);
        // Directed edge from edge[0] to edge[1]
    }
    return adj;
}

// Function to check if a cycle exists in the directed graph using Kahn's Algorithm (BFS)
bool isCyclic(int V, vector<vector<int>> &edges)
{
    vector<vector<int>> adj = constructAdj(V, edges);
    // Build the adjacency list

    vector<int> inDegree(V, 0); // Array to store in-degree of each vertex
    queue<int> q;               // Queue to store nodes with in-degree 0
    int visited = 0;            // Count of visited (processed) nodes

    // Step 1: Compute in-degrees of all vertices
    for (int u = 0; u < V; ++u)
    {
        for (int v : adj[u])
        {
            inDegree[v]++;
        }
    }

    //  Add all vertices with in-degree 0 to the queue
    for (int u = 0; u < V; ++u)
    {
        if (inDegree[u] == 0)
        {
            q.push(u);
        }
    }

    // Perform BFS (Topological Sort)
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        visited++;

        // Reduce in-degree of neighbors
        for (int v : adj[u])
        {
            inDegree[v]--;
            if (inDegree[v] == 0)
            {
                // Add to queue when in-degree becomes 0
                q.push(v);
            }
        }
    }

    //  If visited nodes != total nodes, a cycle exists
    return visited != V;
}

int main()
{
    int V = 4; // Number of vertices
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 0}, {2, 3}};

    // Output: true (cycle exists)
    cout << (isCyclic(V, edges) ? "true" : "false") << endl;

    return 0;
}