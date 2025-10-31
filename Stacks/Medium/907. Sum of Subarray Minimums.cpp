class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int MOD = 1e9 + 7;

        vector<int> left(n), right(n);
        stack<int> st;

        // Find how many elements on the left are greater
        for (int i = 0; i < n; i++) {
            int count = 1;
            while (!st.empty() && arr[st.top()] > arr[i]) {
                count += left[st.top()];
                st.pop();
            }
            left[i] = count;
            st.push(i);
        }

        // Clear stack for right side
        while (!st.empty()) st.pop();

        //  Find how many elements on the right are >= current
        for (int i = n - 1; i >= 0; i--) {
            int count = 1;
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                count += right[st.top()];
                st.pop();
            }
            right[i] = count;
            st.push(i);
        }

        // Calculate total contribution
        long long result = 0;
        for (int i = 0; i < n; i++) {
            long long contribution = (1LL * arr[i] * left[i] * right[i]) % MOD;
            result = (result + contribution) % MOD;
        }

        return result;
    }
};  explain line by line with code
