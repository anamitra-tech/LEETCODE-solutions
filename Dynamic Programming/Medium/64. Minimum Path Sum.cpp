#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));

        // Base case: destination cell
        dp[n-1][m-1] = grid[n-1][m-1];

        // Fill dp table backward
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {

                if (i == n - 1 && j == m - 1)
                    continue;

                int down  = (i + 1 < n) ? dp[i + 1][j] : INT_MAX;
                int right = (j + 1 < m) ? dp[i][j + 1] : INT_MAX;

                dp[i][j] = grid[i][j] + min(down, right);
            }
        }

        return dp[0][0];
    }
};
