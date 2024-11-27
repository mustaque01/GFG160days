// C++ program to find maximum Subarray Sum in Circular
// array using prefix and suffix

#include <iostream>
#include <vector>
using namespace std;

int circularSubarraySum(vector<int> &arr) {
    int n = arr.size();
    int suffixSum = arr[n - 1];
    
    // maxSuffix array to store the value of 
    // maximum suffix occured so far.
    vector<int> maxSuffix(n + 1, 0);
    maxSuffix[n - 1] = arr[n - 1];
    
    for(int i = n - 2; i >= 0; i--) {
        suffixSum = suffixSum + arr[i];
        maxSuffix[i] = max(maxSuffix[i + 1], suffixSum);
    }
    
    // circularSum is Maximum sum of circular subarray
    int circularSum = arr[0];
    
    // normalSum is Maxium sum subarray considering 
    // the array is non-circular
    int normalSum = arr[0];
    
    int currSum = 0;
    int prefix = 0;
    
    for(int i = 0; i < n; i++) {
        
        // Kadane's algorithm
        currSum = max(currSum + arr[i], arr[i]);
        normalSum = max(normalSum, currSum);
      
        // Calculating maximum Circular Sum
        prefix = prefix + arr[i];
        circularSum = max(circularSum, prefix + maxSuffix[i+1]);
    }
    
    return max(circularSum, normalSum);
}

int main() {
    vector<int> arr = {8, -8, 9, -9, 10, -11, 12};
    cout << circularSubarraySum(arr);
}