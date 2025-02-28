//Driver Code Starts{
// C++ program to find maximum path sum in Binary Tree
#include <iostream>
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


// Returns the maximum path sum in the subtree with the current node as an endpoint. 
// Also updates 'res' with the maximum path sum.
int maxPathSumUtil(Node* root, int& res) {
  
    // Base case: return 0 for a null node
    if (root == NULL)
        return 0;

    // Calculate maximum path sums for left and right subtrees
    int l = max(0, maxPathSumUtil(root->left, res));
    int r = max(0, maxPathSumUtil(root->right, res));

    // Update 'res' with the maximum path sum passing through the current node
    res = max(res, l + r + root->data);

    // Return the maximum path sum rooted at this node
    return root->data + max(l, r);
}

// Returns maximum path sum in tree with given root
int maxPathSum(Node* root) {
    int res = root->data;
    
      // Compute maximum path sum and store it in 'res'
    maxPathSumUtil(root, res);
  
    return res;
}


//Driver Code Starts{
int main() {
      
    // Representation of input binary tree:
    //            10
    //           /  \
    //          2    10
    //         / \     \  
    //        20  1    -25
      //                 /  \
      //                  3       4
    Node* root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(10);
    root->left->left = new Node(20);
    root->left->right = new Node(1);
    root->right->right = new Node(-25);
    root->right->right->left = new Node(3);
    root->right->right->right = new Node(4);

    cout << maxPathSum(root);
    return 0;
}
//Driver Code Ends }