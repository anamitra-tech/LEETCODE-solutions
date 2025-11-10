class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if (!root) return true;
        
        queue<TreeNode*> q;
        q.push(root);
        bool nullSeen = false;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (!node) {
                nullSeen = true;
            } else {
                if (nullSeen) return false; // Saw a null before and now a non-null → not complete

                q.push(node->left);
                q.push(node->right);
            }
        }

        return true;
    }
};
