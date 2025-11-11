class Solution {
public:
    unordered_map<TreeNode*, int> dp;

    int rob(TreeNode* root) {
        if(!root) return 0;
        if(dp.count(root)) return dp[root];

        int include = root->val;
        // If root has left child, add grandchildren
        if(root->left) {
            include += rob(root->left->left) + rob(root->left->right);
        }
        // If root has right child, add grandchildren
        if(root->right) {
            include += rob(root->right->left) + rob(root->right->right);
        }

        // Exclude current node -> just take children
        int exclude = rob(root->left) + rob(root->right);

        // Maximize between including or excluding
        dp[root] = max(include, exclude);
        return dp[root];
    }
};
