#include <bits/stdc++.h>
using namespace std;

// Function to return max profit from k transactions
int maxProfit(vector<int> &prices, int k){
    int n = prices.size();
    if (n == 0 || k == 0)
        return 0;

    vector<vector<int>> curr(k + 1, vector<int>(2, 0));
    vector<vector<int>> next(k + 1, vector<int>(2, 0));

    // Iterate from the last day to the first
    for (int i = n - 1; i >= 0; i--){
        for (int l = 1; l <= k; l++){
          
            // Calculate for buy state
            curr[l][1] = max(-prices[i] + next[l][0], next[l][1]);
          
            // Calculate for sell state
            curr[l][0] = max(prices[i] + next[l - 1][1], next[l][0]);
        }
        // Move current state to next, for the next iteration
        next = curr;
    }

    return curr[k][1];
}

int main(){
    int k = 2;
    vector<int> prices = {10, 22, 5, 80};
    cout << maxProfit(prices, k) << endl;

    return 0;
}