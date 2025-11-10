class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if (!root) return nullptr;

        root->left = pruneTree(root->left);   // Recursively prune left subtree
        root->right = pruneTree(root->right); // Recursively prune right subtree

        // If current node is 0 AND both children are pruned, prune this node
        if (root->val == 0 && root->left == nullptr && root->right == nullptr) {
            return nullptr;
        }

        return root; // Return the node if it should not be pruned
    }
};
