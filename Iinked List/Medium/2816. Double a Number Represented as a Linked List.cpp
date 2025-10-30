class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        int carry = helper(head);
        if (carry) {
            ListNode* newHead = new ListNode(carry);
            newHead->next = head;
            return newHead;
        }
        return head;
    }

    // Helper to recursively traverse to the end and double values
    int helper(ListNode* node) {
        if (!node) return 0;
        int carry = helper(node->next);
        int sum = node->val * 2 + carry;
        node->val = sum % 10;
        return sum / 10;
    }
};
