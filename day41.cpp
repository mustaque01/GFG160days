// C++ code to implement Set Matrix Zeroes using
// first row and column

#include <iostream>
#include <vector>
using namespace std;

void setMatrixZeroes(vector<vector<int>> &mat) {
    int n = mat.size(), m = mat[0].size();

    int c0 = 1;

    // Traverse the arr and mark first cell of
    // each row and column
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 0) {

                // mark i-th row
                mat[i][0] = 0;

                // mark j-th column
                if (j == 0)
                    c0 = 0;
                else
                    mat[0][j] = 0;
            }
        }
    }

    // Traverse and mark the matrix from (1, 1)
    // to (n - 1, m - 1)
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {

            // Check for col & row
            if (mat[i][0] == 0 || mat[0][j] == 0) {
                mat[i][j] = 0;
            }
        }
    }

    // Mark the first row
    if (mat[0][0] == 0) {
        for (int j = 0; j < m; j++)
            mat[0][j] = 0;
    }
  
    // Mark the first column
    if (c0 == 0) {
        for (int i = 0; i < n; i++)
            mat[i][0] = 0;
    }
}

int main() {
    vector<vector<int> > mat = { { 0, 1, 2, 0 },
                                 { 3, 4, 0, 2 },
                                 { 1, 3, 1, 5 } };

    setMatrixZeroes(mat);
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[0].size(); j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}