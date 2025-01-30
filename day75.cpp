//C++ program to print unique permutation of string 
//using hash map.
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Recursive function to generate permutations
void genPermutations(int n, string &curr ,unordered_map<char, int> &cnt,
                             vector<string>& res) {
    
    // Base case: If the current permutation length equals the input
    // string length, add it to the result
    if (curr.size() == n) {
        res.push_back(curr);
        return;
    }

    // Iterate through each character in the frequency map
    for (pair<char, int> it: cnt) {
        char c = it.first;
        int count = it.second;

        // Skip characters with a count of 0
        if (count == 0) 
            continue;

        // Include the character in the current permutation
        curr.push_back(c);

        // Decrease its count in the frequency map
        cnt[c]--;

        // Recur to build the next character in the permutation
        genPermutations(n, curr, cnt , res);

        // Backtrack: Remove the character and restore its count
        curr.pop_back();
        cnt[c]++;
    }
}

// Function to find all unique permutations of the input string
vector<string> findPermutation(string s) {
  
  // Vector to store the result
    vector<string> res; 
  
   // Frequency map to count occurrences of each character
    unordered_map<char, int> cnt;   

    // Populate the frequency map with the characters of the input string
    for (char c : s) 
        cnt[c]++;

    // To build permutations
    string curr = "";
    genPermutations(s.size(), curr, cnt, res);
    return res;
}

int main() {
    string s = "ABC";
    vector<string> res = findPermutation(s);

    for (string perm: res)
        cout << perm << " ";

    return 0;
}