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
    void constructString(TreeNode *root, string &s){
        if(!root)return;
        s+= to_string(root->val);
        if(root->left){
            s.push_back('(');
            constructString(root->left, s);
            s.push_back(')');
        }
        else if(root->right){
            s+="()";
        }
        if(root->right){
            s.push_back('(');
            constructString(root->right, s);
            s.push_back(')'); 
        }
        
    }
    string tree2str(TreeNode* root) {
        string s="";
        constructString(root, s);
        return s;
    }
};
