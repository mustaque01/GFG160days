//Driver Code Starts{
// C++ code for Vertical Traversal of a Binary Tree 
// using HashMap and DFS (Depth First Search)

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    
    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
//Driver Code Ends }


// Helper function to perform DFS and 
// store nodes at different horizontal distances
void DFS(Node* root, int hd, int &mn, 
                 unordered_map<int, vector<int>> &mp) {
    if (root == nullptr) 
        return;
    
    // Store the current node in the map at horizontal distance hd
    mp[hd].push_back(root->data);
    
    // Update the minimum horizontal distance
    mn = min(mn, hd);
    
    // Recursively traverse the left and right subtrees
    DFS(root->left, hd - 1, mn, mp);  
    DFS(root->right, hd + 1, mn, mp);
}

// Function to perform vertical order traversal of a binary tree
vector<vector<int>> verticalOrder(Node *root) {
  
    // HashMap to store nodes at each horizontal distance
    unordered_map<int, vector<int>> mp;
    
    // Variable to track the minimum horizontal distance
    int mn = 0; 

    // Perform DFS to fill the hashmap with vertical levels
    DFS(root, 0, mn, mp);
    
    vector<vector<int>> res;
    int hd = mn;

    // Traverse the map from minimum to maximum horizontal distance
    while(mp.find(hd) != mp.end()) {
        res.push_back(mp[hd]);
        hd++;
    }
  
    return res;
}


//Driver Code Starts{
int main() {
  
    // Constructing the binary tree:
    //        1
    //       / \
    //      2   3
    //     / \ / \
    //    4  5 6  7
    //          \  \
    //           8  9
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);
    root->right->right->right = new Node(9);
  
    vector<vector<int>> res = verticalOrder(root);
    
    for(vector<int> temp: res) {
        cout << "[ ";
        for (int val: temp) 
            cout << val << " ";
        cout << "] ";
    }
    
    return 0;
}

//Driver Code Ends }