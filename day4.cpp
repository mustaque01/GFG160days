// C++ Program to left rotate the array by d positions
// by rotating one element at a time

#include <bits/stdc++.h>
using namespace std;

// Function to left rotate array by d positions
void rotateArr(vector<int>& arr, int d) {
    int n = arr.size();
  
    // Repeat the rotation d times
    for (int i = 0; i < d; i++) {
      
        // Left rotate the array by one position
        int first = arr[0];
        for (int j = 0; j < n - 1; j++) {
            arr[j] = arr[j + 1];
        }
        arr[n - 1] = first;
    }
}

int main() {
    vector<int> arr = { 1, 2, 3, 4, 5, 6 };
    int d = 2;

    rotateArr(arr, d);

    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";

    return 0;
}