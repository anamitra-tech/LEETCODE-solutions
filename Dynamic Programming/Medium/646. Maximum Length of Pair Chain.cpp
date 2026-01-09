

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        // Step 1: Sort pairs based on the end value (greedy choice)
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1]; // Sort by end time in ascending order
        });

        int count = 0;  // Stores the max chain length
        int prevEnd = INT_MIN; // Track the end of the last included interval

        // Step 2: Process pairs
        for (auto& pair : pairs) {
            int start = pair[0], end = pair[1];

            // If this pair does NOT overlap with the previous one, include it
            if (start > prevEnd) {
                count++;  // Increase chain length
                prevEnd = end; // Update last interval's end
            }
        }

        return count;
    }
};
