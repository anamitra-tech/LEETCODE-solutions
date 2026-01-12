#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;

        int n = prices.size();
        int K = 2;
        // dp[k][0] -> max profit with k transactions, not holding stock
        // dp[k][1] -> max profit with k transactions, holding stock
        vector<vector<int>> dp(K+1, vector<int>(2, 0));

        // Initialize holding state
        for (int k = 0; k <= K; ++k) {
            dp[k][1] = -prices[0];
        }

        for (int i = 1; i < n; ++i) {
            for (int k = K; k >= 1; --k) {
                dp[k][0] = max(dp[k][0], dp[k][1] + prices[i]);     // sell
                dp[k][1] = max(dp[k][1], dp[k-1][0] - prices[i]);   // buy
            }
        }

        return dp[K][0];
    }
};

