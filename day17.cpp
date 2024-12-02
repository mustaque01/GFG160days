// C++ program to find the index of the first
// non repeating character using frequency array

#include <iostream>
#include <vector>
using namespace std;

// As the input string can only have lowercase 
// characters, the maximum characters will be 26
const int MAX_CHAR = 26;

char nonRepeatingChar(string &s) {
  
    vector<int> freq(MAX_CHAR, 0);

    // Count the frequency of all characters
    for (char c : s) {
        freq[c - 'a']++;
    }

    // Find the first character with frequency 1
    for (int i = 0; i < s.length(); ++i) {
        if (freq[s[i] - 'a'] == 1)
            return s[i];
    }
    
      // If no character with a frequency of 1 is 
      // found, then return '$'
    return '$';
}

int main() {
    string s = "racecar";
  
    cout << nonRepeatingChar(s);
    return 0;
}