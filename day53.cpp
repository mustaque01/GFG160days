// C++ Program to find pair with sum closest to target 
// using Two Pointer Technique

#include <bits/stdc++.h>
using namespace std;

// function to return the pair with sum closest to target
vector<int> sumClosest(vector<int> &arr, int target) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<int> res;
    int minDiff = INT_MAX;

    int left = 0, right = n - 1;

    while (left < right) {
        int currSum = arr[left] + arr[right];

        // Check if this pair is closer than the closest
        // pair so far
        if (abs(target - currSum) < minDiff) {
            minDiff = abs(target - currSum);
            res = {arr[left], arr[right]};
        }

        // If this pair has less sum, move to greater values
        if (currSum < target)
            left++;

        // If this pair has more sum, move to smaller values
        else if (currSum > target)
            right--;

        // If this pair has sum = target, return it
        else
            return res;
    }

    return res;
}

int main() {
    vector<int> arr = {5, 2, 7, 1, 4};
    int target = 10;

    vector<int> res = sumClosest(arr, target);
    if(res.size() > 0)
        cout << res[0] << " " << res[1];
    return 0;
}