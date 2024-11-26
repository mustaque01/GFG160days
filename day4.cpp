// C++ Code to left rotate an array using Reversal Algorithm

#include <bits/stdc++.h>

using namespace std;

// Function to rotate an array by d elements to the left
void rotateArr(vector<int>& arr, int d) {
    int n = arr.size();
  
    // Handle the case where d > size of array
    d %= n;
  
    // Reverse the first d elements
    reverse(arr.begin(), arr.begin() + d);

    // Reverse the remaining n-d elements
    reverse(arr.begin() + d, arr.end());
  
    // Reverse the entire array
    reverse(arr.begin(), arr.end());
}

int main() {
    vector<int> arr = { 1, 2, 3, 4, 5, 6 };
    int d = 2;
    
      rotateArr(arr, d);
  
    for (int i = 0; i < arr.size(); i++) 
        cout << arr[i] << " ";
    return 0;
}