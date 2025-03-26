#include <bits/stdc++.h>
using namespace std;

// Function to calculate the maximum stolen value
int findMaxSum(vector<int> &arr) {
    int n = arr.size();

    if (n == 0)
        return 0;
    if (n == 1)
        return arr[0];

    // Set previous 2 values
    int secondLast = 0, last = arr[0];

    // Compute current value using previous two values
    // The final current value would be our result
    int res;
    for (int i = 1; i < n; i++) {
        res = max(arr[i] + secondLast, last);
        secondLast = last;
        last = res;
    }
    return res;
}

int main() {
    vector<int> arr = {6, 5, 5, 7, 4};
    cout << findMaxSum(arr) << endl;
    return 0;
}