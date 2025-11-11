class Solution {
    long totalSum = 0;
    long maxProd = 0;
    const int MOD = 1e9 + 7;

    long getTotalSum(TreeNode* root) {
        if (!root) return 0;
        return root->val + getTotalSum(root->left) + getTotalSum(root->right);
    }

    long computeSubtreeSum(TreeNode* root) {
        if (!root) return 0;

        long left = computeSubtreeSum(root->left);
        long right = computeSubtreeSum(root->right);

        long subtreeSum = left + right + root->val;

        long product = subtreeSum * (totalSum - subtreeSum);
        maxProd = max(maxProd, product);

        return subtreeSum;
    }

public:
    int maxProduct(TreeNode* root) {
        totalSum = getTotalSum(root);
        computeSubtreeSum(root);
        return maxProd % MOD;
    }
};
