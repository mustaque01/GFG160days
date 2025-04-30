#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Depth-first search function for topological sorting and cycle detection
bool dfs(int u, vector<vector<int>> &graph, vector<int> &vis, 
                                    vector<int> &rec, string &ans) {
    
    // Mark the node as visited and part of the current recursion stack
    vis[u] = rec[u] = 1;  

    for (int v = 0; v < 26; v++) {
        if (graph[u][v]) {  
            if (!vis[v]) {  
                // Recurse and check for cycle
                if (!dfs(v, graph, vis, rec, ans))  
                    return false;
            } else if (rec[v]) {
                 // A cycle is detected if v is already in the current recursion stack
                return false; 
            }
        }
    }
    // Add the character to the result after visiting all dependencies
    ans.push_back(char('a' + u));
    // Remove from recursion stack
    rec[u] = 0;  
    return true;
}

// Function to find the correct order of characters in an alien dictionary
string findOrder(vector<string> &words) {
    
    // Adjacency matrix for character precedence
    vector<vector<int>> graph(26, vector<int>(26, 0));
    // Marks if a character exists in the dictionary
    vector<int> exist(26, 0);  
    // Marks if a character has been visited
    vector<int> vis(26, 0);   
    // Recursion stack to detect cycles
    vector<int> rec(26, 0);   
    // Resultant character order
    string ans = "";          

    // Step 1: Mark all characters that appear in the input
    for (string word : words) {
        for (char ch : word) {
            exist[ch - 'a'] = 1;
        }
    }

    //Build the graph 
    for (int i = 0; i + 1 < words.size(); i++) {
        const string &a = words[i], &b = words[i + 1];
        int n = a.size(), m = b.size(), ind = 0;

        // Find the first different character between a and b
        while (ind < n && ind < m && a[ind] == b[ind])
            ind++;

        if (ind != n && ind == m)
            return "";

        
        if (ind < n && ind < m)
            graph[a[ind] - 'a'][b[ind] - 'a'] = 1;
    }

    
    for (int i = 0; i < 26; i++) {
        if (exist[i] && !vis[i]) {
            if (!dfs(i, graph, vis, rec, ans)) {
                // Return empty string if a cycle is found
                return "";  
            }
        }
    }
    // Reverse to get the correct topological order
    reverse(ans.begin(), ans.end());  
    return ans;
}

// Driver code to test the implementation
int main() {
    vector<string> words = {"baa", "abcd", "abca", "cab", "cad"};

    string order = findOrder(words);

    if (order.empty()) {
        cout << "No Ordering Possible" << endl;
    } else {
        cout << order << endl;
    }

    return 0;
}