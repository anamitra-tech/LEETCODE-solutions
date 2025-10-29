/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode* next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }

        // Step 1: Use slow and fast pointers to find the middle
        ListNode* slow = head;
        ListNode* fast = head;
        
        // Move slow pointer one step and fast pointer two steps at a time
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half of the list
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        ListNode* nextNode;

        while (curr != nullptr) {
            nextNode = curr->next;  // Store the next node
            curr->next = prev;      // Reverse the current node's pointer
            prev = curr;            // Move prev pointer to current node
            curr = nextNode;        // Move to the next node
        }

        // Step 3: Compare the first half and the reversed second half
        ListNode* firstHalf = head;
        ListNode* secondHalf = prev;  // The second half is now reversed

        while (secondHalf != nullptr) {
            if (firstHalf->val != secondHalf->val) {
                return false;  // Return false if values don't match
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        return true;  // Return true if the list is a palindrome
    }
};
