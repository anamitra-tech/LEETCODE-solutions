class Solution {
public:
    int dfs(TreeNode* root, int minVal, int maxVal) {
        if (!root) return maxVal - minVal;

        // Update min and max seen so far
        minVal = min(minVal, root->val);
        maxVal = max(maxVal, root->val);

        int left = dfs(root->left, minVal, maxVal);
        int right = dfs(root->right, minVal, maxVal);

        return max(left, right);
    }

    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, root->val, root->val);
    }
};
