class Solution {
public:
    int count = 0;

    int minCameraCover(TreeNode* root) {
        if(dfs(root) == 0) count++;  // If root itself needs a camera
        return count;
    }

    int dfs(TreeNode* root) {
        if(!root){
            return 1; // null node is covered
        }

        int left = dfs(root->left);
        int right = dfs(root->right);

        if(left == 0 || right == 0){
            count++;
            return 2; // has camera
        }
        else if(left == 2 || right == 2){
            return 1; // covered
        }
        else{
            return 0; // needs camera
        }
    }
};
