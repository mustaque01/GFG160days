// C++ program to find the diameter
// of a binary tree.
#include <iostream>
#include <algorithm>
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

// Recursive function which finds the 
// height of root and also calculates 
// the diameter of the tree.
int diameterRecur(Node* root, int &res) {
  
    // Base case: tree is empty
    if (root == nullptr)
        return 0;
    
    // find the height of left and right subtree
    // (it will also find of diameter for left 
    // and right subtree).
    int lHeight = diameterRecur(root->left, res);
    int rHeight = diameterRecur(root->right, res);
    
    // Check if diameter of root is greater
    // than res.
    res = max(res, lHeight+rHeight);
    
    // return the height of current subtree.
    return 1 + max(lHeight, rHeight);
}

// Function to get diameter of a binary tree
int diameter(Node* root) {
  
    int res = 0;
    diameterRecur(root, res);
    return res;
}

int main() {

    // Constructed binary tree is
    //          5
    //        /   \
    //       8     6
    //      / \   /
    //     3   7 9
    Node* root = new Node(5);
    root->left = new Node(8);
    root->right = new Node(6);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
      root->right->left = new Node(9);
    cout << diameter(root) << endl;
  
    return 0;
}