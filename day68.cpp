// C++ program to merge two sorted linked
// lists recursively
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

// Function to merge two sorted linked lists recursively
Node* sortedMerge(Node* head1, Node* head2) {

    // Base cases
    if (head1 == nullptr) 
        return head2;
    if (head2 == nullptr) 
        return head1;

    // Recursive merging based on smaller value
    if (head1->data <= head2->data) {
        head1->next = sortedMerge(head1->next, head2);
        return head1;
    } else {
        head2->next = sortedMerge(head1, head2->next);
        return head2;
    }
}

// Function to print the linked list
void printList(Node* curr) {
    while (curr != nullptr) {
        cout << curr->data;
        if (curr->next != nullptr)
            cout << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
  
    // First linked list: 5 -> 10 -> 15
    Node* head1 = new Node(5);
    head1->next = new Node(10);
    head1->next->next = new Node(15);

    // Second linked list: 2 -> 3 -> 20
    Node* head2 = new Node(2);
    head2->next = new Node(3);
    head2->next->next = new Node(20);

    Node* res = sortedMerge(head1, head2);
    printList(res);

    return 0;
}