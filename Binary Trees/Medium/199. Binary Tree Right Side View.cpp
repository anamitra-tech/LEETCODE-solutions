class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            TreeNode* node = nullptr;

            for (int i = 0; i < size; i++) {
                node = q.front();
                q.pop();

                // Push children in the queue
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            // After finishing the level, 'node' is the last node (rightmost)
            result.push_back(node->val);
        }

        return result;
    }
};
