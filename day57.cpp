// C++ program to count distinct elements in every window
// of size k by traversing all windows of size k

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> countDistinct(vector<int> &arr, int k) {
    int n = arr.size();  
    vector<int> res;
    unordered_map<int, int> freq;
  
    // Store the frequency of elements of first window
    for(int i = 0; i < k; i++)
        freq[arr[i]] += 1;
  
    // Store the count of distinct element of first window
    res.push_back(freq.size());
  
    for(int i = k; i < n; i++) {
        freq[arr[i]] += 1;
        freq[arr[i - k]] -= 1;
      
        // If the frequency of arr[i - k] becomes 0, remove 
        // it from hash map
        if(freq[arr[i - k]] == 0)
            freq.erase(arr[i - k]);
      
        res.push_back(freq.size());
    }
      
    return res;
}

int main() {
    vector<int> arr = {1, 2, 1, 3, 4, 2, 3};
    int k = 4;

    vector<int> res = countDistinct(arr, k);
    for(int ele: res)
        cout << ele << " ";
    return 0;
}