#include <vector>
#include <iostream>
using namespace std;
vector<long long> primefact(long long N) 
{
    vector<long long> factors;
    while (N % 2 == 0) {
        factors.push_back(2);
        N /= 2;
    }

    for (long long i = 3; i * i <= N; i += 2) 
    {
        while (N % i == 0) {
            factors.push_back(i);
            N /= i;
        }
    }
    if (N > 2) 
    {
        factors.push_back(N);
    }

    return factors;
}

void runTestCase(long long n) 
{
    vector<long long> result = primefact(n);
    cout << "Input: N = " << n << "\nOutput: [";
    for (int i = 0; i < result.size(); i++) 
    {
        cout << result[i];
        if (i != result.size() - 1) cout << ", ";
    }
    cout << "]\n\n";
}

int main() 
{
    runTestCase(30);
    runTestCase(49);
    runTestCase(19);
    runTestCase(64);
    runTestCase(123456);

    return 0;
}
