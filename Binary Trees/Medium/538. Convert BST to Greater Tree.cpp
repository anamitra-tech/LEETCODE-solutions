class Solution {
public:
    int sum = 0;  // global or member variable to maintain running sum

    void dfs(TreeNode* root) {
        if (!root) return;

        dfs(root->right);          // Right

        sum += root->val;          // Update sum
        root->val = sum;           // Update current node's value

        dfs(root->left);           // Left
    }

    TreeNode* convertBST(TreeNode* root) {
        sum = 0;                   // reset sum before starting
        dfs(root);
        return root;
    }
};
