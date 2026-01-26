class Solution {
public:
    int maxDiameter = 0;

    int dfs(TreeNode* root) {
        if (!root) return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);

        // Update max diameter at this node
        maxDiameter = max(maxDiameter, left + right);

        return 1 + max(left, right); // return depth
    }

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return maxDiameter;
    }
};
