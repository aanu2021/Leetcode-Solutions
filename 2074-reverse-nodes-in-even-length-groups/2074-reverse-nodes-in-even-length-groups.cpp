class Solution {
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        ListNode*dummy=new ListNode(-1);
        dummy->next=head;
        
        int k=1;
        
        int cnt=0;
        
        ListNode*prev=dummy;
        ListNode*curr=dummy;
        ListNode*next=dummy;
        
        while(curr!=NULL){
            curr=curr->next;
            cnt++;
        }
        
        while(next!=NULL){
            
            curr=prev->next;
            
            next=(curr==NULL ? NULL : curr->next);
            
            int toLoop=(cnt>k ? k : cnt-1);
            
            if(toLoop%2!=0){
                
                for(int i=1;i<toLoop;i++){
                    curr=curr->next;
                }
                
            }
            
            else{
                
                for(int i=1;i<toLoop;i++){
                    curr->next=next->next;
                    next->next=prev->next;
                    prev->next=next;
                    next=curr->next;
                }
                
            }
            
            prev=curr;
            cnt-=k;
            k++;
            
        }
        
        return dummy->next;
        
    }
};