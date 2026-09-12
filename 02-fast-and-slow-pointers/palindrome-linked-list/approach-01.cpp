/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
    bool isPalindrome(ListNode* head) {
        if(head==NULL){
            return false;
        }
        ListNode *slow = head; 
        ListNode *fast = head;
        // first lets find the middle of the LL
        while(fast!=NULL && fast->next !=NULL){
            slow = slow->next;
            fast= fast->next->next;
        }
        // now slow is at the middle of LL and we reverse the 2nd half of LL
        ListNode *prev = slow;
        slow = slow->next;
        prev->next=NULL;
        while(slow!=NULL){
            ListNode *temp = slow->next;
            slow->next=prev;
            prev=slow;
            slow = temp;
        }
        slow=prev;
        //now slow is at end of LL, i.e 2nd head from end
        fast=head;
        while(slow!=NULL && fast!=NULL){
            if(fast->val != slow->val){
                return false;
            }
            slow = slow-> next;
            fast=fast->next;
        }
        return true;
    }
};
// @lc code=end
