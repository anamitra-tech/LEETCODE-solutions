class Solution {
public:
    void pushLeft(TreeNode* node, stack<TreeNode*>& stk) {
        while (node) {
            stk.push(node);
            node = node->left;
        }
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> s1, s2;
        vector<int> result;

        pushLeft(root1, s1);
        pushLeft(root2, s2);

        while (!s1.empty() || !s2.empty()) {
            stack<TreeNode*>& s = 
                s2.empty() || (!s1.empty() && s1.top()->val <= s2.top()->val) ? s1 : s2;

            TreeNode* node = s.top(); s.pop();
            result.push_back(node->val);
            pushLeft(node->right, s);  // go right subtree
        }

        return result;
    }
};
