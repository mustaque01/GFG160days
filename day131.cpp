#include <bits/stdc++.h>
using namespace std;

// Function to evaluate a boolean condition.
bool evaluate(int b1, int b2, char op)
{
    if (op == '&')
        return b1 & b2;
    if (op == '|')
        return b1 | b2;
    return b1 ^ b2;
}

// Function to count ways to parenthesize the expression to get 'True'
int countWays(string s)
{
    int n = s.length();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, 0)));

    // Base case: Single operands (T or F)
    for (int i = 0; i < n; i += 2)
    {
        dp[i][i][1] = (s[i] == 'T');
        dp[i][i][0] = (s[i] == 'F');
    }

    // Iterate over different substring lengths
    for (int len = 2; len < n; len += 2)
    {    
        // len increases by 2 (odd indices are operators)
        for (int i = 0; i < n - len; i += 2)
        {
            int j = i + len;
            
            // Reset values for the current subproblem
            dp[i][j][0] = dp[i][j][1] = 0; 

            for (int k = i + 1; k < j; k += 2)
            { // Iterate over operators
                char op = s[k];
                int leftTrue = dp[i][k - 1][1], leftFalse = dp[i][k - 1][0];
                int rightTrue = dp[k + 1][j][1], rightFalse = dp[k + 1][j][0];

                // Count ways to get True or False
                if (evaluate(1, 1, op))
                    dp[i][j][1] += leftTrue * rightTrue;
                if (evaluate(1, 0, op))
                    dp[i][j][1] += leftTrue * rightFalse;
                if (evaluate(0, 1, op))
                    dp[i][j][1] += leftFalse * rightTrue;
                if (evaluate(0, 0, op))
                    dp[i][j][1] += leftFalse * rightFalse;

                if (!evaluate(1, 1, op))
                    dp[i][j][0] += leftTrue * rightTrue;
                if (!evaluate(1, 0, op))
                    dp[i][j][0] += leftTrue * rightFalse;
                if (!evaluate(0, 1, op))
                    dp[i][j][0] += leftFalse * rightTrue;
                if (!evaluate(0, 0, op))
                    dp[i][j][0] += leftFalse * rightFalse;
            }
        }
    }
    
    // Return ways to make entire expression True
    return dp[0][n - 1][1]; 
}

int main()
{
    string s = "T|T&F^T";
    cout << countWays(s) << endl;
    return 0;
}