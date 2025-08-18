#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
void mergeSort(vector<int>& arr1, vector<int>& arr2) 
{
    int m = arr1.size();
    int n = arr2.size();
    int gap = ceil((m + n) / 2.0);
    while (gap > 0) 
    {
        int i = 0, j = gap;
        while (j < m + n) 
        {
            // Case 1: Both in arr1
            if (i < m && j < m) 
            {
                if (arr1[i] > arr1[j]) swap(arr1[i], arr1[j]);
            }
            // Case 2: i in arr1, j in arr2
            else if (i < m && j >= m) 
            {
                if (arr1[i] > arr2[j - m]) swap(arr1[i], arr2[j - m]);
            }
            // Case 3: Both in arr2
            else if (i >= m && j >= m) 
            {
                if (arr2[i - m] > arr2[j - m]) swap(arr2[i - m], arr2[j - m]);
            }
            i++; j++;
        }
        if (gap == 1)
        {
            gap = 0;
        }
        else
        {
            gap = ceil(gap / 2.0);
        }
    }
}

int main() 
{
    vector<int> arr1 = {1, 3, 5};
    vector<int> arr2 = {2, 4, 6};
    mergeSort(arr1, arr2);
    cout << "arr1: ";
    for (int x : arr1) cout << x << " ";
    cout << "\narr2: ";
    for (int x : arr2) cout << x << " ";
    cout << endl;
    return 0;
}
