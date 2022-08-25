class Solution {
public:
    
    ListNode*getMid(ListNode*&head){
        
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        ListNode*slow=head;
        ListNode*fast=head;
        
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode*prevptr=head;
        
        while(prevptr!=NULL && prevptr->next!=slow){
            
            prevptr=prevptr->next;
            
        }
        
        prevptr->next=NULL;
        
        return slow;
        
    }
    
    ListNode* mergeTwoList(ListNode*&list1, ListNode*&list2) {
        
        ListNode dummyHead(0);
        ListNode* ptr = &dummyHead;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                ptr->next = list1;
                list1 = list1->next;
            } else {
                ptr->next = list2;
                list2 = list2->next;
            }
            ptr = ptr->next;
        }
        if(list1) ptr->next = list1;
        else ptr->next = list2;
        
        return dummyHead.next;
        
    }   
    
    ListNode* sortList(ListNode* head) {
        
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        ListNode*mid=getMid(head);
        
        ListNode*list1=sortList(head);
        ListNode*list2=sortList(mid);
        
        return mergeTwoList(list1,list2);
        
    }
};