class Solution {
public:
    void postorder(TreeNode* root, vector<int>& result) {
        if (!root) return;

        postorder(root->left, result);     // left
        postorder(root->right, result);    // right
        result.push_back(root->val);       // root
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postorder(root, result);
        return result;
    }
};
