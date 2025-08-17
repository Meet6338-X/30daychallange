#include <iostream>
#include <vector>
using namespace std;
int dupli(const vector<int>& arr) 
{
    // Phase 1: Detect cycle
    int slow = arr[0];
    int fast = arr[0];
    do 
    {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while(slow != fast);

    // Phase 2: Find entry point (duplicate number)
    slow = arr[0];
    while(slow != fast)
    {
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
}

int main() 
{
    cout << "Duplicate number: " << dupli({1, 3, 4, 2, 2}) << endl;
    cout << "Duplicate number: " << dupli({3, 1, 3, 4, 2}) << endl;
    cout << "Duplicate number: " << dupli({1, 1}) << endl;
    cout << "Duplicate number: " << dupli({1, 4, 4, 2, 3}) << endl; 

    vector<int> big;
    for (int i = 1; i <= 99999; i++) big.push_back(i);
    big.push_back(50000);
    cout << "Duplicate number: " << dupli(big) << endl;
    return 0;
}