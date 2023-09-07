class Solution {
public:
    
    ListNode*reverseList(ListNode*&head){
        
        if(head==NULL || head->next==NULL){
            return head;
        }
        
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
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        left--;
        right--;
        
        if(left==right){
            return head;
        }
        
        ListNode*rightptr=head;
        
        while(right--){
            
            rightptr=rightptr->next;
            
        }
        
        
        ListNode*q=rightptr->next;
        
        rightptr->next=NULL;
        
        
        if(left==0){
            
            ListNode*startpart=head;
            
              startpart=reverseList(startpart);
            
            ListNode*ptr=startpart;
            
            while(ptr!=NULL && ptr->next!=NULL){
                
                ptr=ptr->next;
                
            }
            
            
            ptr->next=q;
            
            return startpart;
            
        }
        
        else{
            
            ListNode*ptr=head;
            
            left--;
            
            while(left--){
                
                ptr=ptr->next;
                
            }
            
            ListNode*midpart=ptr->next;
            ptr->next=NULL;
            
            midpart=reverseList(midpart);
            
            ptr->next=midpart;
            
            ListNode*tempo=ptr;
            
            while(tempo!=NULL && tempo->next!=NULL){
                tempo=tempo->next;
            }
            
            tempo->next=q;
            
            return head;
            
        }
        
    }
};