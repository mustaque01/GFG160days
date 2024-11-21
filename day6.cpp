// C++ program for finding out majority element in an array
// using hash map

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Function to find Majority element in an array
vector<int> findMajority(vector<int> &arr) {
    int n = arr.size();
    unordered_map<int, int> freq;
    vector<int> res;

    // find frequency of each number
    for (int ele : arr)
        freq[ele]++;

    // Iterate over each key-value pair in the hash map
    for (auto it : freq) {
        int ele = it.first;
        int cnt = it.second;

        // Add the element to the result, if its frequency
        // if greater than floor(n/3)
        if (cnt > n / 3)
            res.push_back(ele);
    }

    if (res.size() == 2 && res[0] > res[1])
        swap(res[0], res[1]);
    return res;
}

int main() {

    vector<int> arr = {2, 2, 3, 1, 3, 2, 1, 1};
    vector<int> res = findMajority(arr);
    for (auto ele : res) {
        cout << ele << " ";
    }
    return 0;
}