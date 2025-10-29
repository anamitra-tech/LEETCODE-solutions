class Solution {
public:
    int minSwaps(string s) {
        int balance = 0, maxUnbalanced = 0;
        
        for (char c : s) {
            if (c == '[') {
                balance++; // Increase balance for open brackets
            } else {
                balance--; // Decrease balance for close brackets
            }
            maxUnbalanced = min(maxUnbalanced, balance); // Track most unbalanced point
        }
        
        return (-maxUnbalanced + 1) / 2; // Minimum swaps to fix imbalance
    }
};
