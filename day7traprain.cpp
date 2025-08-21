#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int trap(vector<int>& height) 
    {
        if (height.empty() || height.size() < 3) 
        {
            return 0;
        }
        
        int left = 0;
        int right = height.size() - 1;
        int maxLeft = 0;
        int maxRight = 0;
        int totalWater = 0;

        while (left <= right) 
        {
            if (height[left] <= height[right]) 
            {
                if (height[left] >= maxLeft) 
                {
                    maxLeft = height[left];
                } else {
                    totalWater += maxLeft - height[left];
                }
                left++;
            }
            else
            {
                if (height[right] >= maxRight) 
                {
                    maxRight = height[right];
                }
                else 
                {
                    totalWater += maxRight - height[right];
                }
                right--;
            }
        }
        return totalWater;
    }
};

int main() 
{
    Solution sol;
    vector<int> test1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    vector<int> test2 = {4, 2, 0, 3, 2, 5};
    vector<int> test3 = {1, 1, 1};
    vector<int> test4 = {5};
    vector<int> test5 = {2, 0, 2};

    cout << "Test 1: [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1] -> " << sol.trap(test1) << endl;
    cout << "Test 2: [4, 2, 0, 3, 2, 5] -> " << sol.trap(test2) << endl;
    cout << "Test 3: [1, 1, 1] -> " << sol.trap(test3) << endl;
    cout << "Test 4: [5] -> " << sol.trap(test4) << endl;
    cout << "Test 5: [2, 0, 2] -> " << sol.trap(test5) << endl;
    return 0;
}