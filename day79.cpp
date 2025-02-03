// C++ program to check if the word exists in the grid or not

#include <iostream>
#include <vector>
using namespace std;

// Function to check if a word exists in a grid
// starting from the first match in the grid
// wIdx: index till which pattern is matched
// x, y: current position in 2D array
bool findMatch(vector<vector<char>> &mat, string word, int x, int y, int wIdx) {
    int wLen = word.length();
    int n = mat.size();
      int m = mat[0].size();
  
    // Pattern matched
    if (wIdx == wLen)
        return true;

    // Out of Boundary
    if (x < 0 || y < 0 || x >= n || y >= m)
        return false;

    // If grid matches with a letter while
    // recursion
    if (mat[x][y] == word[wIdx]) {

        // Marking this cell as visited
        char temp = mat[x][y];
        mat[x][y] = '#';

        // finding subpattern in 4 directions
        bool res = findMatch(mat, word, x - 1, y, wIdx + 1) ||
                   findMatch(mat, word, x + 1, y, wIdx + 1) ||
                   findMatch(mat, word, x, y - 1, wIdx + 1) ||
                   findMatch(mat, word, x, y + 1, wIdx + 1);

        // marking this cell as unvisited again
        mat[x][y] = temp;
        return res;
    }
      
      // Not matching then return false
    return false;
}

// Function to check if the word exists in the matrix or not
bool isWordExist(vector<vector<char>> &mat, string word) {
    int wLen = word.length();
    int n = mat.size();
      int m = mat[0].size();
  
    // if total characters in matrix is
    // less than word length
    if (wLen > n * m)
        return false;

    // Traverse in the grid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            // If first letter matches, then recur and check
            if (mat[i][j] == word[0]){
                if (findMatch(mat, word, i, j, 0))
                    return true;
            }
        }
    }
    return false;
}

int main() {
    vector<vector<char>> mat = { {'a', 'x', 'm', 'y'}, 
                                  {'b', 'g', 'd', 'f'}, 
                                  {'x', 'e', 'e', 't'}, 
                                  {'r', 'a', 'k', 's'} };
      string word = "geeks";    
    cout << (isWordExist(mat, word) ? "true" : "false");

    return 0;
}