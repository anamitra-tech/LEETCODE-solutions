class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;

        // Step 1: Push all elements of l1 and l2 in stacks
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }

        int carry = 0;
        ListNode* dummy = nullptr;

        // Step 2: Process stacks
        while (!s1.empty() || !s2.empty() || carry) {
            int val1 = 0, val2 = 0;

            if (!s1.empty()) {
                val1 = s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                val2 = s2.top();
                s2.pop();
            }

            // Step 3: Add top values + carry
            int sum = val1 + val2 + carry;

            // Step 4: Compare the sum and determine carry
            if (sum <= 9) {
                carry = 0;
                ListNode* Sum = new ListNode(sum);
                Sum->next = dummy;
                dummy = Sum;
            } else {
                int remainder = sum % 10;
                ListNode* Remainder = new ListNode(remainder);
                Remainder->next = dummy;
                dummy = Remainder;
                carry = sum / 10;
            }
        }

        // Step 5: Return the result list
        return dummy;
    }
};
