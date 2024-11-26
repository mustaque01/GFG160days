// C++ program to find Maximum Product Subarray using Minimum
// and Maximum Product ending at every index

#include <bits/stdc++.h>
using namespace std;

// function to find the product of max product subarray
int maxProduct(vector<int> &arr) {
      int n = arr.size();
  
    // max product ending at the current index
    int currMax = arr[0];

    // min product ending at the current index
    int currMin = arr[0];

    // Initialize overall max product
    int maxProd = arr[0];
  
    // Iterate through the array 
    for (int i = 1; i < n; i++) {
          
          // Temporary variable to store the maximum product ending 
          // at the current index
        int temp = max({ arr[i], arr[i] * currMax,
                                            arr[i] * currMin });
        
          // Update the minimum product ending at the current index
          currMin = min({ arr[i], arr[i] * currMax,
                                            arr[i] * currMin });
      
          // Update the maximum product ending at the current index
        currMax = temp;
      
          // Update the overall maximum product
        maxProd = max(maxProd, currMax);
    }
    return maxProd;
}

int main() {
    vector<int> arr = { -2, 6, -3, -10, 0, 2 };
    cout << maxProduct(arr);
    return 0;
}