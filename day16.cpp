// C++ Code to check if two Strings are anagram of 
// each other using Hash map

#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool areAnagrams(string &s1, string &s2) {
    
    // Create a hashmap to store character frequencies
    unordered_map<char, int> charCount;
    
    // Count frequency of each character in string s1
    for(char ch: s1) 
        charCount[ch] += 1;
  
    // Count frequency of each character in string s2
    for(char ch: s2) 
        charCount[ch] -= 1;
  
    // Check if all frequencies are zero
    for (auto& pair : charCount) {
        if (pair.second != 0) {
            return false;
        }
    }
    
    // If all conditions satisfied, they are anagrams
    return true;
}

int main() {
    string s1 = "geeks";
    string s2 = "kseeg";
    cout << (areAnagrams(s1, s2) ? "true" : "false") << endl;

    return 0;
}