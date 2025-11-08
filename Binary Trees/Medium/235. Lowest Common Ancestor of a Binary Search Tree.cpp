class Solution {
public:
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;

        // both p and q smaller → go left
        if ((p->val < root->val) && (q->val < root->val)) {
            TreeNode* left = dfs(root->left, p, q);
            return left;
        }

        // both p and q greater → go right
        if ((p->val > root->val) && (q->val > root->val)) {
            TreeNode* right = dfs(root->right, p, q);
            return right;
        }

        // otherwise one on left and one on right (or root == p/q)
        return root;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root, p, q);
    }
};
