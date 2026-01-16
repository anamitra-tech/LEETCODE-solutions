class Solution {
public:
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = new TreeNode(INT_MIN);
    
    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        if (prev->val > root->val) {
            if (!first) first = prev;
            second = root;
        }
        prev = root;

        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(first->val, second->val);
    }
};



//the problem that u created was that u did ajacent swap but no we would do first and the lsecond method for the sawp of far n
//nodes
