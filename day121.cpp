// C++ program to find minimum of coins
// to make a given change sum
#include<bits/stdc++.h>
using namespace std;

// Function to find the minimum number of 
// coins needed to make the given sum
int minCoins(vector<int> &coins, int sum) {
    
    // Create a DP array to store the minimum coins
    // for each value up to sum
    vector<int> dp(sum+1, INT_MAX);
    
    // Base case: 0 coins are needed to make sum 0
    dp[0] = 0; 
    
    // Iterate over each coin in the coins array
    for (int i=coins.size()-1; i>=0; i--) {
        
        // Iterate through all sums from 1 to the given sum
        for (int j=1; j<=sum; j++) {
            
            // Initialize take and noTake variables
            int take = INT_MAX, noTake = INT_MAX;
            
            // Check if we can take the current coin
            if (j-coins[i]>=0 && coins[i]>0) {
                
                // Get the minimum coins needed for
                // the remaining sum
                take = dp[j-coins[i]]; 
                
                // Increment take if it's a valid option
                if (take != INT_MAX) take++; 
            }
            
            // If we have more coins available,
            // consider not taking the current coin
            
            if (i+1<coins.size())
            // Get the minimum coins needed without
            // taking the current coi
                noTake = dp[j]; 
            
            // Update the DP array with the minimum of
            // taking or not taking the coin
            dp[j] = min(take, noTake);
        }
    }
    
    // found a solution, return the minimum
    // coins needed, otherwise return -1
    if (dp[sum]!=INT_MAX) return dp[sum];
    return -1;
}

int main() {
    vector<int> coins =  {9, 6, 5, 1};
    int sum = 19; 
    cout << minCoins(coins, sum);
    return 0;
}