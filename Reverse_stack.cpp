#include <iostream>
#include <stack>
using namespace std;

// Insert element at the bottom of the stack
void insertAtBottom(stack<int> &st, int val) {
    if (st.empty()) {
        st.push(val);
        return;
    }

    int temp = st.top();
    st.pop();
    insertAtBottom(st, val);
    st.push(temp);
}

// Recursively reverse the stack
void reverseStack(stack<int> &st) {
    if (st.empty()) return;

    int temp = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, temp);
}

// Driver code
int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(28);
    st.push(52);
    st.push(5);

    reverseStack(st);

    // Print reversed stack
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}
