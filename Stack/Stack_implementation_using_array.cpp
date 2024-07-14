#include <bits/stdc++.h>
using namespace std;

// Implementation of stack using array
class Stack {
public:
    int sz;          // Maximum size of the stack
    vector<int> arr; // Internal storage for stack elements
    int topIndex;    // Index of the top element in the stack

    Stack(int n) {
        sz = n;
        arr.resize(sz);
        topIndex = -1; // Initialize topIndex to -1 indicating the stack is empty
    }

    void push(int x) {
        if (topIndex >= sz - 1) {
            cout << "Stack Overflow" << endl;
            return;
        } else {
            arr[++topIndex] = x; // Increment topIndex and add the element
        }
    }

    void pop() {
        if (topIndex < 0) {
            cout << "Stack Underflow" << endl;
            return;
        }
        topIndex--; // Decrement topIndex to remove the top element
    }

    int top() {
        if (topIndex < 0) {
            cout << "Stack is empty" << endl;
            return 0;
        }
        return arr[topIndex];
    }

    bool isEmpty() {
        return topIndex < 0;
    }
};

int main() {
    Stack st(5);
    st.push(9);
    st.push(19);
    st.push(20);
    st.push(25);
    st.push(94);
    st.push(48);  
    while (!st.isEmpty()) {
        cout << st.top() << endl;
        st.pop();
    }
    return 0;
}
