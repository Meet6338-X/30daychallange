#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution 
{
public:
    int lstring(string s) 
    {
        vector<int> lastIndex(256, -1);
        int n = s.size();
        int left = 0, maxLen = 0;

        for (int right = 0; right < n; right++) 
        {
            char c = s[right];
            if (lastIndex[c] >= left) 
            {
                left = lastIndex[c] + 1;
            }

            lastIndex[c] = right;
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};

int main() 
{
    Solution sol;
    cout << sol.lstring("abcabcbb") << endl; 
    cout << sol.lstring("bbbbb") << endl;    
    cout << sol.lstring("pwwkew") << endl;   
    cout << sol.lstring("abcdefgh") << endl; 
    cout << sol.lstring("a") << endl;        
    return 0;
}