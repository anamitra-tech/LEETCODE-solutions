class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<long long> dp(target + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= target; i++) {
            for (int num : nums) {
                if (num > i) break;
                dp[i] += dp[i - num];

                // Clamp to avoid overflow
                if (dp[i] > INT_MAX) dp[i] = INT_MAX;
            }
        }
        return (int)dp[target];
    }
};
