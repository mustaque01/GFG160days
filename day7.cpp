#include <iostream>
#include <vector>
using namespace std;

int maximumProfit(vector<int>& prices) {
    int n = prices.size();
    int lMin = prices[0];  // Local Minima
    int lMax = prices[0];  // Local Maxima
    int res = 0;
  
    int i = 0;
    while (i < n - 1) {
      
        // Find local minima 
        while (i < n - 1 && prices[i] >= prices[i + 1]) { i++; }
        lMin = prices[i];
       
        // Local Maxima
        while (i < n - 1 && prices[i] <= prices[i + 1]) { i++; }
        lMax = prices[i];
      
        // Add current profit 
        res = res + (lMax - lMin);
    }
  
    return res;
}

int main() {
    vector<int> prices = {100, 180, 260, 310, 40, 535, 695};
    cout << maximumProfit(prices);
    return 0;
}