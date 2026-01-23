class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return nlr(p, q);
    }

    bool nlr(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        if (p->val != q->val) return false;

        bool left = nlr(p->left, q->left);
        bool right = nlr(p->right, q->right);

        
        return left && right;
    }
};
