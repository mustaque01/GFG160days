// C++ program to find the first missing positive number 
// using cycle sort

#include <iostream>
#include <vector>
using namespace std;

// Function for finding the first missing positive number
int missingNumber(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {

        // if arr[i] is within range [1, n] and arr[i] is
        // not placed at (arr[i]-1)th index in arr
        while (arr[i] >= 1 && arr[i] <= n
               && arr[i] != arr[arr[i] - 1]) {
                   
            // then swap arr[i] and arr[arr[i]-1]
            // to place arr[i] to its corresponding index
            swap(arr[i], arr[arr[i] - 1]);
        }
    }

    // If any number is not at its corresponding index 
    // then it is the missing number
    for (int i = 1; i <= n; i++) {
        if (i != arr[i-1]) {
            return i;
        }
    }

    // If all number from 1 to n are present 
    // then n + 1 is smallest missing number
    return n + 1;
}

int main() {
    
    vector<int> arr = {2, -3, 4, 1, 1, 7};
    cout << missingNumber(arr);
    return 0;
}