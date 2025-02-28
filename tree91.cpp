//Driver Code Starts{
// C++ code to find a pair with given sum in a Balanced BST
// Using Inorder Traversal
#include <iostream>
#include <vector>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};
//Driver Code Ends }


// Function to perform Inorder traversal and store the 
// elements in a vector
void inorderTraversal(Node* root, vector<int>& inorder) {
    if (root == nullptr)
        return;

    inorderTraversal(root->left, inorder);

    // Store the current node's value
    inorder.push_back(root->data);

    inorderTraversal(root->right, inorder);
}

// Function to find if there exists a pair with a 
// given sum in the BST
bool findTarget(Node* root, int target) {
    
    // Create an auxiliary array and store Inorder traversal
    vector<int> inorder;
    inorderTraversal(root, inorder); 

    // Use two-pointer technique to find the pair with given sum
    int left = 0, right = inorder.size() - 1;

    while (left < right) {
        int currentSum = inorder[left] + inorder[right];

        // If the pair is found, return true
        if (currentSum == target) 
            return true;

        // If the current sum is less than the target, 
        // move the left pointer
        if (currentSum < target)
            left++;
      
          // If the current sum is greater than 
        // the target, move the right pointer
        else
            right--;
    }

    return false;
}


//Driver Code Starts{
int main(){
    // Constructing the following BST:
    //         7
    //        / \
    //       3   8
    //      / \   \
    //     2   4   9

    Node *root = new Node(7);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->right = new Node(9);

    int target = 12;

    // Check if there are two elements in the BST
    // that added to "target"
    if (findTarget(root, target))
        cout << "True";
    else
        cout << "False";

    return 0;
}
//Driver Code Ends }