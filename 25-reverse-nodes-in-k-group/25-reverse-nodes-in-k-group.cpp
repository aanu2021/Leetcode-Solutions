class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head==NULL){
            return head;
        }
        
        ListNode*nexthead=head;
        
        int len=0;
        
        while(nexthead!=NULL && len<k){
            nexthead=nexthead->next;
            len++;
        }
        
        if(len<k){
            return head;
        }
        
        int count=0;
        
        ListNode*prevptr=NULL;
        ListNode*current=head;
        ListNode*nextptr=NULL;
        
        while(current!=NULL && count<k){
            
            nextptr=current->next;
            current->next=prevptr;
            prevptr=current;
            current=nextptr;
            
            count++;
            
        }
        
        if(nextptr!=NULL){
            head->next=reverseKGroup(nextptr,k);
        }
        
        return prevptr;
        
    }
};