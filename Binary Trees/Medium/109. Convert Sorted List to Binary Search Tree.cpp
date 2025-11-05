class Solution {
public:
    // Function to find the middle node between head and tail (exclusive)
    ListNode* findMiddle(ListNode* head, ListNode* tail) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != tail && fast->next != tail) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Recursive function to build BST
    TreeNode* buildBST(ListNode* head, ListNode* tail) {
        if (head == tail) return nullptr;

        ListNode* mid = findMiddle(head, tail);
        TreeNode* root = new TreeNode(mid->val);

        root->left = buildBST(head, mid);
        root->right = buildBST(mid->next, tail);

        return root;
    }

    // Main function to convert sorted list to BST
    TreeNode* sortedListToBST(ListNode* head) {
        return buildBST(head, nullptr);
    }
};
