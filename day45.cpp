#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> intersection(vector<int>& a, vector<int>& b) {
  
    // Put all elements of a[] in sa
    unordered_set<int> sa(a.begin(), a.end());  
    vector<int> res;                            

    // Traverse through b[]
    for (int i = 0; i < b.size(); i++) {
      
        // If the element is in sa
        // a) Add it to the result array
        // b) Erase it from sa to avoid duplicates
        if (sa.find(b[i]) != sa.end()) {
            res.push_back(b[i]); 
            sa.erase(b[i]);  
        }
    }

    return res;
}

int main() {
    vector<int> a = {1, 2, 3, 2, 1};
    vector<int> b = {3, 2, 2, 3, 3, 2};

    vector<int> res = intersection(a, b);
  
    for (int i = 0; i < res.size(); i++) 
        cout << res[i] << " ";

    return 0;
}