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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
         unordered_set<int> numSet(nums.begin(), nums.end());
    
    while (head != nullptr && numSet.find(head->val) != numSet.end()) {
        head = head->next;
    }

    ListNode* current = head;
    ListNode* prev = nullptr;
    
    while (current != nullptr) {
        if (numSet.find(current->val) != numSet.end()) {
            prev->next = current->next; 
        } else {
            prev = current; 
        }
        current = current->next;
    }
    
    return head;
        
    }
};