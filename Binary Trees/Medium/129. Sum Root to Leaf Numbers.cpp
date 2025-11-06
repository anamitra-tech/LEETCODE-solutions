class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }

    int dfs(TreeNode* node, int currentNumber) {
        if (!node) return 0;

        currentNumber = currentNumber * 10 + node->val;

        // If it's a leaf, return the number formed so far
        if (!node->left && !node->right) {
            return currentNumber;
        }

        // Otherwise, recurse for left and right
        return dfs(node->left, currentNumber) + dfs(node->right, currentNumber);
    }
};
