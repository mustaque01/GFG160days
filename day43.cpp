// C++ Program to count pairs with given sum
// using Hash Map

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Returns number of pairs in arr[0...n-1] with sum 
// equal to 'target'
int countPairs(vector<int>& arr, int target) {
    unordered_map<int, int> freq;
    int cnt = 0;

    for (int i = 0; i < arr.size(); i++) {
      
        // Check if the complement (target - arr[i])
        // exists in the map. If yes, increment count
        if (freq.find(target - arr[i]) != freq.end()) {
            cnt += freq[target - arr[i]]; 
        }
      
        // Increment the frequency of arr[i]
        freq[arr[i]]++; 
    }
    return cnt;
}

int main() {
    vector<int> arr = {1, 5, 7, -1, 5}; 
    int target = 6; 
    cout << countPairs(arr, target);    
    return 0;
}