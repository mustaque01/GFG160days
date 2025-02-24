//Driver Code Starts{
// C++ Program Invert a Binary Tree using Iterative Level Order

#include <iostream>
#include <queue> 
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
//Driver Code Ends }


// function to return the root of inverted tree
void mirror(Node* root) {
    if (root == nullptr)
        return ;
    
    queue<Node*> q;
    q.push(root);
    
    // Traverse the tree, level by level
    while(!q.empty()) {
        Node* curr = q.front();
        q.pop();
      
        // Swap the left and right subtree
        swap(curr->left, curr->right);
      
        // Push the left and right node to the queue
        if(curr->left != nullptr)
          q.push(curr->left);
        if(curr->right != nullptr)
          q.push(curr->right);
    }
}

// Print tree as level order
void levelOrder(Node *root) {
    if (root == nullptr) {
          cout << "N ";
          return ;
    }

    queue<Node*> qq;
    qq.push(root);

    while (!qq.empty()) {
        Node *curr = qq.front();
        qq.pop();

        if (curr == nullptr) {
            cout << "N ";
            continue;
        }
        cout << (curr->data) <<  " ";
        qq.push(curr->left);
        qq.push(curr->right);
    }
}


//Driver Code Starts{
int main() {

    // Input Tree:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    mirror(root);
  
    // Mirror Tree:
    //       1
    //      / \
    //     3   2
    //        / \
    //       5   4
    levelOrder(root);

    return 0;
}

//Driver Code Ends }