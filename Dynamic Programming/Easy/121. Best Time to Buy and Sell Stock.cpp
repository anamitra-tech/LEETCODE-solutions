class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        vector<int> dp(n, 0);

        // Base case:
        // On the last day, you cannot make any profit
        dp[n-1] = 0;

        int max_future_price = prices[n-1];

        for (int i = n - 2; i >= 0; i--) {
            // Option 1: skip today
            int skip = dp[i + 1];

            // Option 2: buy today, sell at best future price
            int buy = max_future_price - prices[i];

            dp[i] = max(skip, buy);

            // Update future max price
            max_future_price = max(max_future_price, prices[i]);
        }

        return dp[0];
    }
};
