class Solution {
public:
    int maxSum = INT_MIN;

    int maxGain(TreeNode* root) {
        if (!root) return 0;

        // Recursively get the max gain from left and right (ignore negatives)
        int leftGain = max(0, maxGain(root->left));
        int rightGain = max(0, maxGain(root->right));

        // Check if path THROUGH current node gives a better path sum
        int currentPathSum = root->val + leftGain + rightGain;

        // Update the global maxSum if this path is better
        maxSum = max(maxSum, currentPathSum);

        // For recursion: return max gain if continuing the same path
        return root->val + max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxSum;
    }
};
