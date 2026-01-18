class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;

        Node* leftmost = root;

        // stop before leaf level
        while (leftmost->left) {
            Node* curr = leftmost;

            while (curr) {
                // same parent
                curr->left->next = curr->right;

                // across parents
                if (curr->next) {
                    curr->right->next = curr->next->left;
                }

                // move horizontally
                curr = curr->next;
            }

            // go down one level
            leftmost = leftmost->left;
        }

        return root;
    }
};
