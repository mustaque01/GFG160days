// C++ program to find all solution of N queen problem by
// using backtracking and pruning

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Utility function for solving the N-Queens
// problem using backtracking.
void nQueenUtil(int j, int n, vector<int> &board, vector<bool> &rows, 
    vector<bool> &diag1, vector<bool> &diag2, vector<vector<int>> &res) {
    
    if (j > n) {
          // A solution is found
        res.push_back(board);
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (!rows[i] && !diag1[i + j] && !diag2[i - j + n]) {

            // Place queen
            rows[i] = diag1[i + j] = diag2[i - j + n] = true;
            board.push_back(i);

            // Recurse to the next column
            nQueenUtil(j + 1, n, board, rows, diag1, diag2, res);

            // Remove queen (backtrack)
            board.pop_back();
            rows[i] = diag1[i + j] = diag2[i - j + n] = false;
        }
    }
}

// Solves the N-Queens problem and returns
// all valid configurations.
vector<vector<int>> nQueen(int n) {
    vector<vector<int>> res;
    vector<int> board;

    // Rows occupied
    vector<bool> rows(n + 1, false);

    // Major diagonals (row + j) and Minor diagonals (row - col + n)
    vector<bool> diag1(2 * n + 1, false);
    vector<bool> diag2(2 * n + 1, false);

    // Start solving from the first column
    nQueenUtil(1, n, board, rows, diag1, diag2, res);
    return res;
}

int main() {
    int n = 4;
    vector<vector<int>> res = nQueen(n);

    for (int i = 0; i < res.size(); i++) {
        cout << "[";
        for (int j = 0; j < n; ++j) {
            cout << res[i][j];
            if (j != n - 1)
                cout << " ";
        }
        cout << "]\n";
    }
    return 0;
}