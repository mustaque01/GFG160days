// C++ program to find equilibrium index of an array
// using prefix sum and suffix sum variables

#include <iostream>
#include <vector>
using namespace std;

int equilibriumPoint(vector<int>& arr) {
    int prefSum = 0, total = 0;

    // Calculate the array sum
    for (int ele: arr) {
        total += ele;
    }

    // Iterate pivot over all the elements of the array and
    // till left != right
    for (int pivot = 0; pivot < arr.size(); pivot++) {
          int suffSum = total - prefSum - arr[pivot];
          if (prefSum == suffSum) {
              return pivot;
        }
          prefSum += arr[pivot];
    }

    // there is no equilibrium point
    return -1;
}

int main() {
    vector<int> arr = { 1, 7, 3, 6, 5, 6 };

    cout << equilibriumPoint(arr) << endl;
    return 0;
}