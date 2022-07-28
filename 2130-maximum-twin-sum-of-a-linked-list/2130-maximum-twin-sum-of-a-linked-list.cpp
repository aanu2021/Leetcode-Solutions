/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    
    int pairSum(ListNode* head) {
        
        if(head==NULL){
            return 0;
        }
        
        ListNode*slow=head;
        ListNode*fast=head;
        
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode*ptr=head;
        
        while(ptr->next!=slow){
            ptr=ptr->next;
        }
        
        ListNode*head2=ptr->next;
        ptr->next=NULL;
        
        head2=reverseList(head2);
        
        ListNode*ptr1=head;
        ListNode*ptr2=head2;
        
        int maxsum=0;
        
        while(ptr1!=NULL && ptr2!=NULL){
            
            int currsum=ptr1->val+ptr2->val;
            
            maxsum=max(maxsum,currsum);
            
            ptr1=ptr1->next;
            ptr2=ptr2->next;
            
        }
        
        return maxsum;
        
    }
};