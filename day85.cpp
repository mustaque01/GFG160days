// C++ program to count BST nodes within a
// given range
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left, *right;
    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

// Returns count of nodes in BST in range [l, h]
int getCount(Node *root, int l, int h) {
    
    // Base case
    if (root == nullptr) return 0;
    
    queue<Node*> q;
    q.push(root);
    int ans = 0;
    
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        
        // If current node is in range, then 
        // increment the count and push the 
        // left and right children into queue.
        if (curr->data <= h && curr->data >= l) {
            ans++;
            if (curr->left != nullptr)
                q.push(curr->left);
            if (curr->right != nullptr)
                q.push(curr->right);
        }
        
        // If current node is smaller than low, 
        // then push right child into queue.
        else if (curr->data < l) {
            if (curr->right != nullptr)
                q.push(curr->right);
        }
        
        // Else push left child
        else {
            if (curr->left != nullptr)
                q.push(curr->left);
        }
    }

    return ans;
}

int main() {
    
    // Create a hard coded bst.
    //        10
    //       /  \
    //      5   50 
    //     /   /  \    
    //    1   40  100
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(50);
    root->left->left = new Node(1);
    root->right->left = new Node(40);
    root->right->right = new Node(100);

    int l = 5;
    int h = 45;
    
    cout << getCount(root, l, h) << endl;
    
    return 0;
}