#include <bits/stdc++.h>
using namespace std;

// Function to return max profit from at most 2
// transation
int maxProfit(vector<int> prices) {
    
    // Variables to store the maximum profit 
    // after the first and second transactions
    int firstBuy = INT_MIN;  
    int firstSell = 0;      
    int secondBuy = INT_MIN; 
    int secondSell = 0;      
    
    // Iterate over each day's stock prices
    for (int i = 0; i < prices.size(); i++) {

        firstBuy = max(firstBuy, -prices[i]);
        firstSell = max(firstSell, firstBuy + prices[i]);
        secondBuy = max(secondBuy, firstSell - prices[i]);
        secondSell = max(secondSell, secondBuy + prices[i]);
    }
    
    // The result is the maximum 
    // profit after the second sell
    return secondSell;
}

int main() {
    vector<int> prices = { 10, 22, 5, 75, 65, 80 };
    cout << maxProfit(prices);
    return 0;
}