// C++ program to search an element in row-wise
// and column-wise sorted matrix 

#include <iostream>
#include <vector>

using namespace std;

bool matSearch(vector<vector<int>> &mat, int x) {
    int n = mat.size(), m = mat[0].size();
    int i = 0, j = m - 1;
  
    while(i < n && j >= 0) {
      
        // If x > mat[i][j], then x will be greater
        // than all elements to the left of 
        // mat[i][j] in row i, so increment i
        if(x > mat[i][j]) {
            i++;
        }
      
        // If x < mat[i][j], then x will be smaller
        // than all elements to the bottom of
        // mat[i][j] in column j, so decrement j
        else if(x < mat[i][j]) {
            j--;
        }
      
        // If x = mat[i][j], return true
        else {
            return true;
        }
    }
  
    // If x was not found, return false
    return false;
}

int main() {
    vector<vector<int>> mat = {{3, 30, 38},
                               {20, 52, 54},
                               {35, 60, 69}};
    int x = 35;
    if(matSearch(mat, x)) 
        cout << "true";
    else 
        cout << "false";
    return 0;
}