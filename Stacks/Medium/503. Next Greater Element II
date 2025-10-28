
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n, -1);
        stack<int> stk;  // store indices

        // We'll loop twice for circular behavior
        for (int i = 0; i < 2 * n; i++) {
            int idx = i % n;

            // While stack not empty and current element > top element
            while (!stk.empty() && arr[stk.top()] < arr[idx]) {
                result[stk.top()] = arr[idx];  // next greater found
                stk.pop();
            }

            // Push only first round indices
            if (i < n) stk.push(idx);
        }

        return result;
    }
