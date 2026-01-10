class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        const int MOD = 1e9 + 7;
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        
        dp[0][0] = 1; // base case: 1 way to reach sum=0 with 0 dice

        for (int dice = 1; dice <= n; dice++) {
            for (int sum = 1; sum <= target; sum++) {
                long long ways = 0;
                for (int face = 1; face <= k; face++) {
                    if (sum - face >= 0) {
                        ways += dp[dice-1][sum-face];
                    }
                }
                dp[dice][sum] = ways % MOD;
            }
        }
        
        return dp[n][target];
    }
};
