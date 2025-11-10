class Solution {
public:
    unordered_map<string, int> subtreeCount;
    vector<TreeNode*> result;

    string serialize(TreeNode* root) {
        if (!root) return "#";

        string left = serialize(root->left);
        string right = serialize(root->right);
        string subtree = to_string(root->val) + "," + left + "," + right;

        if (subtreeCount[subtree] == 1) {
            result.push_back(root); // only add the second time it's seen
        }

        subtreeCount[subtree]++;
        return subtree;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        serialize(root);
        return result;
    }
};
