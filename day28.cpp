// C++ program to count occurence of given target using binary search

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countFreq(vector<int> &arr, int target) {
    int l = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
    int r = upper_bound(arr.begin(), arr.end(), target) - arr.begin();
      
    // Return the differnce between upper
    // bound and lower bound of the target
    return r - l;
}

int main() {
    vector<int> arr = {1, 2, 2, 2, 2, 3, 4, 7, 8, 8};
    int target = 2;
    cout<< countFreq(arr, target);
    return 0;
}