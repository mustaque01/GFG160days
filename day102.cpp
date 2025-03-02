// C++ program to calculate stock span 
// values using a stack
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Function to calculate stock span values
vector<int> calculateSpan(vector<int>& arr) {

    int n = arr.size(); 
    vector<int> span(n);  
    stack<int> stk;  

    // Process each day's price
    for (int i = 0; i < n; i++) {
        
        // Remove elements from the stack while the current
        // price is greater than or equal to stack's top price
        while (!stk.empty() && arr[stk.top()] <= arr[i]) {
            stk.pop();
        }

        // If stack is empty, all elements to the left are smaller
        // Else, top of the stack is the last greater element's index
        if (stk.empty()) {
            span[i] = (i + 1);
        }
        else {
            span[i] = (i - stk.top());
        }

        // Push the current index to the stack
        stk.push(i);
    }

    return span;
}

int main() {
    vector<int> arr = {10, 4, 5, 90, 120, 80};
    vector<int> span = calculateSpan(arr);
     for (int x : span) {
        cout << x << " ";
    }
    return 0;
}