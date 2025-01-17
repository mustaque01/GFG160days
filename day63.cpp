// C++ program to find longest subarray with equal 
// number of 0's and 1's Using Hashmap and Prefix Sum

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int maxLen(vector<int> &arr) {
    unordered_map<int, int> mp;

    int preSum = 0; 
    int res = 0; 
  
    // Traverse through the given array
    for (int i = 0; i < arr.size(); i++) {
      
        // Add current element to sum
          // if current element is zero, add -1
        preSum += (arr[i] == 0) ? -1 : 1;

        // To handle sum = 0 at last index
        if (preSum == 0) 
            res = i + 1;

        // If this sum is seen before, then update 
          // result with maximum
        if (mp.find(preSum) != mp.end())
            res = max(res, i - mp[preSum]);
        
        // Else put this sum in hash table
        else 
            mp[preSum] = i;
    }

    return res;
}

int main() {
    vector<int> arr = {1, 0, 0, 1, 0, 1, 1};
  
    cout << maxLen(arr) << endl;
    return 0;
}