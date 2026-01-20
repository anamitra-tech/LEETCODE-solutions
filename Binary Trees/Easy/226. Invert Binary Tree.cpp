class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;

        TreeNode* temp = new TreeNode(root->val);

        temp->left  = invertTree(root->right);
        temp->right = invertTree(root->left);

        return temp;
    }
};

