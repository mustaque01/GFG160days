// C++ program to check if a tree is height-balanced or not 
// Using Bottom Up Recursion

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int d) {
        int data = d;
        left = right = NULL;
    }
};

// Function that returns the height of the tree if the tree is balanced
// Otherwise it returns -1.
int isBalancedRec(Node* root) {
  
      // Base case: Height of empty tree is zero
    if (root == NULL)
        return 0;
      
      // Find Heights of left and right sub trees
    int lHeight = isBalancedRec(root->left);
    int rHeight = isBalancedRec(root->right);
      
      // If either the subtrees are unbalanced or the absolute difference  
      // of their heights is greater than 1, return -1
    if (lHeight == -1 || rHeight == -1 || abs(lHeight - rHeight) > 1)
        return -1;
          
      // Return the height of the tree
    return max(lHeight, rHeight) + 1;
}

// Function to check if tree is height balanced
bool isBalanced(Node *root) {
      return (isBalancedRec(root) > 0);
}

int main() {
    // Representation of input BST:
    //            1
    //           / \
    //          2   3
    //         /  \
    //        4   5 
    //       /
    //      8
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(8);

    cout << (isBalanced(root) ? "True" : "False");
    return 0;
}