vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result(nums1.size(), -1); // Default: -1 for all
        unordered_map<int, int> indexMap;     // To store nums1[i] → i
        stack<int> stk;

        // Map each number in nums1 to its index
        for (int i = 0; i < nums1.size(); i++) {
            indexMap[nums1[i]] = i;
        }

        // Traverse nums2 and use stack to track decreasing sequence
        for (int num : nums2) {
            while (!stk.empty() && num > stk.top()) {
                int top = stk.top();
                stk.pop();

                // If top is in nums1, update its next greater in result
                if (indexMap.count(top)) {
                    int idx = indexMap[top];
                    result[idx] = num;
                }
            }

            stk.push(num);
        }

        return result;
    }
