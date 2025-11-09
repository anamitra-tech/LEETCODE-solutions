class Solution {
public:
    int sum = 0;

    int sumRootToLeaf(TreeNode* root) {
        dfs(root, 0);
        return sum;
    }

    void dfs(TreeNode* root, int current) {
        if (!root) return;

        current = (current << 1) | root->val; // shift left + add bit

        // If it's a leaf node
        if (!root->left && !root->right) {
            sum += current;
            return;
        }

        // Otherwise, continue DFS
        dfs(root->left, current);
        dfs(root->right, current);
    }
};
