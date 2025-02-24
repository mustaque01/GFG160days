//Driver Code Starts{
// C++ code to print Inorder Traversal
// of Binary Tree using Morris Traversal
#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
//Driver Code Ends }


// Function for inorder traversal 
// using Morris Traversal
vector<int> inOrder(Node* root) {
    vector<int> res;
    Node* curr = root;

    while (curr != nullptr) {
        if (curr->left == nullptr) {
          
            // If no left child, visit this node 
            // and go right
            res.push_back(curr->data);
            curr = curr->right;
        }
        else {
          
            // Find the inorder predecessor of curr
            Node* prev = curr->left;
            while (prev->right != nullptr &&
                                 prev->right != curr) {
                prev = prev->right;
            }

            // Make curr the right child of its 
            // inorder predecessor
            if (prev->right == nullptr) {
                prev->right = curr;
                curr = curr->left;
            } 
            else {
              
                // Revert the changes made in 
                // the tree structure
                prev->right = nullptr;
                res.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return res;
}


//Driver Code Starts{

int main() {
  
    // Representation of input binary tree:
    //           1
    //          / \
    //         2   3
    //        / \  
    //       4   5
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> res = inOrder(root);
  
     for (int data : res) {
        cout << data << " ";
    }
    
    return 0;
}

//Driver Code Ends }