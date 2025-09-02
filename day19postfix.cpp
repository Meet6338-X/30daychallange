#include <string>
#include <stack>
#include <vector>
#include <iostream>
#include <sstream>
#include <cmath>   

using namespace std;

int evaluatePostfix(string expr) 
{
    stringstream ss(expr);
    string token;
    stack<long long> st;

    while (ss >> token) 
    {
        if (token == "+" || token == "-" || token == "*" || token == "/" || token == "^")
        {
            long long b = st.top(); st.pop();
            long long a = st.top(); st.pop();
            if (token == "+") st.push(a + b);
            else if (token == "-") st.push(a - b);
            else if (token == "*") st.push(a * b);
            else if (token == "/") 
            {
                st.push(a / b);
            }
            else if (token == "^") 
            {
                st.push((long long)pow((long double)a, (long double)b));
            }
        } 
        else 
        {
            st.push(stoll(token)); 
        }
    }

    return (int)st.top();
}

int main() 
{
    vector<string> tests = 
    {
        "2 1 + 3 *",                          
        "5 6 +",                              
        "-5 6 -",                             
        "15 7 1 1 + - / 3 * 2 1 1 + + -",     
        "5",                                  
        "3 4 2 * 1 5 - 2 3 ^ ^ / +"           
    };

    for (string t : tests) 
    {
        cout << "Input: " << t << "\nOutput: " << evaluatePostfix(t) << "\n\n";
    }
    return 0;
}
