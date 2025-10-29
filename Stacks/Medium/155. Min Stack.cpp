#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    stack<int> st;                    // normal stack
    priority_queue<int, vector<int>, greater<int>> minHeap; // min-heap for min element
    unordered_map<int, int> freq;     // track frequency of elements in heap

    MinStack() {}

    void push(int val) {
        st.push(val);
        minHeap.push(val);
        freq[val]++;
    }

    void pop() {
        if (st.empty()) return;
        int topVal = st.top();
        st.pop();
        freq[topVal]--;

        // Clean the heap top (lazy deletion)
        while (!minHeap.empty() && freq[minHeap.top()] == 0)
            minHeap.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minHeap.top();
    }
};

int main() {
    MinStack ms;
    ms.push(-2);
    ms.push(0);
    ms.push(-3);
    cout << ms.getMin() << endl; // -3
    ms.pop();
    cout << ms.top() << endl;    // 0
    cout << ms.getMin() << endl; // -2
}
