//Driver Code Starts{
// C++ program for level order traversal of Binary Tree
// Using Queue
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node {
  public:
    int data;
    Node *left, *right;

    // Constructor to initialize a new node
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};
//Driver Code Ends }


// Iterative method to find height of Binary Tree
vector<vector<int>> levelOrder(Node *root) {
    if (root == nullptr)
        return {};

    // Create an empty queue for level order traversal
    queue<Node *> q;
    vector<vector<int>> res;

    // Enqueue Root
    q.push(root);
    int currLevel = 0;

    while (!q.empty()) {
        int len = q.size();
        res.push_back({});

        for (int i = 0; i < len; i++) {

            // Add front of queue and remove it from queue
            Node *node = q.front();
            q.pop();

            res[currLevel].push_back(node->data);

            // Enqueue left child
            if (node->left != nullptr)
                q.push(node->left);

            // Enqueue right child
            if (node->right != nullptr)
                q.push(node->right);
        }
        currLevel++;
    }
    return res;
}


//Driver Code Starts{
int main() {
    // Create binary tree
    //      1         
    //     / \       
    //    3   2      
    //          \   
    //           4 
    //          /  \
    //         6    5
    Node *root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(2);
    root->right->right = new Node(4);
    root->right->right->left = new Node(6);
    root->right->right->right = new Node(5);

    // Perform level order traversal
    vector<vector<int>> res = levelOrder(root);

    // Print the result
    for (vector<int> level : res)
        for (int data : level)
            cout << data << " ";
}
//Driver Code Ends }