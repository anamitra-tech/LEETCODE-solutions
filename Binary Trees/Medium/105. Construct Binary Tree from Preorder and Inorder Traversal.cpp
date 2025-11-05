#include <vector>
#include <unordered_map>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int preIndex = 0;

    Node* buildTree(vector<int>& preorder, vector<int>& inorder, 
                    int start, int end, unordered_map<int,int>& inMap) {
        if (start > end) return nullptr;

        // Step 1: Create root node from preorder
        int rootVal = preorder[preIndex++];
        Node* root = new Node(rootVal);

        // Step 2: Find root index in inorder
        int inIndex = inMap[rootVal];

        // Step 3: Recursively build left and right subtrees
        root->left = buildTree(preorder, inorder, start, inIndex - 1, inMap);
        root->right = buildTree(preorder, inorder, inIndex + 1, end, inMap);

        return root;
    }

    Node* buildTreeMain(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> inMap;
        for (int i = 0; i < inorder.size(); i++)
            inMap[inorder[i]] = i;

        return buildTree(preorder, inorder, 0, inorder.size() - 1, inMap);
    }
};
