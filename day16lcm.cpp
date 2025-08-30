#include <vector>
#include <iostream>
using namespace std;
long long gcd(long long a, long long b)
{
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long lcm(long long a, long long b) 
{
    return (a / gcd(a, b)) * b;
}

int main() 
{
    vector<pair<long long, long long>> testCases = 
    {
        {4, 6},
        {5, 10},
        {7, 3},
        {1, 987654321},
        {123456, 789012}
    };

    for (auto &tc : testCases) 
    {
        cout << "Input: N=" << tc.first << ", M=" << tc.second << endl;
        cout << "Output: " << lcm(tc.first, tc.second) << endl;
        cout << "-----------------------" << endl;
    }

    return 0;
}
