class Solution {
public:
    int count = 0;

    void dfs(TreeNode* root, long long sum, int k) {
        if (!root) return;

        // Add current node's value to the sum
        sum += root->val;

        // If sum equals k, increment count
        if (sum == k) count++;

        // Recurse to left and right subtree
        dfs(root->left, sum, k);
        dfs(root->right, sum, k);
    }

    void preorder(TreeNode* root, int k) {
        if (!root) return;

        dfs(root, 0, k);  // call dfs from every node
        preorder(root->left, k);
        preorder(root->right, k);
    }

    int pathSum(TreeNode* root, int k) {
        count = 0;
        preorder(root, k);
        return count;
    }
};
