class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> stk;
        ListNode* current = head;

        // Push all nodes onto the stack
        while (current) {
            stk.push(current);
            current = current->next;
        }

        int max_val = INT_MIN;
        ListNode* result = nullptr;

        // Process stack and build result list
        while (!stk.empty()) {
            ListNode* node = stk.top();
            stk.pop();

            if (node->val >= max_val) {
                node->next = result;
                result = node;
                max_val = node->val;
            }
        }

        return result;
    }
};
