#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Helper function to insert an element into a sorted stack
void insertSorted(stack<int> &st, int x) {
    if (st.empty() || st.top() <= x) {
        st.push(x);
        return;
    }
    int temp = st.top();
    st.pop();
    insertSorted(st, x);
    st.push(temp);
}

// Function to sort the stack using recursion
void sortStack(stack<int> &st) {
    if (st.empty()) return;
    int x = st.top();
    st.pop();
    sortStack(st);
    insertSorted(st, x);
}

// Function to print stack contents in array style [a, b, c]
void printStack(stack<int> st) {
    vector<int> elements;
    while (!st.empty()) {
        elements.push_back(st.top());
        st.pop();
    }
    // elements now has top→bottom, so reverse it for ascending view
    cout << "[";
    for (int i = elements.size() - 1; i >= 0; i--) {
        cout << elements[i];
        if (i != 0) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {

    stack<int> st;
    st.push(3);
    st.push(1);
    st.push(4);
    st.push(2);
    sortStack(st);
    printStack(st);

    // Test Case 1
    stack<int> st1;
    st1.push(7);
    st1.push(1);
    st1.push(5);
    sortStack(st1);
    printStack(st1);  // [1, 5, 7]

    // Test Case 2
    stack<int> st2;
    st2.push(5);
    sortStack(st2);
    printStack(st2);  // [5]

    // Test Case 3
    stack<int> st3;
    st3.push(-3);
    st3.push(14);
    st3.push(8);
    st3.push(2);
    sortStack(st3);
    printStack(st3);  // [-3, 2, 8, 14]

    // Test Case 4
    stack<int> st4;
    sortStack(st4);
    printStack(st4);  // []

    // Test Case 5
    stack<int> st5;
    st5.push(3);
    st5.push(3);
    st5.push(3);
    sortStack(st5);
    printStack(st5);  // [3, 3, 3]

    return 0;
}
