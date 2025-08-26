#include <string>
#include <stack>
#include <vector>
#include <iostream>
using namespace std;
class Solution 
{
public:
    bool isValid(string s) 
    {
        if (s.size() % 2 != 0) return false;

        stack<char> st;
        for (char ch : s) 
        {
            if (ch == '(' || ch == '[' || ch == '{') 
            {
                st.push(ch);
            }
            else
            {
                if (st.empty()) return false;
                char top = st.top();
                st.pop();
                if (ch == ')' && top != '(') return false;
                if (ch == ']' && top != '[') return false;
                if (ch == '}' && top != '{') return false;
            }
        }
        return st.empty();
    }
};

int main() 
{
    Solution sol;
    vector<string> testCases = {
        "()",
        "([)]",
        "[{()}]",
        "",
        "{[}"
    };

    for (auto &tc : testCases) 
    {
        cout << "Input: \"" << tc << "\" → Output: "<< boolalpha << sol.isValid(tc) << endl;
    }
    return 0;
}
