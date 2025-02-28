//Driver Code Starts{
// C++ Program to Count all K Sum Paths in Binary Tree
// Using Prefix sum Technique

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Node {
  public :
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
//Driver Code Ends }


// Function to find paths in the tree which have
// their sum equal to K
int countPathsUtil(Node* node, int k, int currSum, 
                           unordered_map<int, int>& prefSums) {
  
    if (node == nullptr)
        return 0;
  
      int pathCount = 0;
    currSum += node->data;
       
      // Pathsum from root to current node is equal to k
    if (currSum == k)
        pathCount++;
      
    // The count of curr_sum − k gives the number of paths 
      // with sum k up to the current node
    pathCount += prefSums[currSum - k];
  
      // Add the current sum into the hashmap
    prefSums[currSum]++;

    pathCount += countPathsUtil(node->left, k, currSum, prefSums);
    pathCount += countPathsUtil(node->right, k, currSum, prefSums);

    // Remove the current sum from the hashmap
    prefSums[currSum]--;
  
      return pathCount;
}

// Function to find the paths in the tree which have their
// sum equal to K
int countAllPaths(Node* root, int k) {
    unordered_map<int, int> prefSums;

    return countPathsUtil(root, k, 0, prefSums);
}


//Driver Code Starts{
int main() {
  
    // Create a sample tree:
    //        8
    //      /  \
    //     4    5
    //    / \    \
    //   3   2    2
    //  / \   \
    // 3  -2   1

    Node* root = new Node(8);
    root->left = new Node(4);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(2);
    root->right->right = new Node(2);
      root->left->left->left = new Node(3);
      root->left->left->right = new Node(-2);
    root->left->right->right = new Node(1);

    int k = 7; 

    cout << countAllPaths(root, k) << endl;
    return 0;
}
//Driver Code Ends }