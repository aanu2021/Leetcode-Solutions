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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(!head||!head->next){
            return head;
        }
        
        int len=1;
        
        ListNode*ptr=head;
        
        while(ptr && ptr->next){
            
            ptr=ptr->next;
            
            len++;
            
        }
        
        k=k%len;
        
        k=len-k;
        
        ptr->next=head;
        
        ListNode*temp=head;
        ListNode*follow=NULL;
        
        while(k--){
            
            follow=temp;
            temp=temp->next;
            
        }
        
        follow->next=NULL;
        
        return temp;
    }
};