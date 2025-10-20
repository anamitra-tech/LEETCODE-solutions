class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n+1, 0);

        // Build prefix sum
        for (int i = 0; i < n; ++i)
            prefix[i+1] = prefix[i] + nums[i];

        deque<int> dq;
        int res = n+1;

        for (int i = 0; i <= n; ++i) {
            // Check if we can form a subarray ending at i
            while (!dq.empty() && prefix[i] - prefix[dq.front()] >= k) {
                res = min(res, i - dq.front());
                dq.pop_front();
            }

            // Maintain monotonic increasing deque
            while (!dq.empty() && prefix[i] <= prefix[dq.back()])
                dq.pop_back();

            dq.push_back(i);
        }

        return res == n+1 ? -1 : res;
    }
};
