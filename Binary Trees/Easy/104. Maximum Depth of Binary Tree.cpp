int dfs(Node* root, int count) {
    if (!root) {
        return count;
    }

    int left = dfs(root->left, count + 1);
    int right = dfs(root->right, count + 1);

    return max(left, right);
}
