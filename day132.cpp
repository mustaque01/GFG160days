// C++ program to implement word break.
#include <bits/stdc++.h>
using namespace std;

bool wordBreak(string &s, vector<string> &dictionary)
{
    int n = s.size();
    vector<bool> dp(n + 1, 0);
    dp[0] = 1;

    // Traverse through the given string
    for (int i = 1; i <= n; i++)
    {

        // Traverse through the dictionary words
        for (string &w : dictionary)
        {

            // Check if current word is present
            // the prefix before the word is also
            // breakable
            int start = i - w.size();
            if (start >= 0 && dp[start] && s.substr(start, w.size()) == w)
            {
                dp[i] = 1;
                break;
            }
        }
    }
    return dp[n];
}

int main()
{
    string s = "ilike";

    vector<string> dictionary = {"i", "like", "gfg"};

    cout << (wordBreak(s, dictionary) ? "true" : "false") << endl;

    return 0;
}