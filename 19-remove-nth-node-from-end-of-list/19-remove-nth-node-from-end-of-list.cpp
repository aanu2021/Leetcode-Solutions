class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int k) {
        
        if(!head){
            return NULL;
        }
        
        ListNode*dummy=new ListNode(-1);
        
        dummy->next=head;
        
        ListNode*slow=dummy;
        
        ListNode*fast=dummy;
        
        for(int i=1;i<=k;++i){
            
            fast=fast->next;
            
        }
        
        while(fast->next){
            
            fast=fast->next;
            slow=slow->next;
            
        }
        
        slow->next=slow->next->next;
        
        return dummy->next;
        
    }
};