class Solution {
public:
    TreeNode* prev = nullptr;

    void flatten(TreeNode* root) {
        if (!root) return;

        // Store right child first, since we’ll overwrite it
        TreeNode* leftSub = root->left;
        TreeNode* rightSub = root->right;

        // If prev exists, connect it to current node
        if (prev) prev->right = root;

        root->left = nullptr;  // because we’re flattening
        prev = root;

        // Process left first (as you wanted)
        flatten(leftSub);
        flatten(rightSub);
    }
};
