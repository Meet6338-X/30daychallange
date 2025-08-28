#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution 
{
public:
    int atMostK(string s, int k) 
    {
        if (k == 0) return 0;
        int n = s.size();
        int left = 0, count = 0;
        unordered_map<char, int> freq;

        for (int right = 0; right < n; right++)
        {
            freq[s[right]]++;

            while ((int)freq.size() > k) 
            {
                freq[s[left]]--;
                if (freq[s[left]] == 0) 
                {
                    freq.erase(s[left]);
                }
                left++;
            }
            count += (right - left + 1);
        }
        return count;
    }

    int substrCount(string s, int k) 
    {
        return atMostK(s, k) - atMostK(s, k - 1);
    }
};

int main() 
{
    Solution sol;
    cout << sol.substrCount("pqpqs", 2) << endl;       
    cout << sol.substrCount("aabacbebebe", 3) << endl;
    cout << sol.substrCount("a", 1) << endl;           
    cout << sol.substrCount("abc", 3) << endl;         
    cout << sol.substrCount("abc", 2) << endl;         

    return 0;
}
