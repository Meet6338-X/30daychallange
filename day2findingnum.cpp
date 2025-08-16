#include <iostream>
#include <vector>
using namespace std;
int findnum(const vector<int>& arr) 
{
    long long n = arr.size() + 1;
    long long total = n * (n + 1) / 2;
    long long arr_sum = 0;
    for (int num : arr) 
    {
        arr_sum += num;
    }
    return (int)(total - arr_sum);
}

int main() 
{
    cout << "Missing number: " << findnum({1, 2, 4, 5}) << endl;
    cout << "Missing number: " << findnum({2, 3, 4, 5}) << endl;
    cout << "Missing number: " << findnum({1, 2, 3, 4}) << endl;
    cout << "Missing number: " << findnum({1}) << endl;
    vector<int> big;
    for (int i = 1; i <= 999999; i++) big.push_back(i);
    cout << "Missing number: " << findnum(big) << endl;
    return 0;
}
