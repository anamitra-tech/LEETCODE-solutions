class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;

        int leftDepth = minDepth(root->left);
        int rightDepth = minDepth(root->right);

        // If one of the subtrees is NULL, we have to take the other one
        if (!root->left || !root->right)
            return 1 + leftDepth + rightDepth;

        // If both exist, take the min
        return 1 + min(leftDepth, rightDepth);
    }
};
