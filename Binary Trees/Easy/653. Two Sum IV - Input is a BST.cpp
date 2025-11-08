class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> seen;
        dfs(root, seen, k);
        return found;   // return the final answer
    }

private:
    bool found = false;  // ✅ global flag to remember if pair is found

    void dfs(TreeNode* root, unordered_set<int>& seen, int k) {
        if (!root || found) return;  // stop if null or already found

        int diff = k - root->val;
        if (seen.count(diff)) {
            found = true;   // ✅ mark that we found the pair
            return;
        }

        seen.insert(root->val);

        dfs(root->left, seen, k);
        dfs(root->right, seen, k);
    }
};
