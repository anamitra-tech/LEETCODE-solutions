
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // Step 1: Sort by width asc, and height desc if width equal
        sort(envelopes.begin(), envelopes.end(), [](auto &a, auto &b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        int n = envelopes.size();
        vector<int> dp(n, 1);
        int ans = 1;

        // Step 2: Standard LIS on heights
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (envelopes[i][1] > envelopes[j][1] &&
                    envelopes[i][0] > envelopes[j][0]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }

        return ans;
    }
