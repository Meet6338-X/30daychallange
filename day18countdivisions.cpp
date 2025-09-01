#include <iostream>
#include <cmath>
using namespace std;
int countDiv(int N) 
{
    int count = 0;
    for (int i = 1; i * 1LL * i <= N; i++) 
    {
        if (N % i == 0) 
        {
            if (i == N / i) 
                count++;
            else 
                count += 2;
        }
    }
    return count;
}

int main() 
{
    int testCases[] = {12, 18, 29, 100, 1, 997};
    int n = sizeof(testCases) / sizeof(testCases[0]);
    for (int i = 0; i < n; i++) 
    {
        int N = testCases[i];
        cout << "Input: " << N 
             << " -> Output: " << countDiv(N) << endl;
    }
    return 0;
}