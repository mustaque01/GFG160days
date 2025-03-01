// C++ program for find k closest point to origin 
// Using Quick Select Algorithm

#include <iostream>
#include <vector>

using namespace std;

// Function to calculate squared 
// distance from the origin
int squaredDis(vector<int>& point) {
    return point[0] * point[0] + point[1] * point[1];
}

// Function to partition the array around a pivot
int partition(vector<vector<int>>& points, int left, int right) {
    
    // Last element is chosen as a pivot.
    vector<int> pivot = points[right];
    int i = left;

    for (int j = left; j < right; j++) {
      
          // Elements greater than or equal to pivot
          // are placed in the left side of pivot
        if (squaredDis(points[j]) <= squaredDis(pivot)) {
            swap(points[i], points[j]);
            i++;
        }
    }
    swap(points[i], points[right]);
    
    // The correct sorted position of the pivot
    return i;
}

void quickSelect(vector<vector<int>>& points, int left, int right, int k) {
    if (left <= right) {
        int pivotIdx = partition(points, left, right);
        
        // Count of all elements in the left part
        int leftCnt = pivotIdx - left + 1;
      
        // If leftCnt is equal to k, then we have
        // found the k largest element
        if (leftCnt == k) 
            return;
        
        // Search in the left subarray
        if (leftCnt > k)
            quickSelect(points, left, pivotIdx - 1, k);
            
        // Reduce the k by number of elements already covered
        // and search in the right subarray
        else 
            quickSelect(points, pivotIdx + 1, right, k - leftCnt);
    }
}

// Function to find k closest points to the origin
vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    
    quickSelect(points, 0, points.size() - 1, k);
    
    // First k elements of the array will be the largest
    return vector<vector<int>> (points.begin(), points.begin() + k);
}

int main() {
    vector<vector<int>> points = {{1, 3}, {-2, 2}, 
                            {5, -1}, {3, 2}, {1, 1}};
    int k = 3;
    
    vector<vector<int>> res = kClosest(points, k);
    
    for (vector<int> point : res) {
        cout << "[" << point[0] << ", " << point[1] << "] ";
    }

    return 0;
}