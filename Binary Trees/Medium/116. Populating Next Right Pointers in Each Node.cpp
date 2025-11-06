/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size(); // number of nodes at current level

            Node* prev = nullptr;

            for (int i = 0; i < size; i++) {
                Node* curr = q.front();
                q.pop();

                if (prev != nullptr) {
                    prev->next = curr;
                }
                prev = curr;

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }

            // last node's next is already nullptr by default
        }

        return root;
    }
};
