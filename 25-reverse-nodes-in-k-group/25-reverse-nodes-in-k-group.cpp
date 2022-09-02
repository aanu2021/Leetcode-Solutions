class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
      
        if(!head || !head->next){
            return head;
        }
        
        ListNode*dummy=new ListNode(-1);
        
        dummy->next=head;
        
        ListNode*prevptr=dummy;
        ListNode*current=dummy;
        ListNode*nextptr=dummy;
        
        int count=0;
        
        while(current){
            
            current=current->next;
            
            count++;
            
        }
        
        while(nextptr){
            
            current=prevptr->next;
            nextptr=current->next;
            
            int loop=(count>k ? k : 1);
            
            for(int i=1;i<loop;++i){
                
                current->next=nextptr->next;
                nextptr->next=prevptr->next;
                prevptr->next=nextptr;
                nextptr=current->next;
                
            }
            
            prevptr=current;
            count-=k;
            
        }
        
        return dummy->next;
        
    }
};