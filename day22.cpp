// C++ Program to find H-index using Counting Sort

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int hIndex(vector<int> &citations) {

    int n = citations.size();
    vector<int> freq(n + 1);

    // Count the frequency of citations
    for (int i = 0; i < n; i++) {
        if (citations[i] >= n)
            freq[n] += 1;
        else
            freq[citations[i]] += 1;
    }

    int idx = n;
    
    // Variable to keep track of the count of papers
    // having at least idx citations
    int s = freq[n]; 
    while (s < idx) {
        idx--;
        s += freq[idx];
    }
  
    // Return the largest index for which the count of 
    // papers with at least idx citations becomes >= idx
    return idx;
}

int main() {
    vector<int> citations = {6, 0, 3, 5, 3};
    cout << hIndex(citations) << "\n";
    return 0;
}