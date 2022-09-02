class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        if(!head){
            return NULL;
        }
        
        ListNode*slow=head;
        ListNode*fast=head;
        
        bool flag=false;
        
        while(fast!=NULL && fast->next!=NULL){
            
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast){
                flag=true;
                break;
            }
            
        }
        
        if(flag==false){
            return NULL;
        }
        
        slow=head;
        
        while(slow!=fast){
            
            slow=slow->next;
            fast=fast->next;
            
        }
        
        return slow;
        
    }
};