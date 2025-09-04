#include <iostream>
#include <stack>
#include <vector>
using namespace std;
void insertAtBottom(stack<int> &st, int x) {
    if (st.empty()) {
        st.push(x);
        return;
    }
    int topElement = st.top();
    st.pop();
    insertAtBottom(st, x);
    st.push(topElement);
}

void reverseStack(stack<int> &st) {
    if (st.empty()) return;
    int topElement = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, topElement);
}

void printStack(stack<int> st) {
    vector<int> elems;
    while (!st.empty()) {
        elems.push_back(st.top());
        st.pop();
    }
    cout << "[";
    for (int i = elems.size() - 1; i >= 0; i--) {
        cout << elems[i];
        if (i != 0) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    vector<vector<int>> testCases = {
        {3, 2, 1},
        {5},
        {-5, -10, -15},
        {}, 
        {3, 3, 3}
    };

    for (auto &tc : testCases) {
        stack<int> st;
        for (int x : tc) st.push(x);

        cout << "Input: ";
        printStack(st);

        reverseStack(st);

        cout << "Output: ";
        printStack(st);
        cout << "----" << endl;
    }

    return 0;
}