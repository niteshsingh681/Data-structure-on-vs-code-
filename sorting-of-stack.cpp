#include <iostream>
#include <stack>
using namespace std;

// Insert an element into the sorted stack
void sortedInsert(stack<int> &st, int val) {
    if (st.empty() || val > st.top()) {
        st.push(val);
        return;
    }
    int top = st.top();
    st.pop();
    sortedInsert(st, val);
    st.push(top);
}

// Recursively sort the stack
void sortStack(stack<int> &st) {
    if (st.empty()) return;

    int top = st.top();
    st.pop();
    sortStack(st);
    sortedInsert(st, top);
}

// Driver code
int main() {
    stack<int> st;
    st.push(3);
    st.push(1);
    st.push(4);
    st.push(2);

    sortStack(st);

    // Output sorted stack
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}
