#include <iostream>
#include <vector>
using namespace std;
vector<int> findlead(vector<int>& arr) 
{
    int n = arr.size();
    vector<int> leaders;
    int maxFromRight = arr[n - 1];
    leaders.push_back(maxFromRight);
    for (int i = n - 2; i >= 0; i--) 
    {
        if (arr[i] >= maxFromRight) 
        {
            leaders.push_back(arr[i]);
            maxFromRight = arr[i];
        }
    }
    int i = 0, j = leaders.size() - 1;
    while (i < j) 
    {
        int temp = leaders[i];
        leaders[i] = leaders[j];
        leaders[j] = temp;
        i++;
        j--;
    }
    return leaders;
}

int main() 
{
    vector<int> arr = {16, 17, 4, 3, 5, 2};
    vector<int> leaders = findlead(arr);

    cout << "Leaders: ";
    for (int x : leaders) 
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}