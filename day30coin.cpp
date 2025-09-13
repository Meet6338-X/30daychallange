#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int coinChange(vector<int>& coins, int amount) 
{
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;

    for (int i = 1; i <= amount; ++i) 
    {
        for (int coin : coins) 
        {
            if (i >= coin) 
            {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}
int main() 
{
    vector<int> coins1 = {1, 2, 5};
    int amount1 = 11;
    cout << "Output 1: " << coinChange(coins1, amount1) << endl;

    vector<int> coins2 = {2};
    int amount2 = 3;
    cout << "Output 2: " << coinChange(coins2, amount2) << endl;

    vector<int> coins3 = {1};
    int amount3 = 0;
    cout << "Output 3: " << coinChange(coins3, amount3) << endl;

    return 0;
}