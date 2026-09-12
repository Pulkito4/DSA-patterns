/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
 */

// @lc code=start
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        ListNode* curr = head;
        while (curr != NULL && curr->next != NULL && curr->next->next != NULL) {
            ListNode* reversedHead = reverseList(curr->next);
            curr->next = reversedHead;
            curr = curr->next;
        }
    }
};
// @lc code=end
