// C++ program to minimum number of intervals required 
// to be removed to make remaining intervals non-overlapping
// Using sorting by ending value

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// comparator function
bool compare(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}

int minRemoval(vector<vector<int> >& intervals) {
    int cnt = 0;
  
    // Sort by minimum ending point
    sort(intervals.begin(), intervals.end(), compare);

    int end = intervals[0][1];

    for (int i = 1; i < intervals.size(); i++) {

        // if there is an overlap increase the count
        if (intervals[i][0] < end)
            cnt++;

        // else increment the ending point
        else
            end = intervals[i][1];
    }

    // return the count
    return cnt;
}

int main() {
    vector<vector<int>> intervals = 
                    {{1, 2}, {2, 3}, {3, 5}, {1, 4}};
    cout << minRemoval(intervals) << endl;
}