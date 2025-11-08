class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (!root) return result;

        queue<TreeNode*> q;
        stack<TreeNode*> st;

        q.push(root);

        while (!q.empty()) {
            int size = q.size();

            // Push all nodes of the current level into the stack
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                st.push(node);

                // Add children for the next level
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            // The top of the stack is the rightmost node of the level
            TreeNode* temp = st.top();
            result.push_back(temp->val);

            // Clear the stack for next level
            while (!st.empty())
                st.pop();
        }

        return result;
    }
};
