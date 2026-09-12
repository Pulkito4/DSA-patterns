/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL) return false;
        ListNode *slow = head, *fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *prev = slow;
        slow = slow->next;
        prev->next = NULL;
        while (slow != NULL) {
            ListNode *temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }
        slow = prev;
        fast = head;
        while (slow != NULL && fast != NULL) {
            if (fast->val != slow->val) return false;
            slow = slow->next;
            fast = fast->next;
        }
        return true;
    }
};
// @lc code=end
