// C++ program to find the longest subarray where the
// absolute difference between any two elements is not
// greater than X
#include <bits/stdc++.h>
using namespace std;

// Function that prints the longest sub-array
// where the absolute difference between any
// two element is not greater than X
vector<int> longestSubarray(vector<int>& arr, int x) {
    
    // Monotonic Queue to store maximum and minimum elements
    deque<int> minQueue, maxQueue;
    
    // Pointers to mark the range of current subarray
    int n = arr.size(), start = 0, end = 0;
    
    // Pointers to mark the range of maximum subarray
    int resStart = 0, resEnd = 0;
    while (end < n) {
        
        // Pop the elements greater than current element
        // from min Queue
        while (!minQueue.empty()
               && arr[minQueue.back()] > arr[end])
            minQueue.pop_back();
            
        // Pop the elements smaller than current element
        // from max Queue
        while (!maxQueue.empty()
               && arr[maxQueue.back()] < arr[end])
            maxQueue.pop_back();
            
        // Push the current index to both the queues
        minQueue.push_back(end);
        maxQueue.push_back(end);
        
        // Check if the subarray has maximum difference less
        // than X
        while (arr[maxQueue.front()] - arr[minQueue.front()]
               > x) {
                   
            // Reduce the length of sliding window by moving
            // the start pointer
            if (start == minQueue.front())
                minQueue.pop_front();
            if (start == maxQueue.front())
                maxQueue.pop_front();
            start += 1;
        }
        
        // Maximize the subarray length
        if (end - start > resEnd - resStart) {
            resStart = start;
            resEnd = end;
        }
        end += 1;
    }

    // Return the longest sub-array
    vector<int> res;
    for (int i = resStart; i <= resEnd; i++)
        res.push_back(arr[i]);
        
    return res;
}

int main() {
    vector<int> arr = { 8, 4, 2, 6, 7 };
  	int x = 4;

    vector<int> res = longestSubarray(arr, x);
    
    for (auto val: res) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}