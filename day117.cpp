// C++ Program to count no. of ways to reach
// nth stairs using matrix Exponentiation

#include <iostream>
#include <vector>
using namespace std;

// function to multiply two 2x2 Matrices
void multiply(vector<vector<int>>& a, vector<vector<int>>& b) {
  
    // Matrix to store the result
    vector<vector<int>> res(2, vector<int>(2));

    // Matrix Multiplication
    res[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0];
    res[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1];
    res[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0];
    res[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1];

    // Copy the result back to the first matrix
    a[0][0] = res[0][0];
    a[0][1] = res[0][1];
    a[1][0] = res[1][0];
    a[1][1] = res[1][1];
}

// Function to find (m[][] ^ expo)
vector<vector<int>> power(vector<vector<int>>& m, int expo) {
  
    // Initialize result with identity matrix
    vector<vector<int>> res = { { 1, 0 }, { 0, 1 } };

    while (expo) {
        if (expo & 1)
            multiply(res, m);
        multiply(m, m);
        expo >>= 1;
    }

    return res;
}

int countWays(int n) {
  
    // base case
    if (n == 0 || n == 1)
        return 1;

    vector<vector<int>> m = { { 1, 1 }, { 1, 0 } };
  
    // Matrix initialMatrix = {{f(1), 0}, {f(0), 0}}, where f(0)
    // and f(1) are first two terms of sequence
    vector<vector<int>> initialMatrix = { { 1, 0 }, { 1, 0 } };

    // Multiply matrix m (n - 1) times
    vector<vector<int>> res = power(m, n - 1);

    multiply(res, initialMatrix);

    return res[0][0];
}

int main() {
    int n = 4;
    cout << countWays(n);
    return 0;
}