/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int sum = 0;            // stores total sum
    int currentNumber = 0;  // tracks number along the path

    void dfs(TreeNode* root) {
        if (!root) return;

        // build current path number
        currentNumber = currentNumber * 10 + root->val;

        // if leaf, add to sum
        if (!root->left && !root->right) {
            sum += currentNumber;
        }

        // recurse left and right
        dfs(root->left);
        dfs(root->right);

        // backtrack to parent
        currentNumber /= 10;
    }

    int sumNumbers(TreeNode* root) {
        dfs(root);
        return sum;
    }
};
