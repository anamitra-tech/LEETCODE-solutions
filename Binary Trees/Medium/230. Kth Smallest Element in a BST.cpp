class Solution {
public:
    int count = 0;      // To keep track of how many nodes we’ve visited
    int result = -1;    // To store the kth smallest value

    void inOrder(TreeNode* root, int k) {
        if (!root || result != -1) return;

        inOrder(root->left, k);  // Step 1: Go left

        count++;                 // Step 2: Process current
        if (count == k) {
            result = root->val;
            return;
        }

        inOrder(root->right, k); // Step 3: Go right
    }

    int kthSmallest(TreeNode* root, int k) {
        inOrder(root, k);
        return result;
    }
};
