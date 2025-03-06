// C++ program to find the maximum of the minimums 
// for every window size in the array

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> maxOfMins(vector<int>& arr) {
    int n = arr.size();
    vector<int> res(n, 0); 
    stack<int> s;

    // Array to store the length of the window 
    // where each element is the minimum
    vector<int> len(n, 0);

    // Traverse through array to determine 
    // window sizes using a stack
    for (int i = 0; i < n; i++) {
      
        // Process elements to find next smaller 
        // element on the left
        while (!s.empty() && arr[s.top()] >= arr[i]) {
            int top = s.top();
            s.pop();
            int windowSize = s.empty() ? i : i - s.top() - 1;
            len[top] = windowSize;
        }
        s.push(i);
    }

    // Process remaining elements in the stack
    // for right boundaries
    while (!s.empty()) {
        int top = s.top();
        s.pop();
        int windowSize = s.empty() ? n : n - s.top() - 1;
        len[top] = windowSize;
    }

    // Fill res[] based on len[] and arr[]
    for (int i = 0; i < n; i++) {
        int windowSize = len[i] - 1;  // 0-based indexing
        res[windowSize] = max(res[windowSize], arr[i]);
    }

    // Fill remaining entries in res[] to ensure 
    // all are max of min
    for (int i = n - 2; i >= 0; i--)
        res[i] = max(res[i], res[i + 1]);

    return res;
}

int main() {
    vector<int> arr = { 10, 20, 30, 50, 10, 70, 30 };
    vector<int> res = maxOfMins(arr);
    for (int x : res)
        cout << x << " ";
    return 0;
}