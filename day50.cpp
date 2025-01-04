// C++ Program to count all subarrays having
// XOR of elements as given value K using Hash Map
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to find the count of subarrays of arr 
// with XOR value equals to k
int subarrayXor(vector<int>& arr, int k) {
    int res = 0; 

    // Create hash map that stores number of prefix arrays
    // corresponding to a XOR value
    unordered_map<int, int> mp;
  
      int prefXOR = 0;
  
    for (int val : arr) {
      
        // Find XOR of current prefix
        prefXOR ^= val;

        // If prefXOR ^ k exist in mp then there is a subarray 
          // ending at i with XOR equal to k
        res = res + mp[prefXOR ^ k];

        // If this prefix subarray has XOR equal to k
        if (prefXOR == k)
            res++;

        // Add the XOR of this subarray to the map
        mp[prefXOR]++;
    }

    // Return total count of subarrays having XOR of
    // elements as given value k
    return res;
}

int main() {
    vector<int> arr = { 4, 2, 2, 6, 4 };
    int k = 6;

    cout << subarrayXor(arr, k);
    return 0;
}