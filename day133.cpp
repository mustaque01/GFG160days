// C++ program to find minimum Platforms Required
// for Given Arrival and Departure Times
#include <iostream>
#include <vector>
using namespace std;

// Function to find the minimum 
// number of platforms required
int minPlatform(vector<int> &arr, vector<int>& dep) {
    int n = arr.size();
    int res = 0;

    // Find the max Departure time 
    int maxDep = dep[0];
    for (int i=1; i<n; i++) {
        maxDep = max(maxDep, dep[i]);
    }

    // Create a vector to store the count of trains at each
    // time
    vector<int> v(maxDep + 2, 0);
    
    // Increment the count at the arrival time and decrement
    // at the departure time
    for (int i = 0; i < n; i++) {
        v[arr[i]]++;
        v[dep[i] + 1]--;
    }
    
    int count = 0;
    
    // Iterate over the vector and keep track of the maximum
    // sum seen so far
    for (int i = 0; i <= maxDep + 1; i++) {
        count += v[i];
        res = max(res, count);
    }
    
    return res;
}

int main() {

    vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};
    cout << minPlatform(arr, dep);
    return 0;
}