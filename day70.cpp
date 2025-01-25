// C++ code to Clone a linked list with next and random
// pointer by Inserting Nodes In-place

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next, *random;
    Node(int x) {
        data = x;
        next = random = NULL;
    }
};

Node* cloneLinkedList(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    
    // Create new nodes and insert them next to 
      // the original nodes
    Node* curr = head;
    while (curr != NULL) {
        Node* newNode = new Node(curr->data);
        newNode->next = curr->next;
        curr->next = newNode;
        curr = newNode->next;
    }
    
    // Set the random pointers of the new nodes
    curr = head;
    while (curr != NULL) {
        if (curr->random != NULL)
            curr->next->random = curr->random->next;
        curr = curr->next->next;
    }
    
    // Separate the new nodes from the original nodes
    curr = head;
    Node* clonedHead = head->next;
    Node* clone = clonedHead;
    while (clone->next != NULL) {
          
          // Update the next nodes of original node 
          // and cloned node
        curr->next = curr->next->next;
        clone->next = clone->next->next;
          
          // Move pointers of original as well as  
          // cloned linked list to their next nodes
        curr = curr->next;
        clone = clone->next;
    }
    curr->next = NULL;
    clone->next = NULL;
    
    return clonedHead;
}


// Function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << "(";
          if(head->random)
              cout << head->random->data << ")";
          else 
              cout << "null" << ")";
        
          if(head->next != NULL)
              cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
  
    // Creating a linked list with random pointer
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head->next;
  
    // Print the original list
    cout << "Original linked list:\n";
    printList(head);
  
    // Function call
    Node* clonedList = cloneLinkedList(head);
  
    cout << "Cloned linked list:\n";
    printList(clonedList);
  
    return 0;
}