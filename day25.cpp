// C++ program to insert a new Interval in an array of sorted and 
// non-overlapping interval using Contiguous Interval Merging

#include <iostream>
#include <vector>
using namespace std;

// Function to insert and merge intervals
vector<vector<int>> insertInterval(vector<vector<int>>& intervals,
                                   vector<int> &newInterval) {
    vector<vector<int>> res;
    int i = 0;
    int n = intervals.size();

    // Add all intervals that come before the new interval
    while (i < n && intervals[i][1] < newInterval[0]) {
        res.push_back(intervals[i]);
        i++;
    }

    // Merge all overlapping intervals with the new interval
    while (i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    res.push_back(newInterval);

    // Add all the remaining intervals
    while (i < n) {
        res.push_back(intervals[i]);
        i++;
    }

    return res;
}

int main() {
    vector<vector<int>> intervals = {{1, 3}, {4, 5}, {6, 7}, {8, 10}};
    vector<int> newInterval = {5, 6};
    
    vector<vector<int>> res = insertInterval(intervals, newInterval);
      for (vector<int> interval: res) {
          cout << interval[0] << " " << interval[1] << "\n";
    }
    return 0;
}