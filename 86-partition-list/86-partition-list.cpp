class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        
        ListNode*before=new ListNode(-1);
        ListNode*beforehead=before;
        
        ListNode*after=new ListNode(-1);
        ListNode*afterhead=after;
        
        ListNode*ptr=head;
        
        while(ptr!=NULL){
            
            if(ptr->val<x){
                
                beforehead->next=ptr;
                beforehead=beforehead->next;
                
            }
            
            else{
                
                afterhead->next=ptr;
                afterhead=afterhead->next;
                
            }
            
            ptr=ptr->next;
            
        }
        
        afterhead->next=NULL;
        
        beforehead->next=after->next;
        
        return before->next;
        
    }
};