#include <iostream>
#include <vector>
using namespace std;
string longcommon(vector<string>& strs) 
{
    if (strs.empty()) return "";
    string firstl = strs[0]; 
    for (int i = 1; i < strs.size(); i++) 
    {
        while (strs[i].find(firstl) != 0) 
        { 
            firstl = firstl.substr(0, firstl.size() - 1);
            if (firstl.empty()) return "";
        }
    }
    return firstl;
}

int main() 
{
    vector<vector<string>> testCases = 
    {
        {"flower", "flow", "flight"},
        {"dog", "racecar", "car"},
        {"apple", "ape", "april"},
        {""},
        {"alone"},
        {}
    };
    
    for (auto &tc : testCases) 
    {
        cout << "Input: ";
        if (tc.empty()) cout << "[]";
        else {
            cout << "[";
            for (int i = 0; i < tc.size(); i++) 
            {
                cout << "\"" << tc[i] << "\"";
                if (i != tc.size() - 1) cout << ", ";
            }
            cout << "]";
        }
        cout << "\nOutput: \"" << longcommon(tc) << "\"\n\n";
    } 
    return 0;
}