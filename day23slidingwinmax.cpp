#include <vector>
#include <deque>
#include <iostream>
using namespace std;

vector<int> slidingWindowMaximum(vector<int>& arr, int k) {
    deque<int> dq;  
    vector<int> result;
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        // Remove indices that are out of this window
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }

        // Remove smaller elements (not useful)
        while (!dq.empty() && arr[dq.back()] < arr[i]) {
            dq.pop_back();
        }

        dq.push_back(i);

        // Add maximum from window to result
        if (i >= k - 1) {
            result.push_back(arr[dq.front()]);
        }
    }

    return result;
}

void runTest(vector<int> arr, int k) {
    vector<int> ans = slidingWindowMaximum(arr, k);
    for (int x : ans) cout << x << " ";
    cout << endl;
}

int main() {
    runTest({1, 3, -1, -3, 5, 3, 6, 7}, 3); // Expected: 3 3 5 5 6 7
    runTest({1, 5, 3, 2, 4, 6}, 3); // Expected: 5 5 4 6
    runTest({1, 2, 3, 4}, 2); // Expected: 2 3 4
    runTest({7, 7, 7, 7}, 1); // Expected: 7 7 7 7
    runTest({10}, 1); // Expected: 10
    runTest({5, 2, 9, 1}, 1); // Expected: 5 2 9 1
    runTest({4, 4, 4, 4, 4}, 2); // Expected: 4 4 4 4
    return 0;
}

