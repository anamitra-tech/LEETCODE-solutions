class Solution {
public:
    int ans = 0;
    int maxDepth = -1;

    int findBottomLeftValue(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }

    void dfs(TreeNode* root, int depth) {
        if (!root) return;

        if (root->left) {
            if (!root->left->left && !root->left->right) {
                // Left leaf → check if it's deeper
                if (depth + 1 > maxDepth) {
                    maxDepth = depth + 1;
                    ans = root->left->val;
                }
            } else {
                dfs(root->left, depth + 1);
            }
        }

        // Always check right subtree too
        if (root->right) {
            dfs(root->right, depth + 1);
        }

        // Optional: check current root as well
        if (!root->left && !root->right) {
            if (depth > maxDepth) {
                maxDepth = depth;
                ans = root->val;
            }
        }
    }
};
