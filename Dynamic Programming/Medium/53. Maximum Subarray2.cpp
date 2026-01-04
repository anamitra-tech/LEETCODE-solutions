class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int n = a.size();
        vector<int> dp(n);

        dp[n-1] = a[n-1];        // ONLY valid base
        int ans = dp[n-1];

        for (int i = n-2; i >= 0; i--) {
            dp[i] = max(a[i], a[i] + dp[i+1]);
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};
