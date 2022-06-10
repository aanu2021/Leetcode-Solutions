class Solution {
public:
    
    ListNode*reverse(ListNode*head,int k){
        
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        int cnt=0;
        
        ListNode*ptr=head;
        ListNode*prev=ptr;
        
        while(ptr!=NULL && cnt<k){
            cnt++;
            prev=ptr;
            ptr=ptr->next;
        }
        
        if(cnt<k){
            
            if(cnt%2!=0){
                
                return head;
                
            }
            
            else{
                
                ListNode*prevptr=NULL;
                ListNode*current=head;
                ListNode*nextptr=NULL;
                
                while(current!=NULL){
                    nextptr=current->next;
                    current->next=prevptr;
                    prevptr=current;
                    current=nextptr;
                }
                
                return prevptr;
                
            }
            
        }
        
        else{
            
            if(cnt%2!=0){
                
                prev->next=reverse(ptr,k+1);
                
                return head;
                
            }
            
            else{
                
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
                    head->next=reverse(nextptr,k+1);
                }
                
                return prevptr;
                
            }
            
        }
        
    }
    
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        return reverse(head,1);
        
    }
};