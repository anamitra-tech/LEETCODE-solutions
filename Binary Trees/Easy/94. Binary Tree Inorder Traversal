class Solution {
public:
    void inorder(TreeNode* root, vector<int>& result) {
        if (!root) return;

        inorder(root->left, result);          // left
        result.push_back(root->val);          // root
        inorder(root->right, result);         // right
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder(root, result);
        return result;
    }
};
