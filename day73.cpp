//Driver Code Starts{
// C++ program Using Floyd's Cycle Detection Algorithm

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printList(Node *curr) {
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}
//Driver Code Ends }


// Function to detect and remove loop in a linked list that
// may contain loop
void removeLoop(Node *head) {
  
    // If list is empty or has only one node without loop
    if (head == nullptr || head->next ==nullptr)
        return;

    Node *slow = head, *fast = head;

    // Move slow and fast 1 and 2 steps ahead respectively.
    slow = slow->next;
    fast = fast->next->next;

    // Search for loop using slow and fast pointers
    while (fast && fast->next) {
        if (slow == fast)
            break;
        slow = slow->next;
        fast = fast->next->next;
    }

    // If loop exists
    if (slow == fast) {
        slow = head;

        // this check is needed when slow and fast both meet
        // at the head of the LL
        if (slow == fast)
            while (fast->next != slow)
                fast = fast->next;
        else {
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        // since fast->next is the looping point 
        fast->next = nullptr;
    }
}


//Driver Code Starts{
int main() {
  
    // Create a hard-coded linked list:
    // 1 -> 3 -> 4
    Node *head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(4);
  
    // Create a loop
    head->next->next->next = head->next;

    removeLoop(head);
    printList(head);

    return 0;
}
//Driver Code Ends }
