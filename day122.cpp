// c++ program to find the minimum number
// of jumps to reach the end of the array
#include <bits/stdc++.h>
using namespace std;

// Function to return the minimum number
// of jumps to reach arr end.
int minJumps(vector<int> &arr) {
    int n = arr.size();

    // array to memoize values
    vector<int> dp(n, INT_MAX);
    dp[n - 1] = 0;

    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j <= i + arr[i] && j < n; j++) {
            if (dp[j] != INT_MAX) {
                dp[i] = min(dp[i], 1 + dp[j]);
            }
        }
    }

    // If end cannot be reached.
    if (dp[0] == INT_MAX)
        return -1;

    return dp[0];
}

int main() {
  
    vector<int> arr = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    cout << minJumps(arr);
    return 0;
}