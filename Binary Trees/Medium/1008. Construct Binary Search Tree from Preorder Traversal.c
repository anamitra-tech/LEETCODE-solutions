class Solution {
public:
    int idx = 0;

    TreeNode* build(vector<int>& preorder, int lower, int upper) {
        if (idx >= preorder.size()) return nullptr;

        int val = preorder[idx];
        if (val < lower || val > upper) return nullptr;

        TreeNode* root = new TreeNode(val);
        idx++;

        root->left = build(preorder, lower, val);     // left subtree: less than root
        root->right = build(preorder, val, upper);    // right subtree: more than root

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder, INT_MIN, INT_MAX);
    }
};
