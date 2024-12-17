// C++ program to find maximum possible minimum distance
// between any two cows using binary search

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// function to check if we can place k cows
// with at least dist distance apart
bool check(vector<int> &stalls, int k, int dist) {
    
    // Place first cow at 0th index
    int cnt = 1;  
    int prev = stalls[0]; 
    for (int i = 1; i < stalls.size(); i++) {
        
        // If the current stall is at least dist away
        // from the previous one place the cow here
        if (stalls[i] - prev >= dist) {
            prev = stalls[i]; 
            cnt++;
        }
    }

    // Return true if we are able to place all 'k' cows
    return (cnt >= k);
}

int aggressiveCows(vector<int> &stalls, int k) {
  
      // sorting the array to ensure stalls in sequence
      sort(stalls.begin(), stalls.end());
    int res = 0; 
  
    // Search Space for Binary Search
      int lo = 1;
      int hi = stalls.back() - stalls[0];
    while(lo <= hi) {
        int mid = lo + (hi - lo)/2;
        
        // If the mid ditance is possible, update
        // the result and search for larger ditance
        if(check(stalls, k, mid)) {
            res = mid;
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }
    
    return res;
}

int main() {
    vector<int> stalls = {1, 2, 4, 8, 9}; 
    int k = 3;
    int ans = aggressiveCows(stalls, k);
    cout << ans;
    return 0;
}