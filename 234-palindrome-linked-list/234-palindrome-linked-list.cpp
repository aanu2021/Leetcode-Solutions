class Solution {
public:
    
    ListNode*reverseList(ListNode*&head){
        
        if(!head||!head->next){
            return head;
        }
        
        ListNode*prevptr=NULL;
        ListNode*current=head;
        ListNode*nextptr=NULL;
        
        while(current){
            
            nextptr=current->next;
            current->next=prevptr;
            prevptr=current;
            current=nextptr;
            
        }
        
        return prevptr;
        
    }
    
    bool isPalindrome(ListNode* head) {
        
        
        if(!head){
            return false;
        }
        
        if(!head->next){
            return true;
        }
        
        ListNode*slow=head;
        
        ListNode*fast=head;
        
        ListNode*follow_slow=NULL;
        
        
        while(fast!=NULL && fast->next!=NULL){
            
            follow_slow=slow;
            slow=slow->next;
            fast=fast->next->next;
            
        }
        
        follow_slow->next=NULL;
        
        slow=reverseList(slow);
        
        fast=head;
        
        while(slow && fast){
            
            if(slow->val!=fast->val){
                return false;
            }
            
            slow=slow->next;
            fast=fast->next;
            
        }
        
        return true;
        
    }
};