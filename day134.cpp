// C++ program for activity selection problem
// when input activities may not be sorted.
#include <bits/stdc++.h>
using namespace std;

// Function to solve the activity selection problem
int activitySelection(vector<int> &start, vector<int> &finish)
{

    // to store results.
    int ans = 0;

    // Minimum Priority Queue to sort activities in
    // ascending order of finishing time (end[i]).
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;

    for (int i = 0; i < start.size(); i++)
    {
        p.push(make_pair(finish[i], start[i]));
    }

    // to store the end time of last activity
    int finishtime = -1;

    while (!p.empty())
    {
        pair<int, int> activity = p.top();
        p.pop();
        if (activity.second > finishtime)
        {
            finishtime = activity.first;
            ans++;
        }
    }
    return ans;
}

int main()
{
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> finish = {2, 4, 6, 7, 9, 9};
    cout << activitySelection(start, finish);
    return 0;
}