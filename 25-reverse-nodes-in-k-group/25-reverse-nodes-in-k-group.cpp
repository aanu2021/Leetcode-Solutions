class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head==NULL){
            return head;
        }
        
        ListNode*ptr=head;
        
        int cnt=0;
        
        while(ptr!=NULL && cnt<k){
            cnt++;
            ptr=ptr->next;
        }
        
        if(cnt<k){
            return head;
        }
        
        cnt=0;
        
        ListNode*prevptr=NULL;
        ListNode*current=head;
        ListNode*nextptr=NULL;
        
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