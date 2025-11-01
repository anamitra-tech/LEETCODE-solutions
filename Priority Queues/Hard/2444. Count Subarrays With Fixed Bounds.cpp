class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int leftBound = -1;   // index of last invalid number
        int lastMin = -1;     // last index where minK appeared
        int lastMax = -1;     // last index where maxK appeared

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < minK || nums[i] > maxK) {
                leftBound = i;
            }
            if (nums[i] == minK) lastMin = i;
            if (nums[i] == maxK) lastMax = i;

            // If both minK and maxK have appeared after leftBound
            int validStart = min(lastMin, lastMax);
            if (validStart > leftBound) {
                ans += (validStart - leftBound);
            }
        }
        return ans;
    }
};
