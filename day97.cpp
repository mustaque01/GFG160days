// C++ program to merge K sorted linked lists
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

// Function to merge two sorted lists.
Node* mergeTwo(Node* head1, Node* head2) {
  
    // Create a dummy node to simplify 
    // the merging process
    Node* dummy = new Node(-1);
    Node* curr = dummy;

    // Iterate through both linked lists
    while (head1 != nullptr && head2 != nullptr) {
      
        // Add the smaller node to the merged list
        if (head1->data <= head2->data) {
            curr->next = head1;
            head1 = head1->next;
        } else {
            curr->next = head2;
            head2 = head2->next;
        }
        curr = curr->next;
    }

    // If any list is left, append it to
    // the merged list
    if (head1 != nullptr) {
        curr->next = head1;
    } else {
        curr->next = head2;
    }

    // Return the merged list starting
    // from the next of dummy node
    return dummy->next;
}

Node* mergeListsRecur(int i, int j, vector<Node*> &arr) {
    
    // If single list is left
    if (i == j) return arr[i];
    
    // Find the middle of lists
    int mid = i + (j-i)/2;
    
    // Merge lists from i to mid 
    Node* head1 = mergeListsRecur(i, mid, arr);
    
    // Merge lists from mid+1 to j 
    Node* head2 = mergeListsRecur(mid+1, j, arr);
    
    // Merge the above 2 lists 
    Node* head = mergeTwo(head1, head2);
    
    return head;
}

// Function to merge K sorted linked lists
Node* mergeKLists(vector<Node*>& arr) {
    
    // Base case for 0 lists 
    if (arr.size()==0) return nullptr;
  
    return mergeListsRecur(0, arr.size()-1, arr);
}

void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
}

int main() {
    int k = 3; 
  
    vector<Node*> arr(k);

    arr[0] = new Node(1);
    arr[0]->next = new Node(3);
    arr[0]->next->next = new Node(5);
    arr[0]->next->next->next = new Node(7);

    arr[1] = new Node(2);
    arr[1]->next = new Node(4);
    arr[1]->next->next = new Node(6);
    arr[1]->next->next->next = new Node(8);

    arr[2] = new Node(0);
    arr[2]->next = new Node(9);
    arr[2]->next->next = new Node(10);
    arr[2]->next->next->next = new Node(11);
    
    Node* head = mergeKLists(arr);

    printList(head);

    return 0;
}