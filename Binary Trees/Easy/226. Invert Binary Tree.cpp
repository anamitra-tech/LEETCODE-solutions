class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;

        // Recursively invert left and right subtrees first (LRN)
        invertTree(root->left);
        invertTree(root->right);

        // Swap left and right child
        swap(root->left, root->right);

        return root;
    }
};
