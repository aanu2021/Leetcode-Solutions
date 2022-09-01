class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int k) {
        
        if(!head){
            return NULL;
        }
        
        int n=0;
        
        ListNode*ptr=head;
        
        while(ptr){
            
            ptr=ptr->next;
            
            ++n;
            
        }
        
        k=n-k;
        
        if(k==0){
            
            head=head->next;
            
            return head;
            
        }
        
        k--;
        
        ListNode*temp=head;
        
        while(k>0){
            
            temp=temp->next;
            
            k--;
            
        }
        
        temp->next=temp->next->next;
        
        return head;
        
    }
};