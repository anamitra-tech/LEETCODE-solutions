bool dfs(TreeNode* root, int& sum) {
    if (!root) return false;

    int leftSum = 0, rightSum = 0;

    if (root->left)
        leftSum = dfsSum(root->left);

    if (root->right)
        rightSum = dfsSum(root->right);

    int total = leftSum + rightSum;

    return (total == root->val);
}

int dfsSum(TreeNode* root) {
    if (!root) return 0;
    return root->val + dfsSum(root->left) + dfsSum(root->right);
}
