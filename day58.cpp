// C++ code to find the largest substring with non-repeating
// characters using last index of repeated character

#include <iostream>
#include <vector>
using namespace std;

const int MAX_CHAR = 26;

int longestUniqueSubstr(string& s) {
    int n = s.size();
    int res = 0;

    // last index of all characters is initialized as -1
    vector<int> lastIndex(MAX_CHAR, -1);

    // Initialize start of current window
    int start = 0;

    // Move end of current window
    for (int end = 0; end < n; end++) {

        // Find the last index of s[end]
        // Update starting index of current window as
        // maximum of current value of end and last index + 1
        start = max(start, lastIndex[s[end] - 'a'] + 1);

        // Update result if we get a larger window
        res = max(res, end - start + 1);

        // Update last index of s[end]
        lastIndex[s[end] - 'a'] = end;
    }
    return res;
}

int main() {
    string s = "geeksforgeeks";
    cout << longestUniqueSubstr(s);
    return 0;
}