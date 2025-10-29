vector<int> nextLargerNodes(ListNode* head) {
    vector<int> vals;
    for (auto p = head; p; p = p->next) vals.push_back(p->val);

    vector<int> ans(vals.size(), 0);
    stack<int> st;  // stores indices

    for (int i = 0; i < vals.size(); i++) {
        while (!st.empty() && vals[i] > vals[st.top()]) {
            ans[st.top()] = vals[i];
            st.pop();
        }
        st.push(i);
    }

    return ans;
}
