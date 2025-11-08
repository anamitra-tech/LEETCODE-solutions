TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) return nullptr;

    if (root == p || root == q)
        return root;

    TreeNode* left = dfs(root->left, p, q);
    TreeNode* right = dfs(root->right, p, q);

    if (left && right)
        return root;

    return left ? left : right;
}
