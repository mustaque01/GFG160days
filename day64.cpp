#include <iostream>
#include <vector>
using namespace std;

// Function to calculate the product of all elements 
// except the current element
vector<int> productExceptSelf(vector<int> &arr) {
    int zeros = 0, idx = -1;
    int prod = 1;

    // Count zeros and track the index of the zero
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == 0) {
            zeros++;
            idx = i;
        } else {
            prod *= arr[i];
        }
    }

    vector<int> res(arr.size(), 0);

    // If no zeros, calculate the product for all elements
    if (zeros == 0) {
        for (int i = 0; i < arr.size(); i++)
            res[i] = prod / arr[i];
    }
    // If one zero, set product only at the zero's index
    else if (zeros == 1)
        res[idx] = prod;

    return res;
}

int main() {
    vector<int> arr = {10, 3, 5, 6, 2};
    vector<int> res = productExceptSelf(arr);

    for (int val : res)
        cout << val << " ";
}