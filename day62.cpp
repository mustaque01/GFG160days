// C++ program to find longest sub-array having sum k
// using Hash Map and Prefix Sum

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Function to find longest sub-array having sum k
int longestSubarray(vector<int>& arr, int k) {
    unordered_map<int, int> mp;
    int res = 0;
    int prefSum = 0;

    for (int i = 0; i < arr.size(); ++i) {
        prefSum += arr[i];

        // Check if the entire prefix sums to k
        if (prefSum == k) 
            res = i + 1;

        // If prefixSum - k exists in the map then there exist such 
          // subarray from (index of previous prefix + 1) to i.
        else if (mp.find(prefSum - k) != mp.end()) 
            res = max(res, i - mp[prefSum - k]);

        // Store only first occurrence index of prefSum
          if (mp.find(prefSum) == mp.end())
            mp[prefSum] = i;
    }

    return res;
}

int main() {
    vector<int> arr = {10, 5, 2, 7, 1, -10};
    int k = 15;
    cout << longestSubarray(arr, k) << endl;
}