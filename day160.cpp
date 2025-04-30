#include <iostream>
#include <vector>
using namespace std;

vector<int> singleNum(vector<int> &arr) {
    
    // Get the XOR of the two numbers we need to find
    int xorVal = 0;
    for (auto i : arr) {
        xorVal = i ^ xorVal;
    }

    // Get its last set bit
    xorVal &= -xorVal;

    vector<int> res(2, 0);
    
    for (int num : arr) {
        // If bit is not set, it belongs to the first set
        if ((num & xorVal) == 0) { 
            res[0] ^= num;
        }
        
        // If bit is set, it belongs to the second set
        else { 
            res[1] ^= num;
        }
    }

    // Ensure the order of the returned numbers is consistent
    if (res[0] > res[1]) {
        swap(res[0], res[1]);
    }

    return res;
}

int main() {
    vector<int> arr = { 1, 2, 3, 2, 1, 4 };
    vector<int> ans = singleNum(arr);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}