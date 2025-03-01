//Driver Code Starts{
// C++ program to serialize and 
// deserialize a binary tree.
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node{
public:
    int data;
    Node* left, *right;
    Node (int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
//Driver Code Ends }


// Main function to serialize a tree.
vector<int> serialize(Node *root) {
    vector<int> arr;
    
    queue<Node*> q;
    q.push(root);
    
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        
        // If curr node is null,
        // append -1 to result.
        if (curr == nullptr) {
            arr.push_back(-1);
            continue;
        }
        
        // else push its value into
        // result and push left and right
        // child nodes into queue.
        arr.push_back(curr->data);
        
        q.push(curr->left);
        q.push(curr->right);
    }
    
    return arr;
}


// Main function to deserialize a tree.
Node * deSerialize(vector<int> &arr) {
   
   // base case
   if (arr[0]==-1) return nullptr;
   
   // create root node and push 
   // it into queue
   Node* root = new Node(arr[0]);
   queue<Node*> q;
   q.push(root);
   
   int i = 1;
   while (!q.empty()) {
       Node* curr = q.front();
       q.pop();
       
       // If left node is not null
       if (arr[i]!=-1) {
           Node* left = new Node(arr[i]);
           curr->left = left;
           q.push(left);
       }
       i++;
       
       // If right node is not null
       if (arr[i]!=-1) {
           Node* right = new Node(arr[i]);
           curr->right = right;
           q.push(right);
       }
       i++;
   }
   
   return root;
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

    // Create a hard coded tree
    //       10
    //     /    \
    //    20    30
    //  /   \
    // 40  60
    Node* root = new Node(10);        
    root->left = new Node(20);        
    root->right = new Node(30);       
    root->left->left = new Node(40);
    root->left->right = new Node(60); 
    
    vector<int> arr = serialize(root);
    Node* res = deSerialize(arr);
    
    printLevelOrder(res);
}

//Driver Code Ends }