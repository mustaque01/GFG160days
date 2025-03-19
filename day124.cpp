// C++ program to partition a Set 
// into Two Subsets of Equal Sum
// using space optimised
#include <bits/stdc++.h>
using namespace std;

// Returns true if arr[] can be partitioned in two
// subsets of equal sum, otherwise false
bool equalPartition(vector<int>& arr) {
  
    // Calculate sum of the elements in array
    int sum = accumulate(arr.begin(), arr.end(), 0);
    
    // If sum is odd, there cannot be two 
    // subsets with equal sum
    if (sum % 2 != 0) 
        return false;

    sum = sum / 2;
    
    int n = arr.size();
    vector<bool> prev(sum + 1, false), curr(sum + 1);

    // Mark prev[0] = true as it is true
    // to make sum = 0 using 0 elements
    prev[0] = true;

    // Fill the subset table in
    // bottom up manner
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            if (j < arr[i - 1])
                curr[j] = prev[j];
            else
                curr[j] = (prev[j] || prev[j - arr[i - 1]]);
        }
        prev = curr;
    }
    return prev[sum];
}

int main() {
    vector<int> arr = { 1, 5, 11, 5};
    if (equalPartition(arr)) {
        cout << "True" << endl;
    }else{
        cout << "False" << endl;
    }
    return 0;
}