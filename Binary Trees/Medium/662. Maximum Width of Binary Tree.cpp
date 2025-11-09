class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        int maxWidth = 0;

        while (!q.empty()) {
            int size = q.size();
            unsigned long long minIndex = q.front().second;
            unsigned long long left = 0, right = 0;

            for (int i = 0; i < size; ++i) {
                auto [node, index] = q.front(); q.pop();
                index -= minIndex; // Normalize to prevent overflow

                if (i == 0) left = index;
                if (i == size - 1) right = index;

                if (node->left)
                    q.push({node->left, 2 * index});
                if (node->right)
                    q.push({node->right, 2 * index + 1});
            }

            maxWidth = max(maxWidth, int(right - left + 1));
        }

        return maxWidth;
    }
};
