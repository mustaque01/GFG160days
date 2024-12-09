// C++ Code to Merge Overlapping Intervals in-place

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Merge overlapping intervals in-place. We return
// modified size of the array arr.
int mergeOverlap(vector<vector<int>>& arr) {

    // Sort intervals based on start values
    sort(arr.begin(), arr.end());

    // Index of the last merged 
    int resIdx = 0; 

    for (int i = 1; i < arr.size(); i++) {
      
        // If current interval overlaps with the 
        // last merged interval
        if (arr[resIdx][1] >= arr[i][0])           
            arr[resIdx][1] = max(arr[resIdx][1], arr[i][1]);
      
        // Move to the next interval
        else {            
            resIdx++;
            arr[resIdx] = arr[i];
        }
    }

    // Returns size of the merged intervals
    return (resIdx + 1);
}

int main() {
    vector<vector<int>> arr = {{7, 8}, {1, 5}, {2, 4}, {4, 6}};
    
    // Get the new size of the array after merging
    int newSize = mergeOverlap(arr);

    // Print the merged intervals based on the new size
    for (int i = 0; i < newSize; i++) {
        cout << arr[i][0] << " " << arr[i][1] << "\n";
    }

    return 0;
}