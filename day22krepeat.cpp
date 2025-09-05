#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int firstElementKTime(vector<int>& arr, int k) {
    unordered_map<int, int> freq;

    // Step 1: Count frequency
    for (int num : arr) {
        freq[num]++;
    }

    // Step 2: Traverse in order to find first element with freq = k
    for (int num : arr) {
        if (freq[num] == k) {
            return num;
        }
    }

    return -1; // if no element found
}

int main() {
   
    vector<int> arr1 = {3, 1, 4, 4, 5, 2, 6, 1, 4};
    cout << firstElementKTime(arr1,2) << endl; // Expected 1

    vector<int> arr2 = {2, 3, 4, 2, 2, 5, 5};
    cout << firstElementKTime(arr2,2) << endl; // Expected 5

    vector<int> arr3 = {1, 1, 1, 1};
    cout << firstElementKTime(arr3,1) << endl; // Expected -1

    vector<int> arr4 = {10};
    cout << firstElementKTime(arr4,1) << endl; // Expected 10

    vector<int> arr5 = {6, 6, 6, 6, 7, 7, 8, 8, 8};
    cout << firstElementKTime(arr5,3) << endl; // Expected 8
    return 0;
}