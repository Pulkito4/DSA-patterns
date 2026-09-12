/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
 */

// @lc code=start
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL) return;
        vector<ListNode*> nodes;
        ListNode* curr = head;
        while (curr != NULL) {
            nodes.push_back(curr);
            curr = curr->next;
        }
        int left = 0;
        int right = nodes.size() - 1;
        while (left < right) {
            nodes[left]->next = nodes[right];
            left++;
            if (left == right) break;
            nodes[right]->next = nodes[left];
            right--;
        }
        nodes[left]->next = NULL;
    }
};
// @lc code=end
