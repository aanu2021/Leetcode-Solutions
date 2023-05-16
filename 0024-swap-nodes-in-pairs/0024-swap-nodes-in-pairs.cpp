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
    ListNode* swapPairs(ListNode* head) {
        
        if(!head || !head->next) return head;
        
        ListNode*nexthead = head->next;
        ListNode*nextnexthead = head->next->next;
       
        nextnexthead = swapPairs(nextnexthead);
        nexthead->next = head;
        head->next = nextnexthead;
        
        return nexthead;
        
    }
};