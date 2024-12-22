// C++ program to rotate a matrix by 90 degrees anti-
// clockwise by reversing Rows and then Transposing

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void rotateMatrix(vector<vector<int>> &mat){ 
      int n = mat.size();
      
      // Reverse each row
    for (int i = 0; i < n; i++)
        reverse(mat[i].begin(), mat[i].end());

    // Performing Transpose
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++)
            swap(mat[i][j], mat[j][i]);
    }
}

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    rotateMatrix(mat);
    for (auto& row : mat) {
        for (int x : row) {
            cout << x << ' ';
        }
        cout << endl;
    }

    return 0;
}