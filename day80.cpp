// C++ program to check if a given Binary
// Tree is symmetric

#include <iostream>
#include <stack>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to check if the binary tree is symmetric
bool isSymmetric(Node* root) {
    if (root == nullptr) 
        return true;

    // Two stacks to store nodes for comparison
    stack<Node*> s1, s2;

    // Initialize the stacks with the left 
      // and right subtrees
    s1.push(root->left);
    s2.push(root->right);

    while (!s1.empty() && !s2.empty()) {
        
        // Get the current pair of nodes
        Node* node1 = s1.top();
        Node* node2 = s2.top();
        s1.pop();
        s2.pop();

        // If both nodes are null, continue to the next pair
        if (node1 == nullptr && node2 == nullptr) {
            continue;
        }

        // If one node is null and the other is not, 
          // or the nodes' data do not match
        // then the tree is not symmetric
        if (node1 == nullptr || node2 == nullptr 
            || node1->data != node2->data) {
            return false;
        }

        // Push children of node1 and node2 in opposite order
        // Push left child of node1 and right child of node2
        s1.push(node1->left);
        s2.push(node2->right);

        // Push right child of node1 and left child of node2
        s1.push(node1->right);
        s2.push(node2->left);
    }

    // If both stacks are empty, the tree is symmetric
    return s1.empty() && s2.empty();
}

int main() {
    
    // Creating a sample symmetric binary tree
    //        1
    //       / \
    //      2   2
    //     / \ / \
    //    3  4 4  3
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);

    if(isSymmetric(root)) 
          cout << "true";
      else 
          cout << "false";

    return 0;
}