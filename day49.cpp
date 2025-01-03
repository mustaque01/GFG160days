// C++ program to count subarrays having sum K
// using Hash Map

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to find number of subarrays with
// sum as k
int countSubarrays(vector<int> &arr, int k) {
  
    // unordered_map to store prefix sums frequencies
    unordered_map<int, int> prefixSums;
  
    int res = 0;
    int currSum = 0;

    for (int i = 0; i < arr.size(); i++) {
        
        // Add current element to sum so far.
        currSum += arr[i];

        // If currSum is equal to desired sum, then a new
        // subarray is found. So increase count of subarrays.
        if (currSum == k)
            res++;

        // Check if the difference exists in the prefixSums map.
        if (prefixSums.find(currSum - k) != prefixSums.end())
            res += prefixSums[currSum - k];

        // Add currSum to the set of prefix sums.
        prefixSums[currSum]++;
    }

    return res;
}

int main() {
    vector<int> arr = {10, 2, -2, -20, 10};
    int k = -10;
    cout << countSubarrays(arr, k);
    return 0;
}