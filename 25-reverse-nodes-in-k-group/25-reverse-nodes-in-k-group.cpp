class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        ListNode*dummy=new ListNode(-1);
        
        dummy->next=head;
        
        int count=0;
        
        ListNode*prev=dummy;
        ListNode*curr=dummy;
        ListNode*next=dummy;
        
        while(curr!=NULL){
            curr=curr->next;
            count++;
        }
        
        while(next!=NULL){
            
            curr=prev->next;
            next=curr->next;
            
            int toLoop=(count>k ? k : 1);
            
            for(int i=1;i<toLoop;i++){
                
                curr->next=next->next;
                next->next=prev->next;
                prev->next=next;
                next=curr->next;
                
            }
            
            count-=k;
            prev=curr;
            
        }
        
        return dummy->next;
        
    }
};