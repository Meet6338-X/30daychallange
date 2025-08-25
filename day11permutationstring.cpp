#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<string> permuteUnique(string s)
    {
        vector<string> res;
        sort(s.begin(), s.end());           
        vector<bool> used(s.size(), false);
        string path;
        backtrack(s, used, path, res);
        return res;
    }

private:
    void backtrack(string &s, vector<bool> &used, string &path, vector<string> &res) 
    {
        if (path.size() == s.size()) 
        {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < s.size(); i++) 
        {
            if (used[i]) continue;
            if (i > 0 && s[i] == s[i - 1] && !used[i - 1]) continue;
            used[i] = true;
            path.push_back(s[i]);
            backtrack(s, used, path, res);
            path.pop_back();
            used[i] = false;
        }
    }
};

int main() 
{
    Solution sol;
    vector<string> testInputs = {"abc", "aab", "aaa", "a", "abcd"};
    for (auto &inp : testInputs) 
    {
        cout << "Input: " << inp << "\nOutput: ";
        vector<string> result = sol.permuteUnique(inp);
        for (auto &str : result) cout << str << " ";
        cout << "\n\n";
    }
    return 0;
}