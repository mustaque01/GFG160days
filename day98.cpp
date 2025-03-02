// C++ program to find Median from Running Data Stream
// Using Heaps
#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
using namespace std;

// Function to find the median of a stream of data
vector<double> getMedian(vector<int> &arr) {
    
    // Max heap to store the smaller half of numbers
    priority_queue<int> leftMaxHeap;
    
    // Min heap to store the greater half of numbers
    priority_queue<int, vector<int>, greater<int>> rightMinHeap;
    
    vector<double> res;
  
    for (int i = 0; i < arr.size(); i++) {
        // Insert new element into max heap
        leftMaxHeap.push(arr[i]);
        
        // Move the top of max heap to min heap to maintain order
        int temp = leftMaxHeap.top();
        leftMaxHeap.pop();
        rightMinHeap.push(temp);
      
        // Balance heaps if min heap has more elements
        if (rightMinHeap.size() > leftMaxHeap.size()) {
            temp = rightMinHeap.top();
            rightMinHeap.pop();
            leftMaxHeap.push(temp);
        }
        
        // Compute median based on heap sizes
        double median;
        if (leftMaxHeap.size() != rightMinHeap.size())
            median = leftMaxHeap.top();
        else
            median = (double)(leftMaxHeap.top() + rightMinHeap.top()) / 2;
        
        res.push_back(median);
    }
    
    return res;
}


int main() {
    vector<int> arr = {5, 15, 1, 3, 2, 8};
    vector<double> res = getMedian(arr);
    cout << fixed << setprecision(2);
    
    for (double median: res) 
        cout << median << " ";
    return 0;
}