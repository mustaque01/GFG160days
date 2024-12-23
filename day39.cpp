// C++ program to search an element in row-wise
// sorted matrix 

#include <iostream>
#include <vector>

using namespace std;

bool search(vector<int> &arr, int x) {
    int lo = 0, hi = arr.size();
    while(lo <= hi) {
        int mid = (lo + hi) / 2;
      
        // If x = mid, return true
        if(x == arr[mid]) 
            return true;
      
        // If x < arr[mid], search in left half
        if(x < arr[mid])
            hi = mid - 1;
       
        // If x > arr[mid], search in right half
        else
            lo = mid + 1;
    }
    return false;
}

bool searchRowMatrix(vector<vector<int>> &mat, int x) {
    int n = mat.size(), m = mat[0].size();
  
    // Iterate over all the rows to find x
    for(int i = 0; i < n; i++) {
      
        // binary search on ith row
        if(search(mat[i], x))
            return true;
    }
  
    // If x was not found, return false
    return false;
}

int main() {
    vector<vector<int>> mat = {{3, 4, 9},
                               {2, 5, 6},
                               {9, 25, 27}};
    int x = 9;
    if(searchRowMatrix(mat, x)) 
        cout << "true";
    else 
        cout << "false";
    return 0;
}