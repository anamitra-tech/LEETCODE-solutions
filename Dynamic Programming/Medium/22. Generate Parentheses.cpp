  class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp(n + 1);
        dp[0] = {""};

        for (int i = 1; i <= n; i++) {
            for (int k = 0; k < i; k++) {
                for (const string& left : dp[k]) {
                    for (const string& right : dp[i - 1 - k]) {
                        dp[i].push_back("(" + left + ")" + right);
                    }
                }
            }
        }
        return dp[n];
    }
};
