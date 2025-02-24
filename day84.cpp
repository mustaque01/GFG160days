//Driver Code Starts{
// C++ program to convert a left unbalanced BST to
// a balanced BST

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};
//Driver Code Ends }


// Inorder traversal to store elements of the
// tree in sorted order
void storeInorder(Node* root, vector<int>& nodes) {
    if (root == nullptr) 
        return;

    // Traverse the left subtree
    storeInorder(root->left, nodes);

    // Store the node data
    nodes.push_back(root->data);

    // Traverse the right subtree
    storeInorder(root->right, nodes);
}

// Function to build a balanced BST from a sorted array
Node* buildBalancedTree(vector<int>& nodes, int start, int end) {
    
    // Base case
    if (start > end) 
        return nullptr;

    // Get the middle element and make it the root
    int mid = (start + end) / 2;
    Node* root = new Node(nodes[mid]);

    // Recursively build the left and right subtrees
    root->left = buildBalancedTree(nodes, start, mid - 1);
    root->right = buildBalancedTree(nodes, mid + 1, end);

    return root;
}

// Function to balance a BST
Node* balanceBST(Node* root) {
    vector<int> nodes;

    // Store the nodes in sorted order
    storeInorder(root, nodes);

    // Build the balanced tree from the sorted nodes
    return buildBalancedTree(nodes, 0, nodes.size() - 1);
}


//Driver Code Starts{
// Print tree as level order
void printLevelOrder(Node *root) {
    if (root == nullptr) {
        cout << "N ";
        return;
    }

    queue<Node *> qq;
    qq.push(root);
    int nonNull = 1;

    while (!qq.empty() && nonNull > 0) {
        Node *curr = qq.front();
        qq.pop();

        if (curr == nullptr) {
            cout << "N ";
            continue;
        }
        nonNull--;

        cout << (curr->data) << " ";
        qq.push(curr->left);
        qq.push(curr->right);
        if (curr->left)
            nonNull++;
        if (curr->right)
            nonNull++;
    }
}

int main() {
    
    // Constructing an unbalanced BST
    //        4
    //       / \
    //      3   5
    //     /     \
    //    2       6
    //   /           \
    //  1            7

    Node* root = new Node(4);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->left->left = new Node(1);
    root->right = new Node(5);
    root->right->right = new Node(6);
      root->right->right->right = new Node(7);

    Node* balancedRoot = balanceBST(root);
    printLevelOrder(balancedRoot);

    return 0;
}

//Driver Code Ends }