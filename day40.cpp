// C++ program to search in the sorted matrix using
// binary search

#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& mat, int x) {
    int n = mat.size(), m = mat[0].size();

    int lo = 0, hi = n * m - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
      
        // Find row and column of element at mid index
        int row = mid / m;
        int col = mid % m;
      
        // If x is found, return true
        if (mat[row][col] == x) 
            return true;
      
        // If x is greater than mat[row][col], search in
        // right half
        if (mat[row][col] < x) 
            lo = mid + 1;
        
        // If x is less than mat[row][col], search in 
        // left half
        else 
            hi = mid - 1;
    }
    return false;
}

int main() {
    vector<vector<int>> mat = {{1, 5, 9}, {14, 20, 21}, {30, 34, 43}};
    int x = 14;

    if (searchMatrix(mat, x))
        cout << "true";
    else
        cout << "false";

    return 0;
}