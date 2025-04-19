#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

// Definition for a Node
struct Node {
    int val;
    vector<Node*> neighbors;
};

// Map to hold original node to its copy
unordered_map<Node*, Node*> copies;

// Function to clone the graph 
Node* cloneGraph(Node* node) {
    
    // If the node is NULL, return NULL
    if (!node) return NULL;

    // If node is not yet cloned, clone it
    if (copies.find(node) == copies.end()) {
        Node* clone = new Node();
        clone->val = node->val;
        copies[node] = clone;

        // Recursively clone neighbors
        for (Node* neighbor : node->neighbors) {
            clone->neighbors.push_back(cloneGraph(neighbor));
        }
    }

    // Return the clone
    return copies[node];
}

// Build graph
Node* buildGraph() {
    Node* node1 = new Node(); node1->val = 0;
    Node* node2 = new Node(); node2->val = 1;
    Node* node3 = new Node(); node3->val = 2;
    Node* node4 = new Node(); node4->val = 3;

    node1->neighbors = {node2, node3};
    node2->neighbors = {node1, node3};
    node3->neighbors = {node1,node2, node4};
    node4->neighbors = {node3};

    return node1;
}

// Compare two graphs for structural and value equality
bool compareGraphs(Node* node1, Node* node2, map<Node*, Node*>& visited) {
    if (!node1 || !node2) 
        return node1 == node2;

    if (node1->val != node2->val || node1 == node2)
        return false;

    visited[node1] = node2;

    if (node1->neighbors.size() != node2->neighbors.size()) 
        return false;

    for (size_t i = 0; i < node1->neighbors.size(); ++i) {
        Node* n1 = node1->neighbors[i];
        Node* n2 = node2->neighbors[i];

        if (visited.count(n1)) {
            if (visited[n1] != n2) 
                return false;
        } else {
            if (!compareGraphs(n1, n2, visited))
                return false;
        }
    }

    return true;
}

// Driver Code
int main() {
    Node* original = buildGraph();

    // Clone the graph
    Node* cloned = cloneGraph(original);

    // Compare original and cloned graph
    map<Node*, Node*> visited;
    cout << (compareGraphs(original, cloned, visited) ? 
             "true" : "false") << endl;

    return 0;
}