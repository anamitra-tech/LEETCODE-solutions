class Solution {
public:
    // inorder traversal to get sorted elements
    void inorder(TreeNode* root, vector<int>& arr) {
        if (!root) return;
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }

    // merge two sorted arrays using two pointers
    vector<int> mergeArrays(vector<int>& arr1, vector<int>& arr2) {
        int i = 0, j = 0;
        vector<int> result;

        while (i < arr1.size() && j < arr2.size()) {
            if (arr1[i] < arr2[j])
                result.push_back(arr1[i++]);
            else
                result.push_back(arr2[j++]);
        }

        // add remaining elements
        while (i < arr1.size()) result.push_back(arr1[i++]);
        while (j < arr2.size()) result.push_back(arr2[j++]);

        return result;
    }

    // main function
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> arr1, arr2;
        inorder(root1, arr1);
        inorder(root2, arr2);
        return mergeArrays(arr1, arr2);
    }
};
