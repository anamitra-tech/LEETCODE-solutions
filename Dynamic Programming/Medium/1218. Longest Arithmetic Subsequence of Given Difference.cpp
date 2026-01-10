class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> dp;
        int ans = 0;

        for (int num : arr) {
            int temp = num - difference;
            int tempAns = 0;

            if (dp.count(temp)) {              // only if temp exists
                tempAns = dp[temp];
            }

            dp[num] = 1 + tempAns;             // update current subsequence length
            ans = max(ans, dp[num]);           // update global answer
        }

        return ans;
    }
};
