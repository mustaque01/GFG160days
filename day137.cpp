// C++ program to split the string
// to maximum number of substring
#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum number of substrings
// such that there is no common charcater between them
int maxPartitions(string &s) {
       
    vector<int> first(26, -1), last(26, -1);

    for (int i = 0; i < s.size(); i++) {
        if (first[s[i] - 'a'] == -1) 
            first[s[i] - 'a'] = i;  
        last[s[i] - 'a'] = i;  
    }

    int count = 0;
    int end = 0;

    for (int i = 0; i < s.size(); i++) {
        
        // Expand interval
        end = max(end, last[s[i] - 'a']);  

        // When we reach the end of a partition
        if (i == end) {
            
            // New partition formed
            count++;  
        }
    }

    return count;
       
}

int main() {
    string s = "acbbcc";
    cout<<maxPartitions(s);
}