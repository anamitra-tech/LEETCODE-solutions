void dfs(TreeNode* root, int sum, int targetSum, 
         vector<int>& path, vector<vector<int>>& result) {
    if (!root) return;

    path.push_back(root->val);
    sum += root->val;

    if (!root->left && !root->right && sum == targetSum) {
        result.push_back(path);
    }

    dfs(root->left, sum, targetSum, path, result);
    dfs(root->right, sum, targetSum, path, result);

    path.pop_back();
}
