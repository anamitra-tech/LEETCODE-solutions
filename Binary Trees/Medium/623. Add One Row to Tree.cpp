class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }

        queue<TreeNode*> q;
        q.push(root);
        int level = 1;

        while (!q.empty()) {
            int levelSize = q.size();

            if (level == depth - 1) {
                // At level just above where we need to add new nodes
                for (int i = 0; i < levelSize; ++i) {
                    TreeNode* node = q.front();
                    q.pop();

                    TreeNode* tempLeft = node->left;
                    TreeNode* tempRight = node->right;

                    node->left = new TreeNode(val);
                    node->left->left = tempLeft;

                    node->right = new TreeNode(val);
                    node->right->right = tempRight;
                }
                break;  // No need to traverse further
            }

            // Normal level order traversal
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            level++;
        }

        return root;
    }
};
