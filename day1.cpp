class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        // Code Here
            int largest = -1, second_largest = -1;

    for (int num : arr) {
        if (num > largest) {
            second_largest = largest;
            largest = num;
        } else if (num != largest && num > second_largest) {
            second_largest = num;
        }
    }
    return second_largest;
    }
};