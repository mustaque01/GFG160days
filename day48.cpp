// C++ Code to group anagrams together by using frequency
// as keys

#include <bits/stdc++.h>
using namespace std;

const int MAX_CHAR = 26;

// function to generate hash of word s
string getHash(string &s) {
    string hash;
    vector<int> freq(MAX_CHAR, 0);
    
    // Count frequency of each character
    for(char ch: s)
        freq[ch - 'a'] += 1;
    
    // Append the frequency to construct the hash
    for(int i = 0; i < MAX_CHAR; i++) {
        hash.append(to_string(freq[i]));
        hash.append("$");
    }
    
    return hash;
}

vector<vector<string>> anagrams(vector<string> &arr) {
    vector<vector<string>> res;
    unordered_map<string, int> mp;
    for (int i = 0; i < arr.size(); i++) {
        string key = getHash(arr[i]);
      
        // If key is not present in the hash map, add
        // an empty group (vector) in the result and
        // store the index of the group in hash map
        if (mp.find(key) == mp.end()) {
            mp[key] = res.size();
            res.push_back({});
        }
      
        // Insert the string in its correct group
        res[mp[key]].push_back(arr[i]);
    }
    return res;
}

int main() {
    vector<string> arr = {"act", "god", "cat", "dog", "tac"};
    
    vector<vector<string>> res = anagrams(arr);
    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << "\n";
    }
    return 0;
}