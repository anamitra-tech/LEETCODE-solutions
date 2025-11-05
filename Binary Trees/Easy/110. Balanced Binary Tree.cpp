/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // Helper function returns height if balanced, or -1 if unbalanced
    int checkHeight(TreeNode* root) {
        if (!root) return 0;

        int leftHeight = checkHeight(root->left);
        if (leftHeight == -1) return -1;

        int rightHeight = checkHeight(root->right);
        if (rightHeight == -1) return -1;

        if (abs(leftHeight - rightHeight) > 1)
            return -1;

        return max(leftHeight, rightHeight) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
};
