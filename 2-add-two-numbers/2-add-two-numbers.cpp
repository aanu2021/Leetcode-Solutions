class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        if(l1==NULL && l2==NULL){
            return NULL;
        }
        
        ListNode*dummy=new ListNode(-1);
        
        ListNode*temp=dummy;
        
        int carry=0,bit=0;
        
        while(l1 || l2){
            
            bit=carry;
            
            if(l1){
                
                bit+=l1->val;
                
                l1=l1->next;
                
            }
            
            if(l2){
                
                bit+=l2->val;
                
                l2=l2->next;
                
            }

            carry=bit/10;
            bit=bit%10;
            
            temp->next=new ListNode(bit);
            
            temp=temp->next;
            
        }
        
        if(carry){
            
            temp->next=new ListNode(carry);
            
        }
        
        return dummy->next;
        
    }
};