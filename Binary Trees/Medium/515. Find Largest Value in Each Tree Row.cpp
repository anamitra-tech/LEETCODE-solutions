class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
 
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            int maxVal = INT_MIN; 

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* temp = q.front();
                q.pop();

                maxVal = max(maxVal, temp->val);  // Track max at this level

                if (temp->left)
                    q.push(temp->left);

                if (temp->right)
                    q.push(temp->right);
            }

            result.push_back(maxVal);
        }

        return result;
    }
};
