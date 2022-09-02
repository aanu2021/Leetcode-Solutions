class Solution {
public:
    
    ListNode*getMid(ListNode*&head){
        
        if(!head || !head->next){
            return head;
        }
        
        ListNode*slow=head;
        ListNode*fast=head;
        ListNode*follow_slow=head;
        
        while(fast && fast->next){
            
            follow_slow=slow;
            slow=slow->next;
            fast=fast->next->next;
            
        }
        
        follow_slow->next=NULL;
        
        return slow;
        
    }
    
    ListNode*merge(ListNode*&headA,ListNode*&headB){
        
        if(headA==NULL){
            return headB;
        }
        
        if(headB==NULL){
            return headA;
        }
        
        ListNode*dummy=new ListNode(-1);
        
        ListNode*temp=dummy;
        
        ListNode*ptrA=headA;
        ListNode*ptrB=headB;
        
        while(ptrA && ptrB){
            
            if(ptrA->val<=ptrB->val){
                temp->next=ptrA;
                ptrA=ptrA->next;
            }
            
            else{
                temp->next=ptrB;
                ptrB=ptrB->next;
            }
            
            temp=temp->next;
            
        }
        
        if(ptrA){
            temp->next=ptrA;
        }
        
        if(ptrB){
            temp->next=ptrB;
        }
        
        return dummy->next;
        
    }
    
    ListNode* sortList(ListNode* head) {
        
        if(!head || !head->next){
            return head;
        }
        
        ListNode*mid=getMid(head);
        
        head=sortList(head);
        mid=sortList(mid);
        
        return merge(head,mid);
        
    }
};