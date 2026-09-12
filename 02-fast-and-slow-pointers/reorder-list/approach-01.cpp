/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;      
        ListNode* curr = head;         
        while (curr!=NULL) {
            ListNode* next = curr->next; 
            curr->next = prev;           
            prev = curr;                 
            curr = next;                 
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        ListNode* curr = head;
        // Need at least 3 nodes left to make reversing worth it
        while (curr != NULL && curr->next != NULL && curr->next->next != NULL) {
            ListNode* reversedHead = reverseList(curr->next);            
            curr->next = reversedHead;            
            curr = curr->next;
        }
        return;

    }
};
// @lc code=end
