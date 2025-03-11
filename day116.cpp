// C++ program to find minimum number
// of operations to convert s1 to s2
#include <bits/stdc++.h>
using namespace std;

int editDistance(string &s1, string &s2) {
    int m = s1.size();
    int n = s2.size();
    
    // Stores dp[i-1][j-1]
    int prev; 
    vector<int> curr(n + 1, 0); 

    for (int j = 0; j <= n; j++)
        curr[j] = j;
  
    for (int i = 1; i <= m; i++) {
        prev = curr[0]; 
        curr[0] = i;
        for (int j = 1; j <= n; j++) {
            int temp = curr[j];
            if (s1[i - 1] == s2[j - 1])
                curr[j] = prev;
            else
                curr[j] = 1 + min({curr[j - 1], prev, curr[j]});
            prev = temp;
        }
    }
    
    return curr[n];
}

int main() {
    string s1 = "abcd";
    string s2 = "bcfe";

    cout << editDistance(s1, s2);

    return 0;
}