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

    ListNode* reverseLL(ListNode* head){
        ListNode* curr = head; 
        ListNode* prev = NULL;
        while(curr!=NULL){
            ListNode *temp = curr->next; 
            curr->next = prev;
            prev = curr;
            curr=temp;
        }
        return prev;
    } 

    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL){
        return ;
       }

        // optimal approach
        // STEP 1: find the middle of the LL
        ListNode *slow = head; 
        ListNode *fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        //now slow is at the middle of the LL
        // Break the LL into 2 parts
        ListNode* secHalf = slow->next;
        slow->next=NULL;

        // STEP2: Reverse the 2nd half of the LL
        fast = reverseLL(secHalf);

        // STEP3: merge the 2 halves alternatively
        slow=head;

        while(fast!=NULL){
            ListNode* t1=slow->next;
            ListNode* t2=fast->next;
            slow->next = fast;
            fast->next=t1;
            slow=t1;
            fast=t2;
        }

       return ;
    }
};
// @lc code=end
