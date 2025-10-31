class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Normal Kadane’s
        int sum = 0;
        int maxSum = INT_MIN;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            maxSum = max(maxSum, sum);
            if (sum < 0) sum = 0;
        }

        // Step 2: Min Kadane’s (to find circular part)
        int minSum = INT_MAX;
        sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            minSum = min(minSum, sum);
            if (sum > 0) sum = 0; // reset if positive
        }

        // Step 3: Total sum of array
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        // Step 4: Handle edge case (all numbers negative)
        if (maxSum < 0) return maxSum;

        // Step 5: Return max of normal and circular
        return max(maxSum, totalSum - minSum);
    }
};
