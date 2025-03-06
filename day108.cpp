#include <bits/stdc++.h>
using namespace std;

// Method to find the maximum for each
// and every contiguous subarray of size k.
vector<int> maxOfSubarrays(vector<int>& arr, int k) {

    // to store the results
    vector<int> res;
  
    // create deque to store max values
    deque<int> dq(k);

    // Process first k (or first window) elements of array
    for (int i = 0; i < k; ++i) {
      
        // For every element, the previous smaller elements 
        // are useless so remove them from dq
        while (!dq.empty() && arr[i] >= arr[dq.back()]) {
          
            // Remove from rear
            dq.pop_back();
        }

        // Add new element at rear of queue
        dq.push_back(i);
    }

    // Process rest of the elements, i.e., from arr[k] to arr[n-1]
    for (int i = k; i < arr.size(); ++i) {
      
        // The element at the front of the queue is the largest 
        // element of previous window, so store it
        res.push_back(arr[dq.front()]);

        // Remove the elements which are out of this window
        while (!dq.empty() && dq.front() <= i - k) {
          
            // Remove from front of queue
            dq.pop_front();
        }

        // Remove all elements smaller than the currently being 
        // added element (remove useless elements)
        while (!dq.empty() && arr[i] >= arr[dq.back()]) {
            dq.pop_back();
        }

        // Add current element at the rear of dq
        dq.push_back(i);
    }

    // store the maximum element of last window
    res.push_back(arr[dq.front()]);

    return res;
}

int main() {
    vector<int> arr = {1, 3, 2, 1, 7, 3};
    int k = 3;
    vector<int> res = maxOfSubarrays(arr, k);
    for (int maxVal : res) {
        cout << maxVal << " ";
    }
    return 0;
}