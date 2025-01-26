// C++ program to return first node of loop.
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

// Function to detect a loop in the linked list and 
// return the node where the cycle starts using
// Floyd’s Cycle-Finding Algorithm
Node* findFirstNode(Node* head) {
  
    // Initialize two pointers, slow and fast
    Node* slow = head;
    Node* fast = head;
    
    // Traverse the list
    while (fast != nullptr && fast->next != nullptr) {
      
          // Move slow pointer by one step
        slow = slow->next;          
      
          // Move fast pointer by two steps
        fast = fast->next->next;    

        // Detect loop
        if (slow == fast) {
          
            // Move slow to head, keep fast at meeting point
            slow = head;
            
            // Move both one step at a time until they meet
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            
            // Return the meeting node, which
              // is the start of the loop
            return slow;
        }
    }
    
    // No loop found
    return nullptr;
}

int main() {
  
    // Create a linked list: 10 -> 15 -> 4 -> 20
    Node* head = new Node(10);
    head->next = new Node(15);
    head->next->next = new Node(4);
    head->next->next->next = new Node(20);

    head->next->next->next->next = head;

    Node* loopNode = findFirstNode(head);

    if (loopNode)
        cout << loopNode->data;
    else
        cout << -1;

    return 0;
}