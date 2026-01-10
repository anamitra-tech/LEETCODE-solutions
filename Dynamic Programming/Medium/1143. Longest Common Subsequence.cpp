class Solution {
public:
    int longestCommonSubsequence(string a, string b) {
        int n = a.size();
        int m = b.size();

        // dp[i][j] = LCS length of a[0..i-1] and b[0..j-1]
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i-1] == b[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];   // match → take diagonal
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]); // no match → take max of left/top
                }
            }
        }

        return dp[n][m];  // final LCS length
    }
};
