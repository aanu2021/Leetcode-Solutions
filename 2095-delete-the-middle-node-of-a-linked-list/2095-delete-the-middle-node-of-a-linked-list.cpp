class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        
        if(!head) return NULL;
        
        if(!head->next) return NULL;
        
        ListNode*slow = head;
        ListNode*fast = head;
        
        ListNode*follow = NULL;
        
        while(fast && fast->next){
            
            follow = slow;
            slow = slow->next;
            fast = fast->next->next;
            
        }
        
        if(follow){
            
            follow->next = follow->next->next;
            
        }
        
        return head;
        
    }
};