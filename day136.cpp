// C++ program to find starting index of circular Tour
// using greedy approach in one pass

#include <iostream>
#include <vector>
using namespace std;

int startStation(vector<int> &gas, vector<int> &cost) {
  	int n = gas.size();  
  
    // Variables to track total and current remaining gas
    int totalGas = 0;
    int currGas = 0;
    int startIdx = 0;

    // Traverse through each station to calculate remaining
    // gas in the tank, and total gas 
    for(int i = 0; i < n; i++) {
      	currGas += gas[i] - cost[i]; 
        totalGas += gas[i] - cost[i];  

        // If currGas is negative, circular tour can't 
      	// start with this index, so update it to next one
        if(currGas < 0) {
            currGas = 0;
            startIdx = i + 1; 
        }
    }

    // No solution exist
    if(totalGas < 0) 
        return -1;

    return startIdx;
}

int main() {
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    cout << startStation(gas, cost); 
    return 0;
}