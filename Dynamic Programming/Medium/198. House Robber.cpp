class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        // dp[i] = maximum money robbed from houses i to n-1
        vector<int> dp(n + 2, 0);

        // base case
        dp[n - 1] = nums[n - 1];

        // fill dp from right to left
        for (int i = n - 2; i >= 0; i--) {
            dp[i] = max(dp[i + 1], nums[i] + dp[i + 2]);
        }

        return dp[0];
    }
};
