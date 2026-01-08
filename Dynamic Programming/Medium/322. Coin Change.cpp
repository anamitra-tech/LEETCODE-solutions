class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // dp[i] = minimum number of coins to make amount i
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;  // base case: 0 coins to make 0
        
        // outer loop: try every amount from 1 to amount
        for (int i = 1; i <= amount; i++) {
            // inner loop: try every coin
            for (int j = 0; j < coins.size(); j++) {
                if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX) {
                    dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
                }
            }
        }
        
        return (dp[amount] == INT_MAX) ? -1 : dp[amount];
    }
};
