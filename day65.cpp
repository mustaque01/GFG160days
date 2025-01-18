// C++ program to reverse linked list using Stack

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

// Function to reverse the linked list
Node* reverseList(Node* head) {
      
    // Create a stack to store the nodes
    stack<Node*> s;
  
    Node* temp = head;
  
      // Push all nodes except the last node into stack
    while (temp->next != NULL) {
        s.push(temp);
        temp = temp->next;
    }
      
      // Make the last node as new head of the linked list
    head = temp;
  
      // Pop all the nodes and append to the linked list
    while (!s.empty()) {
          
        // append the top value of stack in list
        temp->next = s.top();
        
          // Pop the value from stack
        s.pop();
        
          // move to the next node in the list
        temp = temp->next;
    }
      
      // Update the next pointer of last node of stack to NULL
    temp->next = NULL;
  
      return head;
}

void printList(Node* node) {
    while (node != nullptr) {
        cout << " " << node->data;
        node = node->next;
    }
}

int main() {
      
    // Create a hard-coded linked list:
    // 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Given Linked List:";
    printList(head);

    head = reverseList(head);

    cout << "\nReversed Linked List:";
    printList(head);
  
      return 0;
}