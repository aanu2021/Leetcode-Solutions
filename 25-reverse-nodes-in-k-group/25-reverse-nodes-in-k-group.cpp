class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        int cnt=0;
        
        ListNode*ptr=head;
        
        while(ptr!=NULL && cnt<k){
            
            ptr=ptr->next;
            cnt++;
            
        }
        
        if(cnt<k){
            return head;
        }
        
        
        ListNode*prevptr=NULL;
        ListNode*current=head;
        ListNode*nextptr=NULL;
        
        
        cnt=0;
        
        while(current!=NULL && cnt<k){
            
            nextptr=current->next;
            current->next=prevptr;
            prevptr=current;
            current=nextptr;
            
            cnt++;
            
        }
        
        if(nextptr!=NULL){
            
            head->next=reverseKGroup(nextptr,k);
            
        }
        
        return prevptr;
        
    }
};