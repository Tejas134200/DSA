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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==nullptr) return nullptr;
        ListNode* cur = head;
        int nn = n;
        ListNode* fast = head;
        while(nn--){
            fast = fast->next;

        }
         if(fast == nullptr) return head->next;
        while(fast&&fast->next){
            cur=cur->next;
            fast=fast->next;
        }
        cur->next = cur->next->next;
        return head;
    }
    
};