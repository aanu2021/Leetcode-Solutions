class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        
        ListNode*dummy=new ListNode(-1);
        
        dummy->next=head;
        
        ListNode*prevptr=dummy;
        ListNode*current=dummy;
        ListNode*nextptr=dummy;
        
        
        int count=0;
        
        while(current){
            
            count++;
            current=current->next;
            
        }
        
        while(nextptr!=NULL){
            
            current=prevptr->next;
            nextptr=current->next;
            
            int toForLoop=(count>k ? k : 1);
            
            for(int i=1;i<toForLoop;++i){
                
                current->next=nextptr->next;
                nextptr->next=prevptr->next;
                prevptr->next=nextptr;
                nextptr=current->next;
                
            }
            
            count-=k;
            prevptr=current;
            
        }
        
        return dummy->next;        
    }
};