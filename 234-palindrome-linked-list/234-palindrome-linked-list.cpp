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
        
        ListNode*newhead=reverseList(head->next);
        
        head->next->next=head;
        
        return newhead;
        
    }
    
    bool isPalindrome(ListNode* head) {
        
        if(!head|| head->next==NULL){
            return head;
        }
        
        
        ListNode*p=head;
        
        int n=0;
        
        while(p!=NULL){
            p=p->next;
            n++;
        }
        
        ListNode*slow=head;
        ListNode*fast=head;
        
        while(fast!=NULL && fast->next!=NULL){
            
            slow=slow->next;
            fast=fast->next->next;
            
        }
        
        
        ListNode*secondList=head;
        
        while(secondList && secondList->next!=slow){
            secondList=secondList->next;
        }
        
        secondList->next=NULL;
        
        if(n%2){
            slow=slow->next;
        }
        
        slow=reverseList(slow);
        
        while(head){
            
            if(head->val!=slow->val){
                return false;
            }
            
            head=head->next;
            slow=slow->next;
            
        }
        
        return true;
       
    }
};