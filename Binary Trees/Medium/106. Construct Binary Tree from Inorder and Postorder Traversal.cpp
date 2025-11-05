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
    int postIndex;  // start from end of postorder array

    Node* buildTree(vector<int>& inorder, vector<int>& postorder, 
                    int start, int end, unordered_map<int,int>& inMap) {
        if (start > end) return nullptr;

        // Step 1: Pick current root from postorder
        int rootVal = postorder[postIndex--];
        Node* root = new Node(rootVal);

        // Step 2: Find this root’s index in inorder
        int inIndex = inMap[rootVal];

        // ⚠️ Step 3: Build RIGHT subtree first (since we’re going backward)
        root->right = buildTree(inorder, postorder, inIndex + 1, end, inMap);
        root->left = buildTree(inorder, postorder, start, inIndex - 1, inMap);

        return root;
    }

    Node* buildTreeMain(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> inMap;
        for (int i = 0; i < inorder.size(); i++)
            inMap[inorder[i]] = i;

        postIndex = postorder.size() - 1;
        return buildTree(inorder, postorder, 0, inorder.size() - 1, inMap);
    }
};
