class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> currentLevel(levelSize);

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* temp = q.front();
                q.pop();

                // Decide index based on current direction
                int index = leftToRight ? i : (levelSize - 1 - i);
                currentLevel[index] = temp->val;

                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }

            result.push_back(currentLevel);
            leftToRight = !leftToRight; 
        }

        return result;
    }
};
