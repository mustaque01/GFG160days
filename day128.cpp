// C++ Program to solve House Robber Problem 2
#include <iostream>
#include <vector>
using namespace std;

// Tabulation approach to find the maximum 
// value. Here x and y are the starting and 
// ending indices of the subarray.
int maxValTab(int x, int y, vector<int> &arr) {
    int n = arr.size();
    
    // For first house, taking is only option
    int prev2 = arr[x];
    
    // For second house, we can either take
    // from 1st or 2nd.
    int prev1 = max(arr[x], arr[x+1]);
    
    for (int j=x+2; j<=y; j++) {
        int take = arr[j] + prev2;
        int noTake = prev1;
        
        int curr = max(take, noTake);
        
        // update states
        prev2 = prev1;
        prev1 = curr;
    }
    
    return prev1;
}

// Function to calculate the maximum stolen value
int maxValue(vector<int>& arr) {
    int n = arr.size();
    
    // Base cases
    if (n == 0) return 0;
    if (n == 1) return arr[0];
  
    int ans = 0;
    
    // Skipping last house 
    ans = max(ans, maxValTab(0, n-2, arr));
    
    // Skipping first house 
    ans = max(ans, maxValTab(1, n-1, arr));
    
    return ans;
}

int main() {
    vector<int> arr = {2, 2, 3, 1, 2};
    cout << maxValue(arr);
    return 0;
}