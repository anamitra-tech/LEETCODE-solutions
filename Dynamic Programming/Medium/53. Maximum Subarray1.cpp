class Solution {
public:
    int maxSubArray(std::vector<int>& arr) {
        int sum = 0;          // To store the sum of the current subarray
        int maxSum = INT_MIN; // Initialize maxSum to the smallest possible value

        // Iterate over the array
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];        // Add the current element to the sum
            maxSum = std::max(maxSum, sum); // Update maxSum if the current sum is greater

            // If sum becomes negative, reset it to 0
            if (sum < 0) {
                sum = 0;
            }
        }

        return maxSum;  // Return the maximum sum found
    }
};
