class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
       if(head==NULL || head->next==NULL){
          
           return head;
          
       }
        
       int cnt=0;
        
        ListNode*dummy=new ListNode(-1);
        
        dummy->next=head;
        
        ListNode*prev=dummy;
        ListNode*curr=dummy;
        ListNode*next=dummy;
        
        while(curr!=NULL){
            curr=curr->next;
            cnt++;
        }
        
        while(next){
            
            curr=prev->next;
            next=curr->next;
            
            int toLoop=(cnt>k ? k : 0);
            
            for(int i=1;i<toLoop;i++){
                
                curr->next=next->next;
                next->next=prev->next;
                prev->next=next;
                next=curr->next;
                
            }
            
            prev=curr;
            cnt-=k;
            
        }
        
        return dummy->next;
        
    }
};