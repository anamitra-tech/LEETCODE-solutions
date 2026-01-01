 #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> a;
    vector<vector<int>> dp; // 0 = not computed yet
    int n = 0, m = 0;

    bool isLeft(int i, int j) {          // checks (i, j+1)
        if (j + 1 >= m) return false;
        return a[i][j + 1] > a[i][j];
    }

    bool isRight(int i, int j) {         // checks (i, j-1)
        if (j - 1 < 0) return false;
        return a[i][j - 1] > a[i][j];
    }

    bool isUp(int i, int j) {            // checks (i-1, j)
        if (i - 1 < 0) return false;
        return a[i - 1][j] > a[i][j];
    }

    bool isDown(int i, int j) {          // checks (i+1, j)
        if (i + 1 >= n) return false;
        return a[i + 1][j] > a[i][j];
    }

    int backtrack(int i, int j) {
        if (dp[i][j] != 0) return dp[i][j];

        int best = 1; // at least the cell itself

        if (isLeft(i, j))  best = max(best, 1 + backtrack(i, j + 1));
        if (isRight(i, j)) best = max(best, 1 + backtrack(i, j - 1));
        if (isUp(i, j))    best = max(best, 1 + backtrack(i - 1, j));
        if (isDown(i, j))  best = max(best, 1 + backtrack(i + 1, j));

        return dp[i][j] = best;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        a = matrix;
        n = (int)a.size();
        m = (int)a[0].size();
        dp.assign(n, vector<int>(m, 0));

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, backtrack(i, j));
            }
        }
        return ans;
    }
};
