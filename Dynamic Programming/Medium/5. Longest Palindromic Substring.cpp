class Solution {
public:
    string longestPalindrome(string s) {
        int n = (int)s.size();
        if (n == 0) return "";

        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int bestLen = 1;
        int bestStart = 0;

        // length 1
        for (int i = 0; i < n; i++) dp[i][i] = true;

        // length >= 2
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (s[i] == s[j] && (len <= 3 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                    if (len > bestLen) {
                        bestLen = len;
                        bestStart = i;
                    }
                }
            }
        }
        return s.substr(bestStart, bestLen);
    }
};
