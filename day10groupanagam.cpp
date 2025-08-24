#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
//leetcode 49

class Solution {
public:
    vector<vector<string>> grpanagram(vector<string>& strs) {
        unordered_map<string, vector<string>> ans;

        for (string& s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            ans[key].push_back(s);
        }

        vector<vector<string>> result;
        for (auto& entry : ans) {
            result.push_back(entry.second);
        }

        return result;        
    }
};

void printResult(vector<vector<string>> &res) {
    for (auto &group : res) {
        cout << "[ ";
        for (auto &word : group) cout << word << " ";
        cout << "]";
    }
    cout << "\n";
}

int main() {
    Solution sol;
    vector<string> t1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<string> t2 = {""};
    vector<string> t3 = {"a"};
    vector<string> t4 = {"abc", "bca", "cab", "xyz", "zyx", "yxz"};
    vector<string> t5 = {"abc", "def", "ghi"};
    
    cout << "Test 1: ";
    auto r1 = sol.grpanagram(t1);
    printResult(r1);

    cout << "Test 2: ";
    auto r2 = sol.grpanagram(t2);
    printResult(r2);

    cout << "Test 3: ";
    auto r3 = sol.grpanagram(t3);
    printResult(r3);

    cout << "Test 4: ";
    auto r4 = sol.grpanagram(t4);
    printResult(r4);

    cout << "Test 5: ";
    auto r5 = sol.grpanagram(t5);
    printResult(r5);
    return 0;
}
