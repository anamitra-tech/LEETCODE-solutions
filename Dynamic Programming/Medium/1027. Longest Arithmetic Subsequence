 int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;

        // dp[i][diff] = length of arithmetic subsequence ending at index i with difference diff
        vector<unordered_map<int, int>> dp(n);

        int ans = 2; // minimum length is 2
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int diff = nums[i] - nums[j];

                // if a subsequence ending at j with same diff exists, extend it
                if (dp[j].count(diff)) {
                    dp[i][diff] = dp[j][diff] + 1;
                } else {
                    // otherwise start new subsequence with nums[j], nums[i]
                    dp[i][diff] = 2;
                }

                ans = max(ans, dp[i][diff]);
            }
        }
        return ans;
    }
