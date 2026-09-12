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
    void reorderList(ListNode* head) {
         if(head==NULL || head->next==NULL || head->next->next==NULL){
        return ;
       }
       vector<ListNode*> nodes;
       ListNode* curr = head; 
       while(curr!=NULL){
        nodes.push_back(curr);
        curr=curr->next;
       }

       //using 2 pointers to swap the rightmost and left elements
       int left = 0;
       int right= nodes.size()-1;
       while(left<right){
        nodes[left]->next = nodes[right];
        left++;

        if(left==right){
            break;
        }
        nodes[right]->next=nodes[left];
        right--;
       }
       // update the left node/element so that there is no cycle
        nodes[left]->next=NULL;
        return ;
    }
};
// @lc code=end
